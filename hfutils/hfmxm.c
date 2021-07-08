#include <mxm/api/mxm_version.h>
#include <mxm/api/mxm_api.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/mman.h>

//#include <sys/types.h>
//#include <ifaddrs.h>

#include "hflog.h"
#include "hfmxm.h"
#include "hfsocket.h"

/*
// Design and Evaluation of Low-Latency Communication Middleware on High Performance Computing S...
// http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.897.9687&rep=rep1&type=pdf
// http://gac.udc.es/~juan/papers/ccpe2015-2.pdf
7.1. Connection setup

  The MXM library is initialized using the mxm_init() method. Next, the connection setup must
  be carried out in order to enable communications. In MXM, messages are exchanged between
  endpoints, which are software representations of the Mellanox IB/RoCE adapters. At present, MXM
  does not include any communication manager to ease the connection setup. Thereby, in order to
  establish the initial connections between endpoints, the mxmdev device has to rely on an outof-band
  mechanism to distribute the endpoint addresses between all the processes. Hence, each
  process first creates and sets up an endpoint using the mxm_ep_create() function. After initializing
  endpoints, a Matched Queue (MQ) interface is created via mxm_mq_create(). Basically, an MQ is
  a specific context of sending and receiving messages which maintains ordering between requests.
  It exposes a simplified messaging interface that resembles an MPI communicator, but supporting
  only basic point-to-point communications. Next, the endpoint addresses are exchanged between all
  processes relying on TCP sockets, selected as the ubiquitous out-of-band mechanism. Finally, the
  mxm_ep_connect() function must be used to establish the endpoint connections with the information
  gathered from the TCP communication phase, thus enabling data transfers.

7.2. Basic communication operation

  The MXM library provides a C-based API which includes a small set of point-to-point
  communication primitives similar to those needed to implement the xxdev interface (see
  Section 4). Thus, mxmdev acts as a thin wrapper over the MXM library, so that the implementation
  of a method in xxdev generally delegates directly in a native method that performs the requested
  operation in MXM through JNI. Therefore, mxmdev deals with the marshaling and communication
  of Java objects, the JNI transfers and the handling of MXM parameters, by implementing a series
  of three steps: (1) get the associated parameters of the Java objects that are required for calling
  the corresponding function in MXM; (2) call the MXM function; and (3) save the results in the
  appropriate attributes of the Java objects involved in the communication. As a general rule, the
  caching of object references has been extensively used in the implementation of the JNI layer, thus
  minimizing the overhead associated with the JNI calls.
  Every message operation in MXM, either sending or receiving, starts with a non-blocking
  communication request (e.g., mxm_req_send()). This request is queued by MXM, returning the
  control to mxmdev. Next, the mxmdev device is responsible for checking the successful completion
  of the communication operation using one of the supported mechanisms in MXM (e.g., mxm wait(),
  mxm_req_test()). The MXM tag matching mechanism at the receiving side is based on a 32-bit
  value (mxm_tag_t), which must be specified by both communication peers in order to deliver
  incoming messages to the right receive requests. The tag value specified by the programmer at
  the corresponding MPJ-level method (e.g., MPI.COMM WORLD.Send()) is used for this purpose.
  Hence, incoming MXM messages are stored according to their MPJ tags to pre-posted receive
  buffers. In this case note that, unlike the ugnidev and ibvdev devices, the underlying
  communication protocols are implemented internally by MXM. Currently, MXM includes both
  intra-node (via shared memory) and inter-node communication protocols, which allows MPJ
  applications to take full advantage of hybrid shared/distributed memory architectures, widely
  extended nowadays

*/

#define MXM_RS_MAX_TRANSFER 65536
#define MXM_RXQE_AMOUNT      1024
#define MXM_TXQE_AMOUNT      1024

// we need a ring of outstanding requests that we can post to the MXM driver
typedef struct _mxm_recv_elem_t mxm_recv_elem_t; // gasnet_mxm_recv_req
struct _mxm_recv_elem_t {
    mxm_recv_elem_t *next;
    mxm_recv_req_t mxm_rreq;

    // we require this for the receive.
    // Since it could happen that the request was just partically consumed!
    size_t len_leftover;
};

typedef struct _mxm_send_elem_t mxm_send_elem_t;
struct _mxm_send_elem_t {
  mxm_send_elem_t *next;
  mxm_send_req_t mxm_sreq;
};

typedef struct _mxm_module_t mxm_module_t; // gasnet_mxm_module
struct _mxm_module_t {
    mxm_h              mxm_context;
    mxm_ep_h           mxm_ep;
    mxm_mq_h           mxm_mq;
    mxm_conn_h         mxm_conn[1]; // FixME: on the daemon, this carries multiple! -> see WARNING below

    mxm_recv_elem_t     *reqs_head;
    mxm_recv_elem_t     *reqs_pool;
    
    mxm_send_elem_t     *snd_reqs_head;
    mxm_send_elem_t     *tmp_snd_reqs_head; // required for blocking sends
    mxm_send_elem_t     *snd_reqs_pool;

    mxm_module_t *next;
};

// let's borrow the GASNet method
// this makes the receive 'slots' available (again)
static inline mxm_error_t hfmxm_post_recv( mxm_mq_h mxm_mq, mxm_recv_req_t * p_req )
{
    // ToDo: use the tags for cudaMemcpy()!
    mxm_req_base_t * p_base = &p_req->base;
    p_req->tag = 0;
    p_req->tag_mask = 0; /* match any tag */
    p_base->completed_cb = NULL;
    p_base->conn = NULL; /* receive from any source */
    p_base->mq = mxm_mq;
    p_base->state = MXM_REQ_NEW;
    p_base->data_type = MXM_REQ_DATA_BUFFER;
    p_base->data.buffer.length = MXM_RS_MAX_TRANSFER; // reset just to make sure...
    return mxm_req_recv(p_req);
}

hferr_t __hfmxm_common_connect( mxm_context_opts_t *mxm_opts,
                                mxm_ep_opts_t *mxm_ep_opts,
                                mxm_module_t* module )
{
    /*
     * Initialize MXM
     *
     * There are three modes:
     *   - MXM_ASYNC_MODE_NONE
     *   - MXM_ASYNC_MODE_SIGNAL
     *   - MXM_ASYNC_MODE_THREAD
     * GASnet works with THREAD -> let's do the same!
     */
    mxm_opts->async_mode = MXM_ASYNC_MODE_THREAD;
    mxm_error_t err = mxm_init(mxm_opts, &module->mxm_context);
    if( err != MXM_OK ) {
        if( err == MXM_ERR_NO_DEVICE )
            hferr("[hfmxm] No supported device found, disqualifying MXM\n");
        else
            hferr("[hfmxm] MXM init failed (%s)\n", mxm_error_string(err));
        return HFERR;
    }

    /*
     * Setup the endpoint options and local addresses to bind to
     */
    err = mxm_ep_create(module->mxm_context, mxm_ep_opts, &module->mxm_ep);
    if( err != MXM_OK ) {
        hferr("[hfmxm] Unable to create MXM endpoint (%s)\n",
                  mxm_error_string(err));
        return HFERR;
    }
    hfinf("[hfmxm] MXM ep: %p (module: %p)\n", module->mxm_ep, module );

    /* TODO: using 0xabcd as context ID - do we have only one communicator? */
    err = mxm_mq_create( module->mxm_context, 0xabcd, &module->mxm_mq );
    if( err != MXM_OK ) {
        hferr("[hfmxm] MXM mq create failed (%s)", mxm_error_string(err));
        return HFERR;
    }

    // now we need some mechanism that posts a tremendous amount of post_recv's
    // we'll will use a ring of recv's (same as GASNet)
    module->reqs_pool = (typeof(module->reqs_pool)) malloc ( MXM_RXQE_AMOUNT * sizeof(*module->reqs_pool) );
    unsigned i;
    for( i = 0; i < MXM_RXQE_AMOUNT; ++i ) {
        mxm_recv_elem_t *req = &module->reqs_pool[ i ];
        req->next = &module->reqs_pool[ (i + 1) % MXM_RXQE_AMOUNT ];
        req->len_leftover = 0; // init to 0 as the request is 'consumed'
        
        // require for each recv a buffer ... (gasnetc_alloc_recv_req)
        
        size_t size = MXM_RS_MAX_TRANSFER; // has to be page size!
        char *buf = NULL;
        err = mxm_mem_map( module->mxm_context, (void**)&buf, &size, 0, NULL, 0); // allocates for us!
        //char* buf = mmap( NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_NORESERVE, -1, 0 );
        if( buf == NULL
            || err != MXM_OK
            || size != MXM_RS_MAX_TRANSFER ) {
            hferr("[hfmxm] couldn't allocate network buffers!\n");
            return HFERR;
        }
        
        // this can be used to re-wire the send
        req->mxm_rreq.base.data.buffer.ptr = buf;
        req->mxm_rreq.base.data.buffer.length = MXM_RS_MAX_TRANSFER;
        
        // last aspect of this entire setup function!!
        err = hfmxm_post_recv( module->mxm_mq, &req->mxm_rreq );
        if( err != MXM_OK ) {
            hferr("[hfmxm] post recv. failed!\n");
            return HFERR;
        }
    }
    module->reqs_head = &module->reqs_pool[ 0 ];

    module->snd_reqs_pool = (typeof(module->snd_reqs_pool)) malloc ( MXM_TXQE_AMOUNT * sizeof(*module->snd_reqs_pool) );
    for( i = 0; i < MXM_TXQE_AMOUNT; ++i ) {
      mxm_send_elem_t *req = &module->snd_reqs_pool[ i ];
      req->mxm_sreq.base.state = MXM_REQ_COMPLETED;
      req->next = &module->snd_reqs_pool[ (i + 1) % MXM_TXQE_AMOUNT ];
    }
    module->snd_reqs_head = &module->snd_reqs_pool[ 0 ];
    module->tmp_snd_reqs_head = &module->snd_reqs_pool[ 0 ];

    return HFOK;
}

//#define HF_MXM_MULTI_LINK 1
hferr_t hfmxm_common_connect( hfmxm_t* conn )
{
    mxm_context_opts_t *env_mxm_opts;
    mxm_ep_opts_t      *mxm_ep_opts;

    mxm_error_t err = mxm_config_read_opts(&env_mxm_opts, &mxm_ep_opts,
                                           "HFCUDA", NULL, 0);
    if( err != MXM_OK ) {
        hferr("[hfmxm] Failed to parse MXM configuration\n");
        return HFERR;
    }

    //mxm_ib_port_spec_t spec[4];
    //spec[0].port_num = env_mxm_opts->ib.ports.specs[0].port_num;
    //spec[0].device_name = env_mxm_opts->ib.ports.specs[0].device_name;
    //spec[1].port_num = env_mxm_opts->ib.ports.specs[0].port_num + 1;
    //spec[1].device_name = env_mxm_opts->ib.ports.specs[0].device_name;
    //spec[2].port_num = env_mxm_opts->ib.ports.specs[0].port_num;
    //spec[2].device_name = env_mxm_opts->ib.ports.specs[0].device_name + 1;
    //spec[3].port_num = env_mxm_opts->ib.ports.specs[0].port_num + 1;
    //spec[3].device_name = env_mxm_opts->ib.ports.specs[0].device_name + 1;
    
    //env_mxm_opts->ib.ports.count = 2; //4;
    //env_mxm_opts->ib.ports.specs = spec;

    // ok, the main MXM API refuses us to get multiple IB links involved with ONE processs
    // but ... we can hack it :-)

    // MXM_IB_PORTS=mlx5_0:1,mlx5_1:1 

    // The MXM API retrieves from the environment the amount of IBs that the user wants to run on.
    // Still, the API schedules the processes among the IB links, not allowing to run one process
    // on multiple links. But the API is aware of how many IBs the user wants, hence leverage that:
#ifdef HF_MXM_MULTI_LINK
    unsigned ib_count = env_mxm_opts->ib.ports.count;
#else
    unsigned ib_count = 1;
#endif

    mxm_module_t* module = (typeof(module)) malloc (sizeof(*module) * ib_count);
    conn->ib_modules = module;
    conn->ib_modulec = ib_count;
    // don't initialize the module->next pointer yet -> will be done in the accept protocol

    mxm_context_opts_t *mxm_opts = (typeof(mxm_opts)) malloc (sizeof(*mxm_opts) * ib_count);
    unsigned i;
    for( i = 0; i < ib_count; ++i ) {
      memcpy( &mxm_opts[i], env_mxm_opts, sizeof(mxm_opts[i]) );

      hfinf("[hfmxm] init ib link %p:%d\n",
             env_mxm_opts->ib.ports.specs[i].device_name,
             env_mxm_opts->ib.ports.specs[i].port_num );

#ifdef HF_MXM_MULTI_LINK
      mxm_opts->ib.ports.count = 1;
      mxm_opts->ib.ports.specs[0].port_num = env_mxm_opts->ib.ports.specs[i].port_num;
      mxm_opts->ib.ports.specs[0].device_name = env_mxm_opts->ib.ports.specs[i].device_name;
#endif

      hferr_t herr = __hfmxm_common_connect( &mxm_opts[i], mxm_ep_opts /* for now config all ep's the same way */, &module[i] );
      if( herr != HFOK )
          return herr;
    }

    mxm_config_free_ep_opts(mxm_ep_opts);

    return HFOK;
}


typedef struct _hfmxm_ep_t hfmxm_ep_t;
struct __attribute__((packed)) _hfmxm_ep_t {
    size_t addr_len;
    char addr[];
};

hfmxm_ep_t* hfmxm_ep_info_exchange( hfsocket_t *sock_conn, hfmxm_ep_t *ep )
{
    hfcheck(hfsocket_send( sock_conn, ep, sizeof(*ep) + ep->addr_len));

    // as struct len is dynamic we try to get the most of it here ...
    hfmxm_ep_t *rmt_ep = (typeof(rmt_ep)) malloc (sizeof(*rmt_ep));
    hfcheck(hfsocket_recv( sock_conn, rmt_ep, sizeof(*rmt_ep) ));
    
    // now we know the dynamic part ... 
    rmt_ep = (typeof(rmt_ep)) realloc ( rmt_ep, sizeof(*rmt_ep) + rmt_ep->addr_len );
    hfcheck(hfsocket_recv( sock_conn, rmt_ep->addr, rmt_ep->addr_len ));
    return rmt_ep;
}

hferr_t hfmxm_accept_protocol( hfsocket_t *sock_conn, hfmxm_t *conn )
{
    /*
     * First: query the other for how many interfaces are given!
     */
    unsigned rmt_modulec;
    hfcheck(hfsocket_send( sock_conn, &conn->ib_modulec, sizeof(conn->ib_modulec)));
    hfcheck(hfsocket_recv( sock_conn, &rmt_modulec, sizeof(rmt_modulec) ));
    if( ! rmt_modulec )
        return HFERR;

    unsigned actual_modulec;
    if( rmt_modulec != conn->ib_modulec ) {
        // let's handle the lower case ... provide a warning if not the same!
        actual_modulec = rmt_modulec > conn->ib_modulec ? conn->ib_modulec : rmt_modulec;
        hfwar("[hfmxm] unbalanced ib ports given! self: %d vs. rmt: %d. Will choose lower one!\n", 
                conn->ib_modulec, rmt_modulec);
    }
    else
        actual_modulec = conn->ib_modulec;
    conn->act_ib_modulec = actual_modulec;

    mxm_module_t* ib_modules = (mxm_module_t*) conn->ib_modules;

    // set first link:
    conn->cur_ib_module = &ib_modules[0];

    unsigned i;
    for( i = 0; i < actual_modulec; ++i ) {
        /*
         * set the pointer chain of modules
         */
        ib_modules[i].next = &ib_modules[ (i + 1) % actual_modulec ];        
        
        /*
         * Get address for each PTL on this endpoint and exchange it
         */
        hfmxm_ep_t *my_ep = (typeof(my_ep)) malloc (sizeof(*my_ep));
        my_ep->addr_len = 0; // needs to be set -> mxm_ep_get_address() will then tell us the size

        /*
         * Get address of our PTL meaning this endpoint and exchange it
         */
        mxm_error_t err = mxm_ep_get_address( ib_modules[i].mxm_ep, my_ep->addr, &my_ep->addr_len);
        switch( err ) {
        case MXM_ERR_BUFFER_TOO_SMALL:
            my_ep = (typeof(my_ep)) realloc ( my_ep, sizeof(*my_ep) + my_ep->addr_len + 100 );

            // retry
            err = mxm_ep_get_address( ib_modules[i].mxm_ep, my_ep->addr, &my_ep->addr_len );
            if( err != MXM_OK ) {
                hferr("[hfmxm] Unable to extract endpoint address (%s)\n",
                                          mxm_error_string(err));
                return HFERR;
            }
            break;
        case MXM_OK:
            break;
        default:
            hferr("[hfmxm] Unable to extract endpoint address (%s)\n",
                                      mxm_error_string(err));
            return HFERR;
        }
        hfinf("[hfmxm] Obtained MXM address: %.*s\n", (int)my_ep->addr_len, my_ep->addr );

        /*
         * MXM fills in addresses for MXM_PTL_SELF and MXM_PTL_RDMA.
         * We don't care about the rest - tell valgrind to ignore it.
         */
        /*VALGRIND_MAKE_MEM_DEFINED(&local_ep, sizeof (local_ep));*/

        /* 
           Don't use hfcomm_recv() and hfcomm_send() directly!!! These will use / point to the MXM.
           But here we really require the socket!
         */
        hfmxm_ep_t *rmt_ep = hfmxm_ep_info_exchange( sock_conn, my_ep );
        free(my_ep);

        /*
         * NOTE: we do NOT copy the data from the remote_eps buffer,
         * but use it by pointer.
         * ALSO NOTE: for the same reason, we do NOT free remote_eps
         * array - its content is used by gasnet_mxm_module.mxm_conn_reqs
         */
        err = mxm_ep_connect(ib_modules[i].mxm_ep,
                             rmt_ep->addr, // DO NOT DEALLOCATE!!!!
                             &ib_modules[i].mxm_conn[0]);
        if( err != MXM_OK ) {
            hferr("[hfmxm] MXM returned connect error: %s\n", mxm_error_string(err));
            return HFERR;
        }
        hfinf("[hfmxm] exchanged MXM addr.! partner: %.*s, status: %s\n",
                (int)rmt_ep->addr_len, rmt_ep->addr, mxm_error_string(err) );


        /* Let's don't have a penalty for the first message ... */
        err = mxm_ep_wireup( ib_modules[i].mxm_ep );
        if( err != MXM_OK ) {
            hferr("[hfmxm] MXM returned connect error: %s\n", mxm_error_string(err));
            return HFERR;
        }
    }

    return HFOK;
}


hferr_t hfmxm_client_connect(hfmxm_t* conn, char* host, int port)
{
    hfdeb("[hfmxm] %s() [CALL] connecting to: host=%s port=%d\n",
            __FUNCTION__, host, port);

    hfcheck(hfmxm_common_connect( conn ));

    hfsocket_t hfconn_boot;
    hfcheck(hfsocket_client_connect( &hfconn_boot, host, port ));

    hfdeb("[hfmxm] running connect protocol! (conn: %p)\n", conn );
    hfcheck(hfmxm_accept_protocol( &hfconn_boot, conn ));

    // ToDo: clear hfconn_boot socket!

    hfdeb("[hfmxm] %s() [DONE]\n", __FUNCTION__);

    return HFOK;
}

//
//  Prepare server to accept incoming connections.
//  ----------------------------------------------------------------------------
//


hferr_t hfmxm_server_prepare(hfmxm_t* conn, char* host, int port)
{
    hfdeb("[hfmxm] %s() [CALL] preparing: host=%s port=%d\n",
            __FUNCTION__, host, port);

    hfcheck(hfmxm_common_connect( conn ));

#if 0
    struct ifaddrs *addrs,*tmp;
    getifaddrs(&addrs);
    tmp = addrs;

    while (tmp)
    {
        if (tmp->ifa_addr 
            && tmp->ifa_addr->sa_family == AF_PACKET)
            printf("%s\n", tmp->ifa_name);

        tmp = tmp->ifa_next;
    }

    freeifaddrs(addrs);
#endif

    /*
     * Sadly MXM requires a boot-strapping with some other conduit.
     * Let's use hfsocket :-)
     *
     * Idea: - daemon creates a 'login'-thread using / handling a socket
     *       - any client / requester connects first to the socket and exchanges his mxm addr.
     *         while at the same time retrieving the daemons mxm addr.
     *       - both, client and daemon start connecting with the mxm connection.
     *       - both drop the previous socket connection
     */
    hfcheck(hfsocket_server_prepare( &conn->sock_conn_main, host, port ));

    hfdeb("[hfmxm] %s() [DONE]\n", __FUNCTION__);

    return HFOK;
}

//
//  Accept incoming connection.
//  ----------------------------------------------------------------------------
//

hferr_t hfmxm_server_accept(hfmxm_t* server, hfmxm_t* conn)
{
    hfsocket_t hfconn_boot;
    hfcheck(hfsocket_server_accept( &server->sock_conn_main, &hfconn_boot ));
    hfinf("[hfmxm] %s() socket connection accepted\n", __FUNCTION__);
    
    /* WARNING!
       The mxm connections (mxm_conn) are unique in the mxm_module.
       As the daemon spawns a thread and the thread obtains a new 'conn' connection,
       copy the servers module and let hfmxm_accept_protocol overwrite the module.
       In the client it's even less a problem
    */
    conn->ib_modules = (mxm_module_t*) malloc (sizeof(mxm_module_t) * server->ib_modulec); // conn->module is void*!
    memcpy( conn->ib_modules, server->ib_modules, sizeof(mxm_module_t) * server->ib_modulec);
    conn->ib_modulec = server->ib_modulec;
    hfcheck(hfmxm_accept_protocol( &hfconn_boot, conn ));
    // ToDo: clear hfconn_boot socket!

    hfdeb("[hfmxm] %s() [DONE]\n", __FUNCTION__);

    return HFOK;
}


static inline void hfmxm_drain_reqs( mxm_module_t *module,
                                     mxm_req_base_t *req )
{
  // check first if the next one is done!
  while( ! mxm_req_test( req ) ) {
      // progress if the hardware hasn't done it already!
      mxm_error_t err = mxm_progress( module->mxm_context );
      if( err != MXM_OK ) {
          hferr("[hfmxm] %s(): mxm_progress() error %d: %s\n", 
                  __FUNCTION__, err, mxm_error_string(err));
      }
  }
}




/*
 * From a sender's point of view, the request and reply functions block
 * until the message is sent. A message is defined to be sent once it is
 * safe for the caller to reuse the memory containing the message (except
 * for gasnet_RequestLongAsyncM() case).
 *
 * In implementations which copy or buffer messages for transmission,
 * the definition still holds: message sent means the layer has copied
 * the message and promises to deliver the copy with its "best effort",
 * and the original message storage may be reused.
 *
 * By best effort, the message layer promises it will take care of all
 * the details necessary to transmit the message. These details include
 * any retransmission attempts and buffering issues on unreliable networks.
 *
 * However, in either case, sent does not imply received. Once control
 * returns from a request or reply function, clients cannot assume that
 * the message has been received and handled at the destination.
 * The message layer only guarantees that if a request or reply is sent,
 * and, if the receiver occasionally polls for arriving messages, then
 * the message will eventually be received and handled.
 *
 * From a receiver's point of view, a message is defined to be received
 * only once its handler function is invoked.
 */
/*
 * FLAG_BLOCKING tells MXM to free user's buffer ASAP.
 * This does NOT mean that the call will be blocked,
 * but it will affect MXM decision w.r.t. how to send
 * the message. E.g. MXM will not use ZCOPY.
 */
#define hfmxm_packet_set_desc( DESCR, IMM_DATA, TAG ) \
({ \
    typeof(DESCR) __descr = (DESCR); \
    __descr->opcode = MXM_REQ_OP_SEND; \
    __descr->base.state = MXM_REQ_NEW; \
    __descr->base.completed_cb = NULL; \
    __descr->base.context = NULL; \
    __descr->base.data.buffer.memh = NULL; \
    __descr->base.data_type = MXM_REQ_DATA_BUFFER; \
    __descr->flags = MXM_REQ_SEND_FLAG_BLOCKING; \
    __descr->op.send.imm_data = (IMM_DATA); \
    __descr->op.send.tag = (TAG); \
    __descr; \
})

hferr_t hfmxm_send(hfmxm_t* conn, void* ptr, size_t size)
{
    hfdeb("[hfmxm] %s() [CALL] ptr=0x%016lx size=%lu\n",
            __FUNCTION__, ptr, size);


    /*
     * ToDo: either use imm_data and tag for something related to internals or use it for 8 Byte immediate sends!
     */
    mxm_imm_t imm_data = 0; /* (mxm_imm_t) GASNETC_MSG_METADATA(
                             handler_id, numargs, category,
                             is_request, is_sync_request,
                             SYSTEM_MSG_NA, msg_num); */

    mxm_tag_t tag = (mxm_tag_t) 0; // GASNet uses gasnet id


    mxm_module_t *module = (mxm_module_t*) conn->cur_ib_module;
    size_t tsize = size;
    char* cptr = ptr;
    while( tsize ) {
      
        size_t csize;
        if( tsize >= MXM_RS_MAX_TRANSFER )
            csize = MXM_RS_MAX_TRANSFER;
        else
            csize = tsize;
        tsize -= csize;

        mxm_send_elem_t *mxm_cur_sreq = module->snd_reqs_head;
        hfmxm_packet_set_desc( &mxm_cur_sreq->mxm_sreq, imm_data, tag );
        mxm_cur_sreq->mxm_sreq.base.conn = module->mxm_conn[0]; // ToDo
        mxm_cur_sreq->mxm_sreq.base.mq = module->mxm_mq;
        mxm_cur_sreq->mxm_sreq.base.data.buffer.ptr = cptr;
        mxm_cur_sreq->mxm_sreq.base.data.buffer.length = csize;

        mxm_error_t err = mxm_req_send( &mxm_cur_sreq->mxm_sreq );
        if( err != MXM_OK ) {
            hferr("[hfmxm] %s(): mxm_req_send() error %d: %s\n", 
                    __FUNCTION__, err, mxm_error_string(err));
            return HFERR;
        }

        // we need to set head pointer here immediately as we move on with the module!
        // next blocking loop uses bl_next pointer!
        module->snd_reqs_head = mxm_cur_sreq->next;
        module = module->next;

        // check if the next one is done!
        hfmxm_drain_reqs( module, &module->snd_reqs_head->mxm_sreq.base );

        cptr += csize;
    };

    module = (mxm_module_t*) conn->cur_ib_module; // get original module
    tsize = size;
    while( tsize ) {
      
        size_t csize;
        if( tsize > MXM_RS_MAX_TRANSFER )
            csize = MXM_RS_MAX_TRANSFER;
        else
            csize = tsize;
        tsize -= csize;

        // as this is a blocking send, issue test!
        mxm_send_elem_t *mxm_cur_sreq = module->tmp_snd_reqs_head;
        hfmxm_drain_reqs( module, &mxm_cur_sreq->mxm_sreq.base );

        module->tmp_snd_reqs_head = mxm_cur_sreq->next;
        module = module->next;
    }
    conn->cur_ib_module = module; // update module here! Not before!

    hfdeb("[hfmxm] %s() [DONE]\n", __FUNCTION__);

    return HFOK;
}


static inline bool hfmxm_handle_one_buffer( mxm_module_t *module,
                                            void** dst_ptr, size_t* dst_size,
                                            size_t *len_leftover,
                                            mxm_recv_req_t *req )
{
    // handle request!
    //mxm_imm_t imm_data = r->completion.sender_imm;
    //mxm_tag_t tag = r->completion.sender_tag;
    //(void)imm_data;
    //(void)tag;

    size_t req_len = req->completion.actual_len;
    char* req_ptr = req->base.data.buffer.ptr + (req_len - (*len_leftover));
    if( req_len <= (*dst_size) ) {
        memcpy( (*dst_ptr), req_ptr, req_len );
        (*dst_size) -= req_len;
        (*(char**)dst_ptr) += req_len;            

        *len_leftover = 0;
        mxm_error_t err = hfmxm_post_recv( module->mxm_mq, req );
        if( err != MXM_OK ) {
            hferr("[hfmxm] post recv. failed!\n");
            exit(-1);
        }

        return true; // buffer consumed -> move on!
    }
    else {
        // more available then required
        memcpy( (*dst_ptr), req_ptr, (*dst_size) );

        *len_leftover = req_len - (*dst_size);

        (*dst_size) = 0;
        return false; // buffer not fully consumed -> next round needs further work!
    }
}


hferr_t hfmxm_recv(hfmxm_t* conn, void* ptr, size_t size)
{
    hfdeb("[hfmxm] %s() [CALL] ptr=0x%016lx size=%lu\n",
            __FUNCTION__, ptr, size);

    mxm_module_t *module = (mxm_module_t*) conn->cur_ib_module;

    // if the last one is a leftover
    mxm_recv_elem_t *req_head = module->reqs_head;
    if( req_head->len_leftover ) {
        // only move further if fully consumed
        if( hfmxm_handle_one_buffer( module, &ptr, &size, &req_head->len_leftover, &req_head->mxm_rreq ) ) {
            // first iterate the current module further
            module->reqs_head = module->reqs_head->next;
            
            // then iterate the module for the link further (and set it back to structure)
            conn->cur_ib_module = module = module->next;
            
            // and obtain new head
            req_head = module->reqs_head;
        }
    }
    
    while( size ) {
        mxm_recv_req_t *r = &req_head->mxm_rreq; 
        hfmxm_drain_reqs( module, &r->base );        
        //mxm_req_wait(&r->base); // ToDo

        req_head->len_leftover = r->completion.actual_len; // set the entire size here.
        if( hfmxm_handle_one_buffer( module, &ptr, &size, &req_head->len_leftover, r ) ) {
            // first iterate the current module further
            module->reqs_head = module->reqs_head->next;
            
            // then iterate the module for the link further (and set back to structure)
            conn->cur_ib_module = module = module->next;
            
            // and obtain new head
            req_head = module->reqs_head;
        }
    }

    hfdeb("[hfmxm] %s() [DONE]\n", __FUNCTION__);

    return HFOK;
}

hferr_t hfmxm_client_free(hfmxm_t* conn)
{
    return HFOK;
}

hferr_t hfmxm_server_free(hfmxm_t* server)
{
    return HFOK;
}


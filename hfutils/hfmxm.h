#ifndef _HFMXM_H_
#define _HFMXM_H_

#include "hfsocket.h"

typedef struct _hfmxm_t hfmxm_t;
struct _hfmxm_t {
    // only used for the accept
    hfsocket_t sock_conn_main;

    // required on the client / daemon side
    unsigned ib_modulec;
    unsigned act_ib_modulec;
    void* ib_modules;
    
    void* cur_ib_module;
};

hferr_t hfmxm_client_connect (hfmxm_t* client, char* host, int port);
hferr_t hfmxm_server_prepare (hfmxm_t* server, char* host, int port);
hferr_t hfmxm_server_accept  (hfmxm_t* server, hfmxm_t* conn);

hferr_t hfmxm_send (hfmxm_t* conn, void* ptr, size_t size);
hferr_t hfmxm_recv (hfmxm_t* conn, void* ptr, size_t size);

hferr_t hfmxm_client_free (hfmxm_t* client);
hferr_t hfmxm_server_free (hfmxm_t* server);

#endif /* #ifndef _HFMXM_H_ */

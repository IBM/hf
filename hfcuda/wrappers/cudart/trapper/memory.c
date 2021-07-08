// -----------------------------------------------------------------------------

cudaError_t
    cudaFree(
        void* devPtr)
{
    hfinf("[trapper] cudaFree() [CALL] "
            "devPtr=0x%016lx\n",
            devPtr);

    cudaError_t cudaError = cudaSuccess;
    if( devPtr != NULL ) {
        struct __attribute__((packed)) {
            hf_msgdescr_t header;
            struct __attribute__((packed)) {
                void* devPtr;
            } data;
        } t2d_msg;
        HF_MSGDESCR_SET( &t2d_msg.header,
                         HFCUDA_CUDART_cudaFree );
        t2d_msg.data.devPtr = devPtr;

        hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));

        hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
        
        // returns: cudaSuccess, cudaErrorInvalidDevicePointer, cudaErrorInitializationError
        if( cudaError == cudaSuccess ) {
            int devId;
            hfcheck(hfcuda_vdm_get_device(&devId));
            hfcheck(hfcuda_am_del_mem_dev(devPtr, devId));
        }
    }

    hfinf("[trapper] cudaFree() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t
    cudaMalloc(
        void** devPtr,
        size_t size)
{   
    hfinf("[trapper] cudaMalloc() [CALL] "
            "size=%lu\n",
            size);

    struct {
        void* devPtr;
        cudaError_t cudaError;
    } d2t_msg;

    // cudaMalloc( 0 ) is valid code and produces a NULL ptr and cudaSuccess
    // but we can't add that to our memory manager, otherwise
    // we might try to insert multiple NULL pointer with size 0 :-(
    // still if NULL would be valid with a larger size, we can support that:
    if( size > 0 ) {
        struct __attribute__((packed)) {
            hf_msgdescr_t header;
            struct __attribute__((packed)) {
                size_t size;
            } data;
        } t2d_msg;
        HF_MSGDESCR_SET( &t2d_msg.header,
                         HFCUDA_CUDART_cudaMalloc );
        t2d_msg.data.size = size;

        hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));

        hfcheck(hfcuda_comm_recv(&d2t_msg, sizeof(d2t_msg)));

        // returns: cudaSuccess, cudaErrorMemoryAllocation
        if( d2t_msg.cudaError == cudaSuccess ) {
            int devId;
            hfcheck(hfcuda_vdm_get_device(&devId));
            // ToDo: should indicate that accessible only by device
            hfcheck(hfcuda_am_add_mem_dev(d2t_msg.devPtr, size, devId));
        }
    }
    else {
        // hint: maybe we should call the original call here ... locally 
        d2t_msg.devPtr = NULL;
        d2t_msg.cudaError = cudaSuccess;
    }

    hfinf("[trapper] cudaMalloc() [DONE] "
            "cudaError=%d devPtr=0x%016lx\n",
            d2t_msg.cudaError, d2t_msg.devPtr);

    if( devPtr )
        *devPtr = d2t_msg.devPtr;

    return d2t_msg.cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t
    cudaMallocHost(
        void** ptr,
        size_t size)
{
    hfinf("[trapper] cudaMallocHost() [CALL] "
            "size=%lu\n",
            size);

    struct {
        void* ptr;
        cudaError_t cudaError;
    } d2t_msg;

    // ToDo: check if cudaMallocHost( 0 ) has same behavior as cudaMalloc( 0 )
    if( size > 0 ) {
        struct __attribute__((packed)) {
            hf_msgdescr_t header;
            struct __attribute__((packed)) {
                size_t size;
            } data;
        } t2d_msg;
        HF_MSGDESCR_SET( &t2d_msg.header,
                         HFCUDA_CUDART_cudaMallocHost );
        t2d_msg.data.size = size;

        hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));

        hfcheck(hfcuda_comm_recv(&d2t_msg, sizeof(d2t_msg)));

        // returns: cudaSuccess, cudaErrorMemoryAllocation
        if( d2t_msg.cudaError == cudaSuccess ) {
            int devId;
            hfcheck(hfcuda_vdm_get_device(&devId));
            // ToDo: should indicate that accessible on device and host
            hfcheck(hfcuda_am_add_mem_dev(d2t_msg.ptr, size, devId));
        }
    }
    else {
        // hint: maybe we should call the original call here ... locally 
        d2t_msg.ptr = NULL;
        d2t_msg.cudaError = cudaSuccess;
    }

    hfinf("[trapper] cudaMallocHost() [DONE] "
            "cudaError=%d ptr=0x%016lx\n",
            d2t_msg.cudaError, d2t_msg.ptr);

    if( ptr )
        *ptr = d2t_msg.ptr;

    return d2t_msg.cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t
    cudaMemGetInfo(
        size_t* free,
        size_t* total)
{
    hf_msgdescr_t header;
    HF_MSGDESCR_SET( &header,
                     HFCUDA_CUDART_cudaMemGetInfo );

    hfinf("[trapper] cudaMemGetInfo() [CALL] CODE=%d "
            "\n", header.func);

    hfcheck(hfcuda_comm_send(&header, sizeof(header)));

    struct {
        cudaError_t cudaError;
        size_t free;
        size_t total;
    } d2t_msg;

    hfcheck(hfcuda_comm_recv(&d2t_msg, sizeof(d2t_msg)));

    hfinf("[trapper] cudaMemGetInfo() [DONE] "
            "cudaError=%d free=%lu total=%lu\n",
            d2t_msg.cudaError, d2t_msg.free, d2t_msg.total);

    if( free )
        *free = d2t_msg.free;
    if( total )
        *total = d2t_msg.total;

    return d2t_msg.cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t cudaMemcpy(
        void* dst,
        const void* src,
        size_t count,
        enum cudaMemcpyKind kind)
{
    hfinf("[trapper] cudaMemcpy() [CALL] "
            "dst=0x%016lx src=0x%016lx count=%lu kind=%d=%s\n",
            dst, src, count, kind, cudaMemcpy_str[kind]);

    cudaError_t cudaError = cudaSuccess;
    if( count > 0 ) { // only send if larger then 0. Some people supply src = NULL, count = 0 :-(

        struct __attribute__((packed)) {
            hf_msgdescr_t header;
            struct __attribute__((packed)) {
                void* dst;
                const void* src;
                size_t count;
                enum cudaMemcpyKind kind;
                // ToDo: one could put small memcpy request to the daemon into this message.
            } data;
        } t2d_msg;
        HF_MSGDESCR_SET( &t2d_msg.header,
                         HFCUDA_CUDART_cudaMemcpy );
        t2d_msg.data.dst = dst;
        t2d_msg.data.src = src;
        t2d_msg.data.count = count;
        t2d_msg.data.kind = kind;

        hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));

        switch (kind) {
            case cudaMemcpyHostToDevice:
                hfcheck(hfcuda_comm_send((void*) src, count));
                break;

            case cudaMemcpyDeviceToHost:
                hfcheck(hfcuda_comm_recv(dst, count));
                break;

            case cudaMemcpyDeviceToDevice:
                // in thise case we don't need to send anything, will just be delegated
                break;

            // ToDo:
            default:
                exit(-1);
        }

        hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
    }

    hfinf("[trapper] cudaMemcpy() [DONE] cudaError=%d\n",
            cudaError);

    return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t cudaMemcpyAsync	(	void * dst,
                              const void * src,
                              size_t count,
                              enum cudaMemcpyKind kind,
                              cudaStream_t stream
                            )	
{
    hfinf("[trapper] cudaMemcpyAsync() [CALL] "
            "dst=0x%016lx src=0x%016lx count=%lu kind=%d=%s stream = %d\n",
            dst, src, count, kind, cudaMemcpy_str[kind], stream);

    cudaError_t cudaError = cudaSuccess;
    if( count > 0 ) { // only send if larger then 0. Some people supply src = NULL, count = 0 :-(
        struct __attribute__((packed)) {
            hf_msgdescr_t header;
            struct __attribute__((packed)) {
                void* dst;
                const void* src;
                size_t count;
                enum cudaMemcpyKind kind;
                cudaStream_t stream;
            } data;
        } t2d_msg;
        HF_MSGDESCR_SET( &t2d_msg.header,
                         HFCUDA_CUDART_cudaMemcpyAsync );
        t2d_msg.data.dst = dst;
        t2d_msg.data.src = src;
        t2d_msg.data.count = count;
        t2d_msg.data.kind = kind;
        t2d_msg.data.stream = stream;

        hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));

        switch (kind) {
            case cudaMemcpyHostToDevice:
                hfcheck(hfcuda_comm_send((void*) src, count));
                break;

            case cudaMemcpyDeviceToHost:
                hfcheck(hfcuda_comm_recv(dst, count));
                break;

            case cudaMemcpyDeviceToDevice:
                // in thise case we don't need to send anything, will just be delegated
                break;

            // ToDo:
            default:
                exit(-1);
        }

        hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
    }

    hfinf("[trapper] cudaMemcpyAsync() [DONE] cudaError=%d\n",
            cudaError);

    return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t cudaMemcpyToSymbol (const void* symbol, const void* src, size_t count, size_t offset, enum cudaMemcpyKind kind )
{
    Dl_info info;
    dladdr(symbol, &info);
    if(info.dli_sname == NULL
       || info.dli_saddr == NULL) {
      // https://stackoverflow.com/questions/11731229/dladdr-doesnt-return-the-function-name
      hferr("dladdr didn't return function name\n"
            "Try to link with '-Wl,--export-dynamic' and compile with '-rdynamic'\n");
      exit(-1);
    }

    hfinf("[trapper] cudaMemcpyToSymbol() [CALL] "
            "symbol=0x%016lx(%s) src=0x%016lx count=%lu kind=%d=%s\n",
            symbol, info.dli_sname, src, count, kind, cudaMemcpy_str[kind]);

    cudaError_t cudaError = cudaSuccess;
    if( count > 0 ) { // only send if larger then 0. Some people supply src = NULL, count = 0 :-(
        enum cudaMemcpyKind tmp_kind = kind;
        if( kind == cudaMemcpyDefault ) {
            // just need to check if 'src' is on host or not!
            // then use either cudaMemcpyHostToDevice or cudaMemcpyDeviceToDevice
            int devId;
            hfcheck(hfcuda_vdm_get_device(&devId));

            hfcuda_am_node_t* _____result_MEMCHECK = hfcuda_am_mem_check( (void*) src, devId );
            if( _____result_MEMCHECK && _____result_MEMCHECK->isdevice )
                tmp_kind = cudaMemcpyDeviceToDevice;
            else
                tmp_kind = cudaMemcpyHostToDevice;
        }

        struct __attribute__((packed)) {
            hf_msgdescr_t header;
            struct __attribute__((packed)) {
                const void* src;
                size_t count;
                size_t offset;
                enum cudaMemcpyKind kind;
                unsigned int symbol_name_len;
            } data;
        } t2d_msg;
        HF_MSGDESCR_SET( &t2d_msg.header,
                         HFCUDA_CUDART_cudaMemcpyToSymbol );
        t2d_msg.data.src = src;
        t2d_msg.data.count = count;
        t2d_msg.data.offset = offset;
        t2d_msg.data.kind = tmp_kind; // use tmp kind!
        t2d_msg.data.symbol_name_len = strlen( info.dli_sname ) + 1;

        hfcheck(hfcuda_comm_send( &t2d_msg, sizeof(t2d_msg) ));
        hfcheck(hfcuda_comm_send( (char*)info.dli_sname, t2d_msg.data.symbol_name_len ));

        // kind can be either cudaMemcpyHostToDevice, cudaMemcpyDeviceToDevice, or cudaMemcpyDefault.
        // Passing cudaMemcpyDefault is recommended, in which case the type of transfer is inferred
        // from the pointer values. However, cudaMemcpyDefault is only allowed on systems that support unified virtual addressing.
        switch (tmp_kind) { // use tmp_kind!
            case cudaMemcpyHostToDevice:
                hfcheck(hfcuda_comm_send((void*) src, count));
                break;

            case cudaMemcpyDeviceToDevice:
                // in thise case we don't need to send anything, will just be delegated
                break;

            case cudaMemcpyDefault:
                break;

            default:
                break;
        }

        hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
    }

    hfinf("[trapper] cudaMemcpyToSymbol() [DONE] cudaError=%d\n",
            cudaError);

    return cudaError;
}


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// ------------ below functions need a deep review -----------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

//This function is used to allocate memory on multiple machines when the application is using GPUs from multiple machines

cudaError_t __cudaHostAlloc(
        void**          pHost,
        void**          rPtr,
        size_t          size,
        unsigned int    flags,
        bool            allocateHostPtr)
{
    // Start.
    hfinf("[trapper] cudaHostAlloc() [CALL] "
          "pHost=%p size=%lu flags=%d\n",
          *pHost, size, flags);

    // Function parameters. 
    cudaError_t             rCudaError;
    cudaError_t             lCudaError = cudaSuccess;

    // Send function code.
    hf_msgdescr_t header;
    HF_MSGDESCR_SET( &header,
                     HFCUDA_CUDART_cudaHostAlloc );
    hfcheck(hfcuda_comm_send(&header, sizeof(header)));
    
    // Sending cuda inputs to the remote node.
    hfcheck(hfcuda_comm_send(&size,     sizeof(size_t)));
    hfcheck(hfcuda_comm_send(&flags,    sizeof(unsigned int)));

    // Allocate memory on the local node if it was not allocated yet. 
    // Synchronize if it is allocating memory in the local node. 
    if (allocateHostPtr) {
        void *lptr = malloc( size );
        if(lptr == NULL) {
            lCudaError = cudaErrorMemoryAllocation;
            hferr("[trapper] cudaMallocHost(): could not alloc the memory "
                  "for size=%d\n", size);
        } 
        else if (mlock(lptr, size)) {
            free(lptr);
            lptr = NULL;
            lCudaError = cudaErrorMemoryAllocation;
            hferr("[trapper] cudaMallocHost(): could not pin the memory.\n");
        }
        else
            lCudaError = cudaSuccess;

        if( pHost )
            *pHost = lptr;
    }

    //Receiving cuda outputs from the remote node.
    hfcheck(hfcuda_comm_recv(&rCudaError,   sizeof(cudaError_t)));
    hfcheck(hfcuda_comm_recv(rPtr,          sizeof(void*)));

    // Adding the local and remote pointers to the hash table.
    char* hostName;
    hfcheck(hfcuda_vdm_get_curr_host(&hostName));
    hfcheck(hfcuda_am_add_host_pointer(*pHost, *rPtr, size, hostName));

    // Finish.
    hfinf("[trapper] cudaHostAlloc() [DONE] "
          "lCudaError=%d rCudaError=%d lPtr=%p rPtr=%p\n",
          lCudaError, rCudaError, *pHost, *rPtr);

    return rCudaError;
}


// -----------------------------------------------------------------------------


cudaError_t cudaHostAlloc(
        void** pHost,
        size_t size,
        unsigned int flags)
{
    //Receive function outputs.
    switch (flags) {
        default:
            hferr("[trapper] ERROR! requested flag of allocated"
                  "memory not supported: %d\n",
                  flags);
            exit(-1); // We really need to exit hard here.
                      // Other flags despite of the below ones are not supported!

        case cudaHostAllocDefault:
        case cudaHostAllocPortable:
            // keep on going
            break;
    }

    //Function output.
    void* rPtr;
    cudaError_t cudaError = __cudaHostAlloc(pHost, &rPtr, size, flags, true);
    hfinf("[trapper] cudaHostAlloc() [DONE] "
          "lPtr=%p rPtr=%p\n",
          *pHost, rPtr);

    return cudaError;
}


// -----------------------------------------------------------------------------

/* Passes back device pointer of mapped host memory allocated 
 *  * by cudaHostAlloc or registered by cudaHostRegister.
 *   * */
cudaError_t cudaHostGetDevicePointer(
                void** pDevice, 
                        void* pHost, 
                                unsigned int  flags)
{
        // Start.
        hfinf("[trapper] cudaHostGetDevicePointer() [CALL] "
              "pDevice=%p pHost=%p flags=%d\n",
              *pDevice, pHost,flags);
        // Send function code.
        hf_msgdescr_t header;
        HF_MSGDESCR_SET( &header,
                         HFCUDA_CUDART_cudaHostGetDevicePointer );
        hfcheck(hfcuda_comm_send(&header, sizeof(header)));
        
        // Send function inputs.
        void* rPtr = NULL;
        char* hostName;
        hfcheck(hfcuda_vdm_get_curr_host(&hostName));
        hferr_t error = hfcuda_am_get_host_pointer_attr(&rPtr, pHost, hostName, rPtrPointer);
        
        switch (error ) {
        case HFOK:
        case HFErrorRemoteHostAddrDoesNotExist:       
           break;
       
        default:
           hfcheck(error);
        }
        
        hfcheck(hfcuda_comm_send(&flags, sizeof(unsigned int)));
        
        // Function outputs.
        cudaError_t cudaError;
       
        // Receive function outputs.
        hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
        hfcheck(hfcuda_comm_recv(pDevice, sizeof(void*)));
        
        // Finish.
        hfinf("[trapper] cudaHostGetDevicePointer() [DONE] "
              "cudaError=%d pDevice=%p\n",
               cudaError, *pDevice);
        return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t
    cudaHostRegister(
        void* ptr,
        size_t size,
        unsigned int flags)
{
    hfinf("[trapper] cudaHostRegister() [CALL] "
            "ptr=0x%016lx, size=%lu flags=%u\n",
            ptr, size, flags);

    // Question: how can this work?
    //           The PTR is very likely from the trapper VA (e.g.
    //           malloc). Therefore sending the cudaHostRegister
    //           to the other side and execute it should always
    //           fail (except if address is living on the other
    //           side, what I assume is not the case) .... ToDo!

    hf_msgdescr_t header;
    HF_MSGDESCR_SET( &header,
                     HFCUDA_CUDART_cudaHostRegister );
    hfcheck(hfcuda_comm_send(&header, sizeof(header)));
    hfcheck(hfcuda_comm_send(&ptr, sizeof(void*)));
    hfcheck(hfcuda_comm_send(&size, sizeof(size_t)));
    hfcheck(hfcuda_comm_send(&flags, sizeof(unsigned int)));

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));

    exit(-1); // this function is broken, hence let's die here safely

    hfinf("[trapper] cudaHostRegister() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t cudaHostUnregister(
        void *ptr)
{
    //Start.
    hfinf("[trapper] cudaHostUnregister() [CALL] \n");
    (void)ptr;

    /*
    //Send function code. 
    hf_msgdescr_t header;
    HF_MSGDESCR_SET( &header,
                     HFCUDA_CUDART_cudaHostUnregister );
    hfcheck(hfcuda_comm_send(&header, sizeof(header)));
    
    //Send function inputs. 
    hfcheck(hfcuda_comm_send(&, sizeof()));

    //Function outputs. 
    cudaError_t cudaError;

    //Receive function outputs. 
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));

    hfdeb("[trapper] cudaHostUnregister: stream=%p\n",
           pStream);

    //Finish.
    hfinf("[trapper] cudaHostUnregister() [DONE] "
          "cudaError= Function not implemented\n");
    */

    hferr("[trapper] cudaHostUnregister() [DONE] "
          "cudaError= Function not implemented\n");
    return cudaErrorNotSupported;
}

// -----------------------------------------------------------------------------

//
//  @nmimura: Simple wrapper to implement ATS checkpointing code,
//  basically just ship the function to the other side while sending the 
//  data to be prefecthed.
//

cudaError_t cudaMemPrefetchAsync(
    const void* devPtr, 
    size_t count, 
    int dstDevice, 
    cudaStream_t stream)
{
  hfcuda_function_t function = HFCUDA_CUDART_cudaMemPrefetchAsync;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&count, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&dstDevice, sizeof(int)));
  hfcheck(hfcuda_comm_send(&stream, sizeof(cudaStream_t)));
  hfcheck(hfcuda_comm_send((void*) devPtr, count));

  cudaError_t cudaError;
  hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));

  void* cmpa_remote;
  hfcheck(hfcuda_comm_recv(&cmpa_remote, sizeof(void*)));
  cmpa_addr[cmpa_cnt] = (void*) devPtr;
  cmpa_tran[cmpa_cnt] = cmpa_remote;
  printf("[trapper] cudaMemPrefetchAsync: added "
         "cmpa_addr[%lu]=0x%016lx => cmpa_tran[%lu]=0x%016lx\n",
         cmpa_cnt, (size_t) cmpa_addr[cmpa_cnt], 
         cmpa_cnt, (size_t) cmpa_tran[cmpa_cnt]);
  cmpa_cnt++;

  return cudaError;
}


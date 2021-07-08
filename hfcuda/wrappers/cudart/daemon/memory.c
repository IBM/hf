// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaFree(void)
{
    hfinf("[daemon] cudaFree() [INIT]\n");

    struct __attribute__((packed)) {
        void* devPtr;
    } t2d_msg_data;

    // header already handled by daemon!
    hfcheck(hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));

    hfinf("[daemon] cudaFree() [CALL] "
            "devPtr=0x%016lx\n",
            t2d_msg_data.devPtr);

    cudaError_t cudaError = cudaFree( t2d_msg_data.devPtr );

    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaFree() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaMalloc(void)
{
    hfinf("[daemon] cudaMalloc() [INIT]\n");

    struct __attribute__((packed)) {
        size_t size;
    } t2d_msg_data;

    hfcheck(hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));

    hfinf("[daemon] cudaMalloc() [CALL] "
            "size=%lu\n",
            t2d_msg_data.size);

    struct {
        void* devPtr;
        cudaError_t cudaError;
    } d2t_msg;
    d2t_msg.cudaError = cudaMalloc( &d2t_msg.devPtr, t2d_msg_data.size );

    hfcheck(hfcuda_comm_send(&d2t_msg, sizeof(d2t_msg)));

    hfinf("[daemon] cudaMalloc() [DONE] "
            "cudaError=%d devPtr=0x%016lx\n",
            d2t_msg.cudaError, d2t_msg.devPtr);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaMallocHost(void)
{
    hfinf("[daemon] cudaMallocHost() [INIT]\n");

    struct __attribute__((packed)) {
        size_t size;
    } t2d_msg_data;

    hfcheck(hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));

    hfinf("[daemon] cudaMallocHost() [CALL] "
            "size=%lu\n");

    struct {
        void* ptr;
        cudaError_t cudaError;
    } d2t_msg;
    d2t_msg.cudaError = cudaMallocHost( &d2t_msg.ptr, t2d_msg_data.size);

    hfcheck(hfcuda_comm_send(&d2t_msg, sizeof(d2t_msg)));

    hfinf("[daemon] cudaMallocHost() [DONE] "
            "\n");
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaMemGetInfo(void)
{
    hfinf("[daemon] cudaMallocHost() [INIT]\n");

    hfinf("[daemon] cudaMallocHost() [CALL] "
            "\n");

    struct {
        cudaError_t cudaError;
        size_t free;
        size_t total;
    } d2t_msg;

    d2t_msg.cudaError = cudaMemGetInfo(&d2t_msg.free,
                                       &d2t_msg.total);

    hfcheck(hfcuda_comm_send(&d2t_msg, sizeof(d2t_msg)));

    hfinf("[daemon] cudaMallocHost() [DONE] "
            "cudaError=%d free=%lu total=%lu\n",
            d2t_msg.cudaError, d2t_msg.free, d2t_msg.total);

    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaMemcpy(void)
{
    hfinf("[daemon] cudaMemcpy() [INIT]\n");

    struct __attribute__((packed)) {
        void* dst;
        const void* src;
        size_t count;
        enum cudaMemcpyKind kind;
    } t2d_msg_data;

    hfcheck(hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));

    hfinf("[daemon] cudaMemcpy() [CALL] "
            "dst=0x%016lx src=0x%016lx count=%lu kind=%d=%s\n",
            t2d_msg_data.dst, t2d_msg_data.src, t2d_msg_data.count,
            t2d_msg_data.kind, cudaMemcpy_str[t2d_msg_data.kind]);
    
    // ToDo: create an asynchronous implementation not requiring a synchronous implementation
    cudaError_t cudaError;
    switch (t2d_msg_data.kind) {
        case cudaMemcpyHostToDevice:
        {
            void* data;
            cudaError_t merr = cudaMallocHost(&data, t2d_msg_data.count);
            if(merr != cudaSuccess)
                data = malloc (t2d_msg_data.count);

            hfcheck(hfcuda_comm_recv(data, t2d_msg_data.count));
            cudaError =
                cudaMemcpy(
                    t2d_msg_data.dst,
                    data,
                    t2d_msg_data.count,
                    t2d_msg_data.kind);

            if(merr == cudaSuccess)
                cudaFreeHost(data);
            else
                free(data);
            break;
        }
        case cudaMemcpyDeviceToHost:
        {
            void* data;
            cudaError_t merr = cudaMallocHost(&data, t2d_msg_data.count);
            if(merr != cudaSuccess)
                data = malloc (t2d_msg_data.count);

            cudaError =
                cudaMemcpy(
                    data,
                    t2d_msg_data.src,
                    t2d_msg_data.count,
                    t2d_msg_data.kind);

            hfcheck(hfcuda_comm_send(data, t2d_msg_data.count));

            if(merr == cudaSuccess)
                cudaFreeHost(data);
            else
                free(data);
            break;
        }
        case cudaMemcpyDeviceToDevice:
            // is just a delegation
            cudaError =
                cudaMemcpy(
                    t2d_msg_data.dst,
                    t2d_msg_data.src,
                    t2d_msg_data.count,
                    t2d_msg_data.kind);
            break;

        default:
            hferr("[daemon] cudaMemcpy() [ERROR] kind not supported (%d)\n",
                  t2d_msg_data.kind);
            exit(-1);
    }

    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaMemcpy() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}


// -----------------------------------------------------------------------------

void* __thread_memcpy_H2D(void *arg)
{
    struct {
        pthread_t thread;
        cudaEvent_t event;
        cudaError_t mem_alloc_cuda;
        char data[];
    } *memHtD = (typeof(memHtD)) arg;

    cudaError_t werr;
    do {
      usleep(10);
    } while( (werr = cudaEventQuery( memHtD->event )) == cudaErrorNotReady );

    // doesn't matter if the error code was successful or not.
    // As long as it is not cudaErrorNotReady anymore, we can delete the buffer and die

    cudaEventDestroy( memHtD->event );

    if(memHtD->mem_alloc_cuda == cudaSuccess)
        cudaFreeHost(memHtD);
    else
        free(memHtD);
    return NULL;
} 

hferr_t
    handle_HFCUDA_CUDART_cudaMemcpyAsync(void)
{
    hfinf("[daemon] cudaMemcpyAsync() [INIT]\n");

    struct __attribute__((packed)) {
        void* dst;
        const void* src;
        size_t count;
        enum cudaMemcpyKind kind;
        cudaStream_t stream;
    } t2d_msg_data;

    hfcheck(hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));

    hfinf("[daemon] cudaMemcpyAsync() [CALL] "
            "dst=0x%016lx src=0x%016lx count=%lu kind=%d=%s stream=%s\n",
            t2d_msg_data.dst, t2d_msg_data.src, t2d_msg_data.count,
            t2d_msg_data.kind, cudaMemcpy_str[t2d_msg_data.kind], t2d_msg_data.stream);
    
    cudaError_t cudaError;
    switch (t2d_msg_data.kind) {

        case cudaMemcpyHostToDevice:
        {
            struct {
                pthread_t thread;
                cudaEvent_t event;
                cudaError_t mem_alloc_cuda;
                char data[];
            } *memHtD;
            cudaError_t merr = cudaMallocHost((void**)&memHtD, sizeof(memHtD[0]) + t2d_msg_data.count);
            if(merr != cudaSuccess)
                memHtD = malloc (sizeof(memHtD[0]) + t2d_msg_data.count);

            hfcheck(hfcuda_comm_recv(memHtD->data, t2d_msg_data.count));

            cudaError = cudaMemcpyAsync( t2d_msg_data.dst, memHtD->data,
                                         t2d_msg_data.count, t2d_msg_data.kind,
                                         t2d_msg_data.stream );

            bool do_cleanup = true;
            if(cudaError == cudaSuccess) {
                if( cudaEventCreate ( &memHtD->event ) == cudaSuccess
                    && cudaEventRecord ( memHtD->event, t2d_msg_data.stream ) == cudaSuccess ) {
                    // we need some garbage collection here.
                    // as we can't just erase the allocation here, we spawn a thread and let the thread
                    // clear the allocation as soon as the cudaMemcpyAsync() finished.
                    // the thread will subsequently die.
                    memHtD->mem_alloc_cuda = merr;
                    pthread_create( &memHtD->thread, NULL, __thread_memcpy_H2D, memHtD );
                    do_cleanup = false; // cleanup happens in thread
                }
                else {
                    // just a fallback to make sure that the data is copied over
                    // (in case we can't handle it asynchronous)
                    cudaStreamSynchronize(t2d_msg_data.stream);
                }
            }

            if( do_cleanup ) {
                if(merr == cudaSuccess)
                    cudaFreeHost(memHtD);
                else
                    free(memHtD);
            }

            break;
        }

        case cudaMemcpyDeviceToHost:
        {
            void* data;
            cudaError_t merr = cudaMallocHost(&data, t2d_msg_data.count);
            if(merr != cudaSuccess)
                data = malloc (t2d_msg_data.count);

            // we need to use cudaMemcpy(), as the buffer will be deleted!
            // hence we need to make sure that the preceding stream stays in order!
            // otherwise we would skip preceding commands!
            cudaError = cudaStreamSynchronize(t2d_msg_data.stream);
            if( cudaError == cudaSuccess )
                cudaError = cudaMemcpy( data, t2d_msg_data.src,
                                        t2d_msg_data.count, t2d_msg_data.kind );

            hfcheck(hfcuda_comm_send(data, t2d_msg_data.count));

            if(merr == cudaSuccess)
                cudaFreeHost(data);
            else
                free(data);

            break;
        }

        case cudaMemcpyDeviceToDevice:
            // is just a delegation
            cudaError =
                cudaMemcpyAsync(
                    t2d_msg_data.dst,
                    t2d_msg_data.src,
                    t2d_msg_data.count,
                    t2d_msg_data.kind,
                    t2d_msg_data.stream);
            break;

        case cudaMemcpyHostToHost:
            hferr("[daemon] cudaMemcpyAsync() [ERROR] H2H will not be executed on the host (%d)\n");
            break; // although this is not supported on the daemon, we don't really need to throw an error

        default:
            hferr("[daemon] cudaMemcpyAsync() [ERROR] kind not supported (%d)\n",
                  t2d_msg_data.kind);
            exit(-1);
    }

    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaMemcpyAsync() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaMemcpyToSymbol(void)
{
    hfinf("[daemon] cudaMemcpyToSymbol() [INIT]\n");

    struct __attribute__((packed)) {
        const void* src;
        size_t count;
        size_t offset;
        enum cudaMemcpyKind kind;
        unsigned int symbol_name_len;
    } t2d_msg_data;

    hfcheck(hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));

    char* symbol_name = (char*) malloc ( t2d_msg_data.symbol_name_len );
    hfcheck(hfcuda_comm_recv( symbol_name, t2d_msg_data.symbol_name_len ));

    const void* symbol;
    hfcheck(hfcuda_shlib_sym(&symbol, symbol_name));

    hfinf("[daemon] cudaMemcpyToSymbol() [CALL] "
            "symbol=%s(%p) src=0x%016lx count=%lu kind=%d=%s\n",
            symbol_name, symbol, t2d_msg_data.src, t2d_msg_data.count,
            t2d_msg_data.kind, cudaMemcpy_str[t2d_msg_data.kind]);
    
    // ToDo: create an asynchronous implementation not requiring a synchronous implementation
    cudaError_t cudaError;
    switch (t2d_msg_data.kind) {
        case cudaMemcpyHostToDevice:
        {
            void* data;
            cudaError_t merr = cudaMallocHost(&data, t2d_msg_data.count);
            if(merr != cudaSuccess)
                data = malloc (t2d_msg_data.count);

            hfcheck(hfcuda_comm_recv(data, t2d_msg_data.count));
            cudaError =
                cudaMemcpyToSymbol(
                    symbol,
                    data,
                    t2d_msg_data.count,
                    t2d_msg_data.offset,
                    t2d_msg_data.kind);

            if(merr == cudaSuccess)
                cudaFreeHost(data);
            else
                free(data);
            break;
        }
        case cudaMemcpyDeviceToDevice:
            // is just a delegation
            cudaError =
                cudaMemcpyToSymbol(
                    symbol,
                    t2d_msg_data.src,
                    t2d_msg_data.count,
                    t2d_msg_data.offset,
                    t2d_msg_data.kind);
            break;

        default:
            // just print warning, as this is something that is anyways not supported ...
            hferr("[daemon] cudaMemcpyToSymbol() [WARN] kind not supported (%d)\n",
                  t2d_msg_data.kind);
    }

    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaMemcpyToSymbol() [DONE] "
            "cudaError=%d\n",
            cudaError);

    free( symbol_name );

    return HFOK;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// ------------ below functions need a deep review -----------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

hferr_t handle_HFCUDA_CUDART_cudaHostAlloc(void)
{
    hfinf("[daemon] cudaHostAlloc() [INIT]\n");

    // Function inputs.
    void* pHost;
    size_t size;
    unsigned int flags;

    // Receive function inputs.
    hfcheck(hfcuda_comm_recv(&size, sizeof(size_t)));
    hfcheck(hfcuda_comm_recv(&flags, sizeof(unsigned int)));

    // Call function. 
    cudaError_t cudaError = cudaHostAlloc(&pHost, size, flags);
    hfdeb("[daemon] cudaHostAlloc(): pHost=%p size=%lu\n", pHost, size);

    //Send function outputs. 
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));
    hfcheck(hfcuda_comm_send(&pHost, sizeof(void*)));

    // Finish. 
    hfinf("[daemon] cudaHostAlloc() [DONE] "
          "cudaError=%d\n",
          cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t handle_cudaHostGetDevicePointer(void)
{
    hfinf("[daemon] cudaHostGetDevicePointer() [INIT]\n");

    // Function inputs. 
    void* pDevice;
    void* pHost;
    unsigned int flags;

    // Receive function inputs. 
    hfcheck(hfcuda_comm_recv(&pHost, sizeof(void*)));
    hfcheck(hfcuda_comm_recv(&flags, sizeof(unsigned int)));

    // Call function. 
    cudaError_t cudaError = cudaHostGetDevicePointer(&pDevice, pHost, flags);
    hfdeb("[daemon] cudaHostGetDevicePointer:"
          "pDevice=0x%016lx\n", pDevice);

    // Send function outputs. 
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));
    hfcheck(hfcuda_comm_send(&pDevice, sizeof(void*)));

    // Finish. 
    hfinf("[daemon] cudaHostGetDevicePointer() [DONE]"
          "cudaError=%d\n",
          cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaHostRegister(void)
{
    hfinf("[daemon] cudaHostRegister() [INIT]\n");

    void* ptr;    
    size_t size;
    unsigned int flags;
    hfcheck(hfcuda_comm_recv(&ptr, sizeof(void*)));          
    hfcheck(hfcuda_comm_recv(&size, sizeof(size_t)));        
    hfcheck(hfcuda_comm_recv(&flags, sizeof(unsigned int)));     

    hfinf("[daemon] cudaHostRegister() [CALL] "
            "ptr=0x%016lx, size=%lu flags=%u\n",
            ptr, size, flags);

    cudaError_t cudaError =
        cudaHostRegister(
            ptr,
            size,
            flags);
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));
    hfcheck(hfcuda_comm_send(&ptr, sizeof(void*)));

    hfinf("[daemon] cudaHostRegister() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t handle_HFCUDA_CUDART_cudaMemPrefetchAsync()
{
  void* devPtr;
  size_t count;
  int dstDevice;
  cudaStream_t stream;

  hfcheck(hfcuda_comm_recv(&count, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(&dstDevice, sizeof(int)));
  hfcheck(hfcuda_comm_recv(&stream, sizeof(cudaStream_t)));
  devPtr = malloc(count);
  hfcheck(hfcuda_comm_recv(devPtr, count));

  printf("[daemon] cudaMemPrefetchAsync: "
         "devPtr=0x%016lx count=%lu dstDevice=%d\n",
         (size_t) devPtr, count, dstDevice);

  cudaError_t cudaError = 
    cudaMemPrefetchAsync(
        devPtr, 
        count, 
        dstDevice, 
        stream);
  hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));
  hfcheck(hfcuda_comm_send(&devPtr, sizeof(void*)));

  return HFOK;
}


//  ----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaConfigureCall(void)
{
    hfinf("[daemon] cudaConfigureCall() [INIT]\n");
    clockme("");
    clockme("(D) cudaConfigureCall start");

    struct __attribute__((packed)) {
        dim3 gridDim;
        dim3 blockDim;
        size_t sharedMem;
        cudaStream_t stream;
    } t2d_msg_data;

    hfcheck(hfcuda_comm_recv(&t2d_msg_data, sizeof(t2d_msg_data)));
    clockme("(D) cudaConfigureCall after recv");

    hfinf("[daemon] cudaConfigureCall() [CALL] "
            "gridDim=(%d,%d,%d) blockDim=(%d,%d,%d) sharedMem=%lu stream=%d\n",
            t2d_msg_data.gridDim.x, t2d_msg_data.gridDim.y, t2d_msg_data.gridDim.z,
            t2d_msg_data.blockDim.x, t2d_msg_data.blockDim.y, t2d_msg_data.blockDim.z,
            t2d_msg_data.sharedMem, t2d_msg_data.stream);

    cudaError_t cudaError = cudaConfigureCall(t2d_msg_data.gridDim, t2d_msg_data.blockDim,
                                              t2d_msg_data.sharedMem, t2d_msg_data.stream);
    clockme("(D) cudaConfigureCall after cudaConfigureCall");
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));
    clockme("(D) cudaConfigureCall after send");

    hfinf("[daemon] cudaConfigureCall() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

//  ----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaLaunch(void)
{
    hfinf("[daemon] cudaLaunch() [INIT]\n");

    clockme("");
    clockme("(D) cudaLaunch start");
    struct __attribute__((packed)) {
        size_t func_name_size;
        uint64_t opt_func_name[8]; // we try to send small strings directly
    } t2d_msg_data;

    unsigned t2d_msg_data_payload_len = sizeof(t2d_msg_data.opt_func_name);

    // that's the minimum we are required to recv! (includes everything until and included isDevPtr)
    unsigned t2d_msg_len = sizeof(t2d_msg_data) - t2d_msg_data_payload_len;
    clockme("(D) cudaLaunch after sizeof");

    hfcheck(hfcuda_comm_recv(&t2d_msg_data, t2d_msg_len));
    clockme("(D) cudaLaunch after recv");

    char* func_name;
    if( t2d_msg_data.func_name_size <= t2d_msg_data_payload_len )
        func_name = (char*)&t2d_msg_data.opt_func_name;
    else
        func_name = malloc(t2d_msg_data.func_name_size);
    clockme("(D) cudaLaunch after malloc");
    hfcheck(hfcuda_comm_recv(func_name, t2d_msg_data.func_name_size));
    clockme("(D) cudaLaunch after recv func_name");

    const void* func;
    hfcheck(hfcuda_shlib_sym(&func, func_name));
    clockme("(D) cudaLaunch after shlib");

    hfinf("[daemon] cudaLaunch() [CALL] "
            "func_name=%s, func=0x%016lx\n",
            func_name, func);

    cudaError_t cudaError = cudaLaunch(func);
    clockme("(D) cudaLaunch after cudaLaunch");
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));
    clockme("(D) cudaLaunch after send cudaError_t");

    hfinf("[daemon] cudaLaunch() [DONE] "
            "cudaError=%d\n",
            cudaError);

    if( t2d_msg_data.func_name_size > t2d_msg_data_payload_len )
        free( func_name );
    clockme("(D) cudaLaunch end");

    return HFOK;
}

//  ----------------------------------------------------------------------------
// https://devtalk.nvidia.com/default/topic/867257/how-to-use-cudalaunchkernel-in-cuda7-0/
// https://devtalk.nvidia.com/default/topic/979462/how-can-i-compile-cuda-code-then-link-it-to-a-c-clr-project/

hferr_t
    handle_HFCUDA_CUDART_cudaLaunchKernel(void)
{
    hfinf("[daemon] cudaLaunchKernel() [INIT]\n");

    struct {
      size_t cxx_func_name_len;
      dim3 gridDim;
      dim3 blockDim;
      unsigned int argc;
      size_t sharedMem;
      cudaStream_t stream;
    } t2d_msg;
    hfcheck(hfcuda_comm_recv(&t2d_msg, sizeof(t2d_msg)));

    // Get the mangled C++ function!
    char* cxx_func_name = (typeof(cxx_func_name)) malloc ( t2d_msg.cxx_func_name_len );
    hfcheck(hfcuda_comm_recv( cxx_func_name, t2d_msg.cxx_func_name_len ));

    const void* cxx_func;
    hfcheck(hfcuda_shlib_sym(&cxx_func, cxx_func_name));

    hfinf("[daemon] cudaLaunchKernel() func_name=%s\n", cxx_func_name);

    uint64_t *args = (uint64_t*) malloc ( t2d_msg.argc * sizeof(uint64_t) );
    hfcheck(hfcuda_comm_recv( args, t2d_msg.argc * sizeof(uint64_t) ));
    
    // need to produce the same pointer -> pointer map
    void** p_args = (void**) malloc ( t2d_msg.argc * sizeof(void*) );
    unsigned int i;
    for( i = 0; i < t2d_msg.argc; ++i )
      p_args[ i ] = (void*)args[ i ];

    hfinf("[daemon] cudaLaunchKernel() [CALL] "
            "func=0x%016lx\n",
            cxx_func);

    cudaError_t cudaError = cudaSuccess;
    
    // We are here calling the mangled C++ function, from C :-)
    // -> ToDo: try to call cudaLaunchKernel directly
    //          (one would then require the c_func_name instead of cxx_func_name!)

    // quick and dirty, but high performing! -> maybe we should even leave as is! (no 
    switch(t2d_msg.argc) {
    case 0:
      cudaError = (* ( cudaError_t(*)(void) )  cxx_func)();
      break;
    case 1:
      cudaError = (* ( cudaError_t(*)(uint64_t) ) cxx_func)(args[0]);
      break;
    case 2:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t) ) cxx_func)(args[0], args[1]);
      break;
    case 3:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t) )
                                      cxx_func)( args[0], args[1], args[2]);
      break;
    case 4:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t) )
                                      cxx_func)( args[0], args[1], args[2], args[3]);
    case 5:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4]);
    case 6:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5]);
    case 7:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6]);
    case 8:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7]);
    case 9:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8]);
    case 10:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8], args[9]);
      break;
    case 11:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8], args[9], args[10]);
      break;
    case 12:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8], args[9], args[10], args[11]);
      break;
    case 13:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8], args[9], args[10], args[11],
                                                 args[12]);
      break;
    case 14:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8], args[9], args[10], args[11],
                                                 args[12], args[13]);
      break;
    case 15:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8], args[9], args[10], args[11],
                                                 args[12], args[13], args[14]);
      break;
    case 16:
      cudaError = (* ( cudaError_t(*)(uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t,
                                      uint64_t, uint64_t, uint64_t, uint64_t) ) 
                                      cxx_func)( args[0], args[1], args[2], args[3],
                                                 args[4], args[5], args[6], args[7],
                                                 args[8], args[9], args[10], args[11],
                                                 args[12], args[13], args[14], args[15]);
      break;
    default:
      hferr("[daemon] don't support %d of arguments yet!\n", t2d_msg.argc);
    }
    
    
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaLaunchKernel() [DONE] "
            "cudaError=%d\n",
            cudaError);

    return HFOK;
}

//  ----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaSetupArgument(void)
{
    hfinf("[daemon] cudaSetupArgument() [INIT]\n");

    struct __attribute__((packed)) {
        size_t size;
        size_t offset;
        bool isDevPtr;
        union {
            void *devptr;
            uintptr_t data;
        };
        uint64_t __data[7];
    } t2d_msg_data;

    unsigned t2d_msg_data_payload_len = sizeof(t2d_msg_data.devptr) + sizeof(t2d_msg_data.__data);

    // that's the minimum we are required to recv! (includes everything until and included isDevPtr)
    unsigned t2d_msg_len = sizeof(t2d_msg_data) - t2d_msg_data_payload_len;

    hfcheck(hfcuda_comm_recv(&t2d_msg_data, t2d_msg_len));

    cudaError_t cudaError;
    if (t2d_msg_data.isDevPtr) {
        // in this case we can start receiving the devptr -> send will have pushed it already!
        hfcheck(hfcuda_comm_recv(&t2d_msg_data.devptr, sizeof(t2d_msg_data.devptr)));

        hfinf("[daemon] cudaSetupArgument() [CALL] "
                "arg=0x%016lx (PTR) size=%lu offset=%lu\n",
                t2d_msg_data.devptr, t2d_msg_data.size, t2d_msg_data.offset);
        cudaError = cudaSetupArgument(&t2d_msg_data.devptr, t2d_msg_data.size, t2d_msg_data.offset);
    }
    else {
        void* arg;
        if( t2d_msg_data.size > t2d_msg_data_payload_len )
            arg = malloc(t2d_msg_data.size);
        else
            arg = &t2d_msg_data.data;
        hfcheck(hfcuda_comm_recv(arg, t2d_msg_data.size));

        hfinf("[daemon] cudaSetupArgument() [CALL] "
                "arg=0x%016lx (VAR) size=%lu offset=%lu\n",
                arg, t2d_msg_data.size, t2d_msg_data.offset);
        cudaError = cudaSetupArgument(arg, t2d_msg_data.size, t2d_msg_data.offset);

        if( t2d_msg_data.size > t2d_msg_data_payload_len )
            free(arg);
    }

    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaSetupArgument() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

//  ----------------------------------------------------------------------------


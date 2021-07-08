//  ----------------------------------------------------------------------------

// @nmimura (2018-01-21): For now this wrapper won't do anything. The cache 
// configuration in this function is set for a specific kernel given its
// address. The execution of kernels on the current version of HFCUDA, however,
// is done via the name of the function and by loading it using the shared 
// library compiled from application code, therefore there is no guarantee that
// the address exists or is valid in the daemon side. There are several ways
// to implement this, such as keeping a map of kernels and cache options 
// (activating the right option when the kernel is launched). However, most
// if not all options will increase kernel launch latency. This could be
// solved in a transparent way if the kernel execution is done directly
// (without shared libraries) by using the driver API from CUDA.

cudaError_t
    cudaFuncSetCacheConfig(
        const void* func,
        enum cudaFuncCache cacheConfig)
{
    hfinf("[trapper] cudaFuncSetCacheConfig [CALL] "
            "func=0x%016lx cacheConfig=%d\n",
            func, cacheConfig);

    hfinf("[trapper] cudaFuncSetCacheConfig [INFO] "
            "call ignored\n");

    cudaError_t cudaError = cudaSuccess;
    hfinf("[trapper] cudaFuncSetCacheConfig [DONE] "
            "cudaError=%d\n",
            cudaError);
    return cudaError;
}

//  ----------------------------------------------------------------------------

cudaError_t cudaConfigureCall(
        dim3 gridDim,
        dim3 blockDim,
        size_t sharedMem,
        cudaStream_t stream)
{
    hfinf("[trapper] cudaConfigureCall() [CALL] "
            "gridDim=(%d,%d,%d) blockDim=(%d,%d,%d) sharedMem=%lu stream=%d\n",
            gridDim.x, gridDim.y, gridDim.z,
            blockDim.x, blockDim.y, blockDim.z,
            sharedMem, stream);

    clockme("");
    clockme("(T) cudaConfigureCall start");

    struct __attribute__((packed)) {
        hf_msgdescr_t header;
        struct __attribute__((packed)) {
            dim3 gridDim;
            dim3 blockDim;
            size_t sharedMem;
            cudaStream_t stream;
        } data;
    } t2d_msg;
    HF_MSGDESCR_SET( &t2d_msg.header,
                     HFCUDA_CUDART_cudaConfigureCall );
    t2d_msg.data.gridDim = gridDim;
    t2d_msg.data.blockDim = blockDim;
    t2d_msg.data.sharedMem = sharedMem;
    t2d_msg.data.stream = stream;
    clockme("(T) cudaConfigureCall after setup");

    hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));
    clockme("(T) cudaConfigureCall after send");
    
    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
    cudaError = 0;
    clockme("(T) cudaConfigureCall after recv");

    hfinf("[trapper] cudaConfigureCall() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return cudaError;
}

//  ----------------------------------------------------------------------------

cudaError_t cudaLaunch(const void* func)
{
    hfinf("[trapper] cudaLaunch() [INIT] "
            "func=0x%016lx\n",
            func);

    clockme("");
    clockme("(T) cudaLaunch start");
    Dl_info info;
    dladdr(func, &info);
    clockme("(T) cudaLaunch after dladdr");
    if(info.dli_sname == NULL
       || info.dli_saddr == NULL) {
      // https://stackoverflow.com/questions/11731229/dladdr-doesnt-return-the-function-name
      hferr("dladdr didn't return function name\n"
            "Try to link with '-Wl,--export-dynamic' and compile with '-rdynamic'\n");
      exit(-1);
    }
    clockme("(T) cudaLaunch after dli_sname");
    char* func_name = (char*) info.dli_sname;
    clockme("(T) cudaLaunch after dli_sname II");

    hfinf("[trapper] cudaLaunch() [CALL] func_name=%s\n", func_name);

    struct __attribute__((packed)) {
        hf_msgdescr_t header;
        struct __attribute__((packed)) {
            size_t func_name_size;
            uint64_t opt_func_name[8]; // we try to send small strings directly
        } data;
    } t2d_msg;
    HF_MSGDESCR_SET( &t2d_msg.header,
                     HFCUDA_CUDART_cudaLaunch );
    t2d_msg.data.func_name_size = (strlen(func_name) + 1) * sizeof(char);
    clockme("(T) cudaLaunch after struct");

    // if we can fit the name into the same message. Go for it!
    unsigned t2d_msg_data_payload_len = sizeof(t2d_msg.data.opt_func_name);

    // that's the minimum we are required to send! (includes everything until and included isDevPtr)
    unsigned t2d_msg_len = sizeof(t2d_msg) - t2d_msg_data_payload_len;
    
    clockme("(T) cudaLaunch after sizeof");
    if( t2d_msg.data.func_name_size <= t2d_msg_data_payload_len ) {
        memcpy( &t2d_msg.data.opt_func_name, func_name, t2d_msg.data.func_name_size );
        t2d_msg_len += t2d_msg.data.func_name_size;
    }
    clockme("(T) cudaLaunch after memcpy");

    hfcheck(hfcuda_comm_send(&t2d_msg, t2d_msg_len));
    clockme("(T) cudaLaunch after send t2d_msg");

    if( t2d_msg.data.func_name_size > t2d_msg_data_payload_len )
        hfcheck(hfcuda_comm_send(func_name, t2d_msg.data.func_name_size));
    clockme("(T) cudaLaunch after send func_name");

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
    clockme("(T) cudaLaunch after recv");

    hfinf("[trapper] cudaLaunch() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return cudaError;
}

//  ----------------------------------------------------------------------------

// https://docs.nvidia.com/cuda/cuda-driver-api/group__CUDA__EXEC.html#group__CUDA__EXEC_1gb8f3dc3031b40da29d5f9a7139e52e15
// cuLaunchKernel() (not the same function, but similar) specifies:
// The number of kernel parameters and their offsets and sizes do not need to be specified as that information is retrieved directly from the kernel's image.

cudaError_t cudaLaunchKernel (const void* func, dim3 gridDim, dim3 blockDim, void** args, size_t sharedMem, cudaStream_t stream )
{
    hfinf("[trapper] cudaLaunchKernel() [INIT] "
            "func=0x%016lx\n",
            func);

/*
    CUDA produces one C and one C++ function. We require the C++ function as it carries the parameter definition.
    Hence, go one hierarchy up and do the demangling.
    
    question: is __device_stub__ an object?
    
    #0  0x00002000090648d4 in exit () from /lib64/libc.so.6
    #1  0x0000200000079b94 in cudaLaunchKernel () from hfcuda/hfcuda_trapper.so
    #2  0x00000000100257fc in __device_stub__Z21grab_diagonals_kerneliPiPdS0_(int, int*, double*, double*) ()
    #3  0x0000000010025838 in grab_diagonals_kernel ()
    #4  0x0000000010025cd4 in device_create_diagonal ()
    #5  0x0000000010023308 in upload_hierarchy$AF21_4 () at amg2013.c:176
    #6  0x0000000010020ff8 in main (argc=4098, argv=0x200000015284 <_dl_fixup+228>)
        at amg2013.c:2899 
*/
    // https://gcc.gnu.org/onlinedocs/gcc/Return-Address.html
    void *parent = __builtin_extract_return_addr( __builtin_return_address(0) );

    // Retrieve the C++ function with mangled parameters
    Dl_info info_parent;
    dladdr(parent, &info_parent);
    if(info_parent.dli_sname == NULL
       || info_parent.dli_saddr == NULL) {
        // https://stackoverflow.com/questions/11731229/dladdr-doesnt-return-the-function-name
        hferr("[trapper] dladdr didn't return function name\n"
              "          Try to link with '-Wl,--export-dynamic' and compile with '-rdynamic'\n");
        exit(-1);
    }

    // Demangle the C++-symbol and extract amount of parameters as well as sizes of individual parameters
    unsigned int argc;
    unsigned int* argtypesizes;
    // https://gcc.gnu.org/onlinedocs/libstdc++/manual/ext_demangling.html
    if( hfdemangle( info_parent.dli_sname, &argc, &argtypesizes ) ) {
        hferr("[trapper] Couldn't demangle of parent 0x%016lx %s\n", parent, info_parent.dli_sname );
        exit(-1);
    }

    hfinf("[trapper] cudaLaunchKernel() [CALL] parent name=%s, argc: %d\n",
          info_parent.dli_sname, argc);

    hf_msgdescr_t header;
    HF_MSGDESCR_SET( &header,
                     HFCUDA_CUDART_cudaLaunchKernel );
    hfcheck(hfcuda_comm_send(&header, sizeof(header)));
    struct {
        size_t cxx_func_name_len;
        dim3 gridDim;
        dim3 blockDim;
        unsigned int argc;
        size_t sharedMem;
        cudaStream_t stream;
    } t2d_msg;
    t2d_msg.cxx_func_name_len = (strlen(info_parent.dli_sname) + 1) * sizeof(char);
    t2d_msg.gridDim = gridDim;
    t2d_msg.blockDim = blockDim;
    t2d_msg.argc = argc;
    t2d_msg.sharedMem = sharedMem;
    t2d_msg.stream = stream;

    // send struct
    hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));

    // send function name (ToDo: combine with arguments)
    hfcheck(hfcuda_comm_send((void*)info_parent.dli_sname, t2d_msg.cxx_func_name_len));

    uint64_t* t2d_args = (typeof(t2d_args)) malloc (argc * sizeof(t2d_args[0]));
    unsigned int i;
    for( i = 0; i < argc; ++i ) {
        // FixME: this here can be a LE / BE issue!!!
        memcpy( &t2d_args[ i ], args[ i ], argtypesizes[ i ] );
    }

    hfcheck(hfcuda_comm_send(t2d_args, argc * sizeof(t2d_args[0])));

    free( t2d_args );
    free( argtypesizes );

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));

    hfinf("[trapper] cudaLaunchKernel() [DONE] "
            "cudaError=%d\n",
            cudaError);

    return cudaSuccess;
}

//  ----------------------------------------------------------------------------

cudaError_t cudaSetupArgument(
        const void* arg,
        size_t size,
        size_t offset)
{
    int devId;
    cudaGetDevice(&devId);

    hfinf("[trapper] cudaSetupArgument() [CALL] "
            "arg=0x%016lx size=%lu offset=%lu\n",
            arg, size, offset);
    
    struct __attribute__((packed)) {
        hf_msgdescr_t header;
        struct __attribute__((packed)) {
            size_t size;
            size_t offset;
            bool isDevPtr;
            union {
                void *devptr;   // devptr only required, if ptr on device
                uintptr_t data; // otherwise start here with small arguments
            };
            uint64_t __data[7];
        } data;
    } t2d_msg;
    HF_MSGDESCR_SET( &t2d_msg.header,
                     HFCUDA_CUDART_cudaSetupArgument );
    t2d_msg.data.size = size;
    t2d_msg.data.offset = offset;
    t2d_msg.data.isDevPtr = false;

    unsigned t2d_msg_data_payload_len = sizeof(t2d_msg.data.devptr) + sizeof(t2d_msg.data.__data);

    // that's the minimum we are required to send! (includes everything until and included isDevPtr)
    unsigned t2d_msg_len = sizeof(t2d_msg) - t2d_msg_data_payload_len;

    if( size == sizeof(void*) ) { // FixME: this _could_ be a ptr, but could also be a data item with 64bit...
        void* devptr = *(void**) arg;
        hfcuda_am_node_t* mem = hfcuda_am_mem_check( devptr, devId );
        if( mem
            && (t2d_msg.data.isDevPtr = mem->isdevice) == true ) {
            t2d_msg.data.devptr = devptr;
            t2d_msg_len += sizeof(t2d_msg.data.devptr); // need to increase size!
        }
    }

    hfinf("[trapper] cudaSetupArgument() " 
            "isDevPtr=%s\n",
            t2d_msg.data.isDevPtr ? "true" : "false");

    // idea: we get a sufficient amount of stack space. (8x 64bit)
    //       if the argument supplied fits in there -> put it into message and send
    //       otherwise -> use another call to send.
    bool extra_send = false;
    if( ! t2d_msg.data.isDevPtr ) {
        if( size > t2d_msg_data_payload_len )
            extra_send = true;
        else {
            memcpy( &t2d_msg.data.data, arg, size );
            t2d_msg_len += size;
        }
    }

    hfcheck(hfcuda_comm_send(&t2d_msg, t2d_msg_len));
    
    if( extra_send )
        hfcheck(hfcuda_comm_send((void*) arg, size));

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));

    hfinf("[trapper] cudaSetupArgument() [DONE] "
            "cudaError=%d\n", cudaError);

    return cudaError;
}

//  ----------------------------------------------------------------------------


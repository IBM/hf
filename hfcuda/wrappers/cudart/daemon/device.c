// -----------------------------------------------------------------------------

// 2018-01-21 @nmimura: See trapper counterpart for comments about the
// current implementation of this wrapper.

hferr_t
    handle_HFCUDA_CUDART_cudaGetDeviceProperties(void)
{
    hfinf("[daemon] cudaGetDeviceProperties() [CALL]\n");

    cudaError_t cudaError;
    int device;
    struct cudaDeviceProp prop;

    if ((cudaError = cudaGetDevice(&device))) {
        hferr("[daemon] cudaGetDeviceProperties [ERROR] "
                "could not obtain currently active device; "
                "cudaError (%d) %s\n",
                cudaError, cudaGetErrorString(cudaError));        
    }
    else {
        cudaError =
            cudaGetDeviceProperties(
                &prop,
                device);
    }

    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));
    hfcheck(hfcuda_comm_send(&prop, sizeof(struct cudaDeviceProp)));

    hfinf("[daemon] cudaGetDeviceProperties() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t 
    handle_HFCUDA_CUDART_cudaSetDevice(void)
{
    hfinf("[daemon] cudaSetDevice() [INIT]\n");

    int device;
    hfcheck(hfcuda_comm_recv(&device, sizeof(int)));

    hfinf("[daemon] cudaSetDevice() [CALL] "
            "real_device=%d\n",
            device);

    cudaError_t cudaError = cudaSetDevice(device);
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaSetDevice() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}


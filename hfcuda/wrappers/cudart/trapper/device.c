// -----------------------------------------------------------------------------

cudaError_t
    cudaGetDevice(
        int* device)
{
    hfinf("[trapper] cudaGetDevice() [CALL]\n");

    cudaError_t cudaError = cudaSuccess;
    hfcheck(hfcuda_vdm_get_device(device));

    hfinf("[trapper] cudaGetDevice() [DONE] "
            "cudaError=%d virtual_device=%d\n",
            cudaError, *device);
    return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t
    cudaGetDeviceCount(
        int* count)
{
    hfinf("[trapper] cudaGetDeviceCount() [CALL] "
            "\n");

    cudaError_t cudaError = cudaSuccess;
    hfcheck(hfcuda_vdm_get_count(count));

    hfinf("[trapper] cudaGetDeviceCount() [DONE] "
            "cudaError=%d count=%d\n",
            cudaError, *count);
    return cudaError;
}

// -----------------------------------------------------------------------------

// 2018-01-21 @nmimura: This implementation represents a limitation
// considering the functionality to be provided by the funtion. This
// function accepts a <device> argument that indicates which device we
// want to obtain information about. However, the current threading and
// communication model creates one communicator per virtual device, and
// the utilization of these communicators is controlled via mutexes.
// Consequently, a client thread that wants to communicate to a device
// that is currently "owned" by another thread will probably have a very
// long waiting time before being able to send the call. The implementation
// below only allows using this function to retrieve information about
// the device that is currently active, i.e., which the trapper thread
// owns the mutex.
//
// The "proper" implementation would require either auxiliary
// communicators or the direct communication with the main thread that
// runs the server routine for a particular daemon (node). That would
// require further logic and protocol design to allow auxiliary calls
// to be made to this server, rather than the current implementation
// that immediately creates a handler once an incoming connection is
// established with a trapper thread.

cudaError_t
    cudaGetDeviceProperties(
        struct cudaDeviceProp* prop,
        int device)
{
    hfinf("[trapper] cudaGetDeviceProperties() [CALL] "
            "virtual_device=%d\n",
            device);

    // ToDo: this if seems to be wrong ... 
    //       why is it not allowed to provide a virtual id that is not the current real local id??
    //       I thought that's the main reason for hfcuda ...
    int current_device;
    hfcheck(cudaGetDevice(&current_device));
    if (device != current_device) {
        hferr("[trapper] cudaGetDeviceProperties() [ERROR] "
                "device requested (%d) does not match current device (%d)\n",
                device, current_device);
        return cudaErrorInvalidDevice;
    }

    hfcuda_function_t function = HFCUDA_CUDART_cudaGetDeviceProperties;
    hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));
    hfcheck(hfcuda_comm_recv(prop, sizeof(struct cudaDeviceProp)));

    hfinf("[trapper] cudaGetDeviceCount() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t
    cudaSetDevice(
        int device)
{
    hfinf("[trapper] cudaSetDevice() [CALL] "
            "virtual_device=%d\n",
            device);

    hfcheck(hfcuda_vdm_set(device));
    hfcuda_function_t function = HFCUDA_CUDART_cudaSetDevice;
    hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

    int real;
    hfcheck(hfcuda_vdm_get_real(&real));
    hfcheck(hfcuda_comm_send(&real, sizeof(int)));

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError_t)));

    hfinf("[trapper] cudaSetDevice() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return cudaError;
}


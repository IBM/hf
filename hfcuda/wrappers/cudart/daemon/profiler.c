// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaProfilerStart(void)
{
    hfinf("[daemon] cudaProfilerStart() [CALL]\n");

    cudaError_t cudaError = cudaProfilerStart();
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaProfilerStart() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t
    handle_HFCUDA_CUDART_cudaProfilerStop(void)
{
    hfinf("[daemon] cudaProfilerStop() [CALL]\n");

    cudaError_t cudaError = cudaProfilerStop();
    hfcheck(hfcuda_comm_send(&cudaError, sizeof(cudaError_t)));

    hfinf("[daemon] cudaProfilerStop() [DONE] "
            "cudaError=%d\n",
            cudaError);
    return HFOK;
}

// -----------------------------------------------------------------------------


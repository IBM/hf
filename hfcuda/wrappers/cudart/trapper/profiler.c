// -----------------------------------------------------------------------------

cudaError_t 
    cudaProfilerStart(void)
{
    hfinf("[trapper] cudaProfilerStart [CALL]\n");

    hf_msgdescr_t header;
    HF_MSGDESCR_SET( &header,
                     HFCUDA_CUDART_cudaProfilerStart );

    hfcheck(hfcuda_comm_send(&header, sizeof(header)));

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError)));
    hfinf("[trapper] cudaProfilerStart [DONE] "
            "cudaError=%d\n");
    return cudaError;
}

// -----------------------------------------------------------------------------

cudaError_t 
    cudaProfilerStop(void)
{
    hfinf("[trapper] cudaProfilerStop [CALL]\n");

    hf_msgdescr_t header;
    HF_MSGDESCR_SET( &header,
                     HFCUDA_CUDART_cudaProfilerStop );

    hfcheck(hfcuda_comm_send(&header, sizeof(header)));

    cudaError_t cudaError;
    hfcheck(hfcuda_comm_recv(&cudaError, sizeof(cudaError)));
    hfinf("[trapper] cudaProfilerStop [DONE] "
            "cudaError=%d\n");
    return cudaError;
}

// -----------------------------------------------------------------------------


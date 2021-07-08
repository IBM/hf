#include <cuda_runtime.h>
#include "hfmem.h"

int hf_mem_init( mspace* hf_gpu_mem )
{
    size_t gpu_free, gpu_total;
    cudaError_t err = cudaMemGetInfo(	&gpu_free, &gpu_total );
    if( err != cudaSuccess )
        return -1;

    void* mem;
    err = cudaMallocHost( &mem, gpu_free );
    if( err != cudaSuccess )
        return -1;

    hf_gpu_mem = create_mspace_with_base( mem, gpu_free, 1 );
    if( ! hf_gpu_mem )
        return -1;

    // Set the mspace limit to the gasnet segment size so it won't go outside.
    mspace_set_footprint_limit( hf_gpu_mem, gpu_free );

    return 0;
}


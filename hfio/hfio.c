#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cuda_runtime.h>

#include "hfio.h"

FILE* hf_cpu_fopen(
    const char* pathname,
    const char* mode)
{
  return fopen(pathname, mode);
}

size_t hf_cpu_fwrite(
    const void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream)
{
  return fwrite(ptr, size, nitems, stream);
}

size_t hf_cpu_fread(
    void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream)
{
  return fread(ptr, size, nitems, stream);
}

int hf_cpu_fclose(
    FILE* stream)
{
  return fclose(stream);
}

FILE* hf_gpu_fopen(
    const char* pathname,
    const char* mode)
{
  //printf("[hfio] hf_gpu_fopen\n");

  return fopen(pathname, mode);
}

size_t hf_gpu_fwrite(
    const void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream)
{
  //printf("[hfio] hf_gpu_fwrite\n");

  void* buffer = malloc(size * nitems);  
  cudaError_t rc;
  if ((rc = cudaMemcpy(buffer, ptr, nitems * size, cudaMemcpyDeviceToHost))) {
    fprintf(stderr, "error: hf_fio: hf_gpu_fwrite: cudaMemcpy: %s\n",
        cudaGetErrorString(rc));
    return 0;
  }

  size_t ret = fwrite(buffer, size, nitems, stream);
  if (ret < nitems) {
    fprintf(stderr, "error: hf_fio: hf_gpu_fwrite: fwrite: %d: %s\n",
        errno, strerror(errno));
    return ret;
  }

  free(buffer);
  return ret;
}

size_t hf_gpu_fread(
    void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream)
{
  //printf("[hfio] hf_gpu_fread\n");

  void* buffer = malloc(nitems * size);
  size_t ret = fread(buffer, size, nitems, stream);
  if (ret < nitems) {
    fprintf(stderr, "error: hf_fio: hf_gpu_fread: %d: %s\n",
        errno, strerror(errno));
    return ret;
  }

  cudaError_t rc;
  if ((rc = cudaMemcpy(ptr, buffer, nitems * size, cudaMemcpyHostToDevice))) {
    fprintf(stderr, "error: hf_fio: hf_gpu_fread: cudaMemcpy: %s\n",
        cudaGetErrorString(rc));
    return 0;
  }

  free(buffer);
  return ret;
}

int hf_gpu_fclose(
    FILE* stream)
{
  //printf("[hfio] hf_gpu_fclose\n");

  return fclose(stream);
}


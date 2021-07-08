#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
#endif
FILE* hf_cpu_fopen(
    const char* pathname, 
    const char* mode);

#ifdef __cplusplus
extern "C"
#endif
size_t hf_cpu_fwrite(
    const void* ptr, 
    size_t size, 
    size_t nitems,
    FILE* stream);

#ifdef __cplusplus
extern "C"
#endif
size_t hf_cpu_fread(
    void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream);

#ifdef __cplusplus
extern "C"
#endif
int hf_cpu_fclose(
    FILE* stream);

#ifdef __cplusplus
extern "C"
#endif
FILE* hf_gpu_fopen(
    const char* pathname,
    const char* mode);

#ifdef __cplusplus
extern "C"
#endif
size_t hf_gpu_fwrite(
    const void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream);

#ifdef __cplusplus
extern "C"
#endif
size_t hf_gpu_fread(
    void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream);

#ifdef __cplusplus
extern "C"
#endif
int hf_gpu_fclose(
    FILE* stream);


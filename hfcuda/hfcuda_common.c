#include <errno.h>
#include <dlfcn.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define MAX 1024*1024
struct timespec ts[MAX];
char* tl[MAX];
int tc = 0;

/*
#define clockme(str) {\
    clock_gettime(CLOCK_MONOTONIC, &ts[tc]);\
    tl[tc] = str;\
    tc++;\
}
*/
#define clockme(str) { }

__attribute__((destructor)) void clock_show()
{
    for (int i = 0; i < tc; i++) {
        if (tl[i][0] == '\0') 
            printf("\n");
        else
            printf("%ld.%09ld:%s\n", ts[i].tv_sec, ts[i].tv_nsec, tl[i]);
    }
}

#include <cuda.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <cusparse.h>
#include <driver_types.h>
#include <cuda_profiler_api.h>
#include <cudnn.h>

#include <hfcomm.h>
#include <hfenv.h>
#include <hflog.h>
#include <hfstr.h>
#include <hfdemangle.h>

#include <uthash.h>

#define HFCUDA_ENV_HOST         "HFCUDA_HOST"
#define HFCUDA_ENV_PORT         "HFCUDA_PORT"
#define HFCUDA_ENV_TYPE         "HFCUDA_COMM"
#define HFCUDA_ENV_DEVICES      "HFCUDA_DEVICES"
#define HFCUDA_ENV_APPSO        "HFCUDA_APPSO"

#define HFCUDA_DEF_HOST         "0.0.0.0"
#define HFCUDA_DEF_PORT         "10000"
#define HFCUDA_DEF_TYPE         "hfib"

#define HFCUDA_DEVICES_SEP ','
#define HFCUDA_PAIR_SEP    ':'

const char* cudaMemcpy_str[] = {
    "HtoH",
    "HtoD",
    "DtoH",
    "DtoD",
    "UVA",
};


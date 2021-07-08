#include <stdio.h>
#include <stdlib.h>

#define KB 1024
#define MB 1024 * KB
#define GB 1024 * MB

typedef enum {
    TEST_PASS,
    TEST_FAIL,
    TEST_OTHER,
} testStatus_t;

void 
    test_setup()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void
    cudaCheck(
        cudaError_t cudaError,
        testStatus_t testStatus)
{
    if (cudaError) {
        fprintf(stderr, "CUDA error at line %d: (%d) %s\n",
                __LINE__,
                cudaError,
                cudaGetErrorString(cudaError));
        exit(testStatus);
    }
}


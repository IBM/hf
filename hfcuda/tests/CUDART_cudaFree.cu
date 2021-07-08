#include "test_common.c"

int
    main()
{
    test_setup();

    size_t len = 1 * MB;
    size_t size = len * sizeof(int);
    int* hv = (int*) malloc(size);
    int *dv;

    cudaCheck(
        cudaMalloc(
            &dv,
            size),
        TEST_OTHER);

    cudaCheck(
        cudaFree(
            dv),
        TEST_FAIL);

    printf("success!\n");
    return TEST_PASS;
}


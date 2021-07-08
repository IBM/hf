#include "test_common.c"

int
    main()
{
    test_setup();

    size_t len = 1 * MB;
    size_t size = len * sizeof(float);
    float* hv = (float*) malloc(size);    
    float *dv;

    cudaCheck(
        cudaMalloc(
            &dv,
            size),
        TEST_OTHER);

    for (int i = 0; i < len; i++) {
        hv[i] = (float) i;
    }

    cudaCheck(
        cudaMemcpy(
            dv,
            hv,
            size,
            cudaMemcpyHostToDevice),
        TEST_FAIL);
    printf("HtoD done\n");

    float* rv = (float*) malloc(size);

    cudaCheck(
        cudaMemcpy(
            rv,
            dv,
            size,
            cudaMemcpyDeviceToHost),
        TEST_FAIL);
    printf("DtoH done\n");

    for (int i = 0; i < len; i++) {    
        if (rv[i] != hv[i]) {
            printf("error: mismatch rv=%lf hv=%lf\n",
                    rv[i], hv[i]);
            return TEST_FAIL;
        }
    }
    
    free(hv);
    free(rv);

    cudaCheck(
        cudaFree(
            dv),
        TEST_OTHER);

    printf("success!\n");
    return TEST_PASS;
}


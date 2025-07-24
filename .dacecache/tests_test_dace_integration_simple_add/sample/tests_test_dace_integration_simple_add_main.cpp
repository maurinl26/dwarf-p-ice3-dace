#include <cstdlib>
#include "../include/tests_test_dace_integration_simple_add.h"

int main(int argc, char **argv) {
    tests_test_dace_integration_simple_addHandle_t handle;
    int err;
    double * __restrict__ A = (double*) calloc(100, sizeof(double));
    double * __restrict__ B = (double*) calloc(100, sizeof(double));
    double * __restrict__ C = (double*) calloc(100, sizeof(double));


    handle = __dace_init_tests_test_dace_integration_simple_add();
    __program_tests_test_dace_integration_simple_add(handle, A, B, C);
    err = __dace_exit_tests_test_dace_integration_simple_add(handle);

    free(A);
    free(B);
    free(C);


    return err;
}

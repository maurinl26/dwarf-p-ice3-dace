#include <cstdlib>
#include "../include/tests_test_dace_integration_dace_operation.h"

int main(int argc, char **argv) {
    tests_test_dace_integration_dace_operationHandle_t handle;
    int err;
    double * __restrict__ A = (double*) calloc(500000, sizeof(double));
    double * __restrict__ B = (double*) calloc(500000, sizeof(double));
    double * __restrict__ C = (double*) calloc(500000, sizeof(double));


    handle = __dace_init_tests_test_dace_integration_dace_operation();
    __program_tests_test_dace_integration_dace_operation(handle, A, B, C);
    err = __dace_exit_tests_test_dace_integration_dace_operation(handle);

    free(A);
    free(B);
    free(C);


    return err;
}

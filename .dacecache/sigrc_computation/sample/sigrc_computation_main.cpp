#include <cstdlib>
#include "../include/sigrc_computation.h"

int main(int argc, char **argv) {
    sigrc_computationHandle_t handle;
    int err;
    int I = 42;
    int J = 42;
    int K = 42;
    int64_t LAMBDA3 = 42;
    double * __restrict__ q1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ sigrc = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ src_1d = (double*) calloc(34, sizeof(double));


    handle = __dace_init_sigrc_computation(I, J, K);
    __program_sigrc_computation(handle, q1, sigrc, src_1d, I, J, K, LAMBDA3);
    err = __dace_exit_sigrc_computation(handle);

    free(q1);
    free(sigrc);
    free(src_1d);


    return err;
}

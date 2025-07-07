#include <cstdlib>
#include "../include/add.h"

int main(int argc, char **argv) {
    addHandle_t handle;
    int err;
    int I = 42;
    int J = 42;
    int K = 42;
    double * __restrict__ a = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ b = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ c = (double*) calloc(((I * J) * K), sizeof(double));


    handle = __dace_init_add(I, J, K);
    __program_add(handle, a, b, c, I, J, K);
    err = __dace_exit_add(handle);

    free(a);
    free(b);
    free(c);


    return err;
}

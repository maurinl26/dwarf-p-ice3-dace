#include <cstdlib>
#include "../include/cloud_fraction_1.h"

int main(int argc, char **argv) {
    cloud_fraction_1Handle_t handle;
    int err;
    int I = 42;
    int J = 42;
    int K = 42;
    double dt = 42;
    double * __restrict__ cph = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ exnref = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ls = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ lv = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rc0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rc_tmp = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rcs0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rcs1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ri0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ri_tmp = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ris0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ris1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rvs0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rvs1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ths0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ths1 = (double*) calloc(((I * J) * K), sizeof(double));


    handle = __dace_init_cloud_fraction_1(I, J, K);
    __program_cloud_fraction_1(handle, cph, exnref, ls, lv, rc0, rc_tmp, rcs0, rcs1, ri0, ri_tmp, ris0, ris1, rvs0, rvs1, ths0, ths1, I, J, K, dt);
    err = __dace_exit_cloud_fraction_1(handle);

    free(cph);
    free(exnref);
    free(ls);
    free(lv);
    free(rc0);
    free(rc_tmp);
    free(rcs0);
    free(rcs1);
    free(ri0);
    free(ri_tmp);
    free(ris0);
    free(ris1);
    free(rvs0);
    free(rvs1);
    free(ths0);
    free(ths1);


    return err;
}

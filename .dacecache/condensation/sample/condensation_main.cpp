#include <cstdlib>
#include "../include/condensation.h"

int main(int argc, char **argv) {
    condensationHandle_t handle;
    int err;
    double ALPI = 42;
    double ALPW = 42;
    double BETAI = 42;
    double BETAW = 42;
    bool FRAC_ICE_ADJUST = 42;
    double GAMI = 42;
    double GAMW = 42;
    int I = 42;
    int J = 42;
    int K = 42;
    bool LAMBDA3 = 42;
    bool LSIGMAS = 42;
    bool LSTATNW = 42;
    bool OCND2 = 42;
    double RD = 42;
    double RV = 42;
    double TMAXMIX = 42;
    double TMINMIX = 42;
    double * __restrict__ cldfr = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ cph = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ls = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ lv = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ pabs = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rc = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rc_out = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ri = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ri_out = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rv = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rv_out = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ sigqsat = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ sigrc = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ sigs = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ t = (double*) calloc(((I * J) * K), sizeof(double));


    handle = __dace_init_condensation(FRAC_ICE_ADJUST, I, J, K, LAMBDA3);
    __program_condensation(handle, cldfr, cph, ls, lv, pabs, rc, rc_out, ri, ri_out, rv, rv_out, sigqsat, sigrc, sigs, t, ALPI, ALPW, BETAI, BETAW, FRAC_ICE_ADJUST, GAMI, GAMW, I, J, K, LAMBDA3, LSIGMAS, LSTATNW, OCND2, RD, RV, TMAXMIX, TMINMIX);
    err = __dace_exit_condensation(handle);

    free(cldfr);
    free(cph);
    free(ls);
    free(lv);
    free(pabs);
    free(rc);
    free(rc_out);
    free(ri);
    free(ri_out);
    free(rv);
    free(rv_out);
    free(sigqsat);
    free(sigrc);
    free(sigs);
    free(t);


    return err;
}

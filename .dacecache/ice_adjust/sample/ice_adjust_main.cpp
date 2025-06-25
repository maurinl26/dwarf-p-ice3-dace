#include <cstdlib>
#include "../include/ice_adjust.h"

int main(int argc, char **argv) {
    ice_adjustHandle_t handle;
    int err;
    double ALPI = 42;
    double ALPW = 42;
    double BETAI = 42;
    double BETAW = 42;
    double CI = 42;
    double CL = 42;
    double CPD = 42;
    double CPV = 42;
    double GAMI = 42;
    double GAMW = 42;
    int I = 42;
    int J = 42;
    int K = 42;
    bool LSIGMAS = 42;
    bool LSTATNW = 42;
    double LSTT = 42;
    double LVTT = 42;
    bool OCND2 = 42;
    double RD = 42;
    double RV = 42;
    double TMAXMIX = 42;
    double TMINMIX = 42;
    double TT = 42;
    double dt = 42;
    double * __restrict__ cldfr = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ exn = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ pabs = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rc0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rcs0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rcs1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rg0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ri0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ris0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ris1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rr0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rs0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rv0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rvs0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rvs1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ sigqsat = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ sigrc = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ sigs = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ th0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ths0 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ths1 = (double*) calloc(((I * J) * K), sizeof(double));


    handle = __dace_init_ice_adjust(I, J, K);
    __program_ice_adjust(handle, cldfr, exn, pabs, rc0, rcs0, rcs1, rg0, ri0, ris0, ris1, rr0, rs0, rv0, rvs0, rvs1, sigqsat, sigrc, sigs, th0, ths0, ths1, ALPI, ALPW, BETAI, BETAW, CI, CL, CPD, CPV, GAMI, GAMW, I, J, K, LSIGMAS, LSTATNW, LSTT, LVTT, OCND2, RD, RV, TMAXMIX, TMINMIX, TT, dt);
    err = __dace_exit_ice_adjust(handle);

    free(cldfr);
    free(exn);
    free(pabs);
    free(rc0);
    free(rcs0);
    free(rcs1);
    free(rg0);
    free(ri0);
    free(ris0);
    free(ris1);
    free(rr0);
    free(rs0);
    free(rv0);
    free(rvs0);
    free(rvs1);
    free(sigqsat);
    free(sigrc);
    free(sigs);
    free(th0);
    free(ths0);
    free(ths1);


    return err;
}

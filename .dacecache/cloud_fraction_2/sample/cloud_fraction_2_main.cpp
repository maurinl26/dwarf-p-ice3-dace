#include <cstdlib>
#include "../include/cloud_fraction_2.h"

int main(int argc, char **argv) {
    cloud_fraction_2Handle_t handle;
    int err;
    double ACRIAUTI = 42;
    double BCRIAUTI = 42;
    double CRIAUTC = 42;
    double CRIAUTI = 42;
    int I = 42;
    int J = 42;
    int K = 42;
    bool LSUBG_COND = 42;
    int SUBG_MF_PDF = 42;
    double TT = 42;
    double dt = 42;
    double * __restrict__ cf_mf = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ cldfr = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ cph = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ exnref = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ hlc_hcf = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ hlc_hrc = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ hli_hcf = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ hli_hri = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ls = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ lv = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rc_mf = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rcs1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rhodref = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ri_mf = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ris1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rvs1 = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ t = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ths1 = (double*) calloc(((I * J) * K), sizeof(double));


    handle = __dace_init_cloud_fraction_2(I, J, K, SUBG_MF_PDF);
    __program_cloud_fraction_2(handle, cf_mf, cldfr, cph, exnref, hlc_hcf, hlc_hrc, hli_hcf, hli_hri, ls, lv, rc_mf, rcs1, rhodref, ri_mf, ris1, rvs1, t, ths1, ACRIAUTI, BCRIAUTI, CRIAUTC, CRIAUTI, I, J, K, LSUBG_COND, SUBG_MF_PDF, TT, dt);
    err = __dace_exit_cloud_fraction_2(handle);

    free(cf_mf);
    free(cldfr);
    free(cph);
    free(exnref);
    free(hlc_hcf);
    free(hlc_hrc);
    free(hli_hcf);
    free(hli_hri);
    free(ls);
    free(lv);
    free(rc_mf);
    free(rcs1);
    free(rhodref);
    free(ri_mf);
    free(ris1);
    free(rvs1);
    free(t);
    free(ths1);


    return err;
}

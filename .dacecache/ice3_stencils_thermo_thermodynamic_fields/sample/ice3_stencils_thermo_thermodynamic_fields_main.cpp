#include <cstdlib>
#include "../include/ice3_stencils_thermo_thermodynamic_fields.h"

int main(int argc, char **argv) {
    ice3_stencils_thermo_thermodynamic_fieldsHandle_t handle;
    int err;
    double CI = 42;
    double CL = 42;
    double CPD = 42;
    double CPV = 42;
    int I = 42;
    int J = 42;
    int K = 42;
    double LSTT = 42;
    double LVTT = 42;
    double NRR = 42;
    double TT = 42;
    double * __restrict__ cph = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ exn = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ls = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ lv = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rc = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rg = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ ri = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rr = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rs = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ rv = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ t = (double*) calloc(((I * J) * K), sizeof(double));
    double * __restrict__ th = (double*) calloc(((I * J) * K), sizeof(double));


    handle = __dace_init_ice3_stencils_thermo_thermodynamic_fields(I, J, K);
    __program_ice3_stencils_thermo_thermodynamic_fields(handle, cph, exn, ls, lv, rc, rg, ri, rr, rs, rv, t, th, CI, CL, CPD, CPV, I, J, K, LSTT, LVTT, NRR, TT);
    err = __dace_exit_ice3_stencils_thermo_thermodynamic_fields(handle);

    free(cph);
    free(exn);
    free(ls);
    free(lv);
    free(rc);
    free(rg);
    free(ri);
    free(rr);
    free(rs);
    free(rv);
    free(t);
    free(th);


    return err;
}

#include <dace/dace.h>
typedef void * thermodynamic_fieldsHandle_t;
extern "C" thermodynamic_fieldsHandle_t __dace_init_thermodynamic_fields(int I, int J, int K, int NRR);
extern "C" int __dace_exit_thermodynamic_fields(thermodynamic_fieldsHandle_t handle);
extern "C" void __program_thermodynamic_fields(thermodynamic_fieldsHandle_t handle, double * __restrict__ cph, double * __restrict__ exn, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ rc, double * __restrict__ rg, double * __restrict__ ri, double * __restrict__ rr, double * __restrict__ rs, double * __restrict__ rv, double * __restrict__ t, double * __restrict__ th, double CI, double CL, double CPD, double CPV, int I, int J, int K, double LSTT, double LVTT, int NRR, double TT);

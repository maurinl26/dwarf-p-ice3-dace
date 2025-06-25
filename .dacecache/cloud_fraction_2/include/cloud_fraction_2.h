#include <dace/dace.h>
typedef void * cloud_fraction_2Handle_t;
extern "C" cloud_fraction_2Handle_t __dace_init_cloud_fraction_2(int I, int J, int K, int SUBG_MF_PDF);
extern "C" int __dace_exit_cloud_fraction_2(cloud_fraction_2Handle_t handle);
extern "C" void __program_cloud_fraction_2(cloud_fraction_2Handle_t handle, double * __restrict__ cf_mf, double * __restrict__ cldfr, double * __restrict__ cph, double * __restrict__ exnref, double * __restrict__ hlc_hcf, double * __restrict__ hlc_hrc, double * __restrict__ hli_hcf, double * __restrict__ hli_hri, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ rc_mf, double * __restrict__ rcs1, double * __restrict__ rhodref, double * __restrict__ ri_mf, double * __restrict__ ris1, double * __restrict__ rvs1, double * __restrict__ t, double * __restrict__ ths1, double ACRIAUTI, double BCRIAUTI, double CRIAUTC, double CRIAUTI, int I, int J, int K, bool LSUBG_COND, int SUBG_MF_PDF, double TT, double dt);

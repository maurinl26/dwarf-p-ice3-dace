#include <dace/dace.h>
typedef void * cloud_fraction_1Handle_t;
extern "C" cloud_fraction_1Handle_t __dace_init_cloud_fraction_1(int I, int J, int K);
extern "C" int __dace_exit_cloud_fraction_1(cloud_fraction_1Handle_t handle);
extern "C" void __program_cloud_fraction_1(cloud_fraction_1Handle_t handle, double * __restrict__ cph, double * __restrict__ exnref, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ rc0, double * __restrict__ rc_tmp, double * __restrict__ rcs0, double * __restrict__ rcs1, double * __restrict__ ri0, double * __restrict__ ri_tmp, double * __restrict__ ris0, double * __restrict__ ris1, double * __restrict__ rvs0, double * __restrict__ rvs1, double * __restrict__ ths0, double * __restrict__ ths1, int I, int J, int K, double dt);

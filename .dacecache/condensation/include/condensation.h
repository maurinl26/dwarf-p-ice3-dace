#include <dace/dace.h>
typedef void * condensationHandle_t;
extern "C" condensationHandle_t __dace_init_condensation(bool FRAC_ICE_ADJUST, int I, int J, int K, bool LAMBDA3);
extern "C" int __dace_exit_condensation(condensationHandle_t handle);
extern "C" void __program_condensation(condensationHandle_t handle, double * __restrict__ cldfr, double * __restrict__ cph, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ pabs, double * __restrict__ rc0, double * __restrict__ rc_out, double * __restrict__ ri0, double * __restrict__ ri_out, double * __restrict__ rv0, double * __restrict__ rv_out, double * __restrict__ sigqsat, double * __restrict__ sigrc, double * __restrict__ sigs, double * __restrict__ t, double ALPI, double ALPW, double BETAI, double BETAW, bool FRAC_ICE_ADJUST, double GAMI, double GAMW, int I, int J, int K, bool LAMBDA3, bool LSIGMAS, bool LSTATNW, bool OCND2, double RD, double RV, double TMAXMIX, double TMINMIX);

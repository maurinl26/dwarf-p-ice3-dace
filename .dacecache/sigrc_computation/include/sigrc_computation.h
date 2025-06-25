#include <dace/dace.h>
typedef void * sigrc_computationHandle_t;
extern "C" sigrc_computationHandle_t __dace_init_sigrc_computation(int I, int J, int K);
extern "C" int __dace_exit_sigrc_computation(sigrc_computationHandle_t handle);
extern "C" void __program_sigrc_computation(sigrc_computationHandle_t handle, double * __restrict__ q1, double * __restrict__ sigrc, double * __restrict__ src_1d, int I, int J, int K, int64_t LAMBDA3);

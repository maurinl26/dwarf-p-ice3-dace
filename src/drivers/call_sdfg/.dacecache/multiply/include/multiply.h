#include <dace/dace.h>
typedef void * multiplyHandle_t;
extern "C" multiplyHandle_t __dace_init_multiply(int I, int J, int K);
extern "C" int __dace_exit_multiply(multiplyHandle_t handle);
extern "C" void __program_multiply(multiplyHandle_t handle, float * __restrict__ __return, float * __restrict__ a, float * __restrict__ b, int I, int J, int K);

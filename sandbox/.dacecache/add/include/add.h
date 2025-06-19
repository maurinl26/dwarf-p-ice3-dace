#include <dace/dace.h>
typedef void * addHandle_t;
extern "C" addHandle_t __dace_init_add(int I, int J, int K);
extern "C" int __dace_exit_add(addHandle_t handle);
extern "C" void __program_add(addHandle_t handle, float * __restrict__ __return, float * __restrict__ a, float * __restrict__ b, int I, int J, int K);

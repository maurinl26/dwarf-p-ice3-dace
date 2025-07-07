#include <dace/dace.h>
typedef void * addHandle_t;
extern "C" addHandle_t __dace_init_add(int I, int J, int K);
extern "C" int __dace_exit_add(addHandle_t handle);
extern "C" void __program_add(addHandle_t handle, double * __restrict__ a, double * __restrict__ b, double * __restrict__ c, int I, int J, int K);

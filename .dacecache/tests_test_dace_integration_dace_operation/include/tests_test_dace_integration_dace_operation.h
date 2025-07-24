#include <dace/dace.h>
typedef void * tests_test_dace_integration_dace_operationHandle_t;
extern "C" tests_test_dace_integration_dace_operationHandle_t __dace_init_tests_test_dace_integration_dace_operation();
extern "C" int __dace_exit_tests_test_dace_integration_dace_operation(tests_test_dace_integration_dace_operationHandle_t handle);
extern "C" void __program_tests_test_dace_integration_dace_operation(tests_test_dace_integration_dace_operationHandle_t handle, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C);

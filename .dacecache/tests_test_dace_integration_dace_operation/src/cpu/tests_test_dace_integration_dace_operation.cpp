/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct tests_test_dace_integration_dace_operation_state_t {

};

void __program_tests_test_dace_integration_dace_operation_internal(tests_test_dace_integration_dace_operation_state_t*__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C)
{

    {
        double *__tmp0;
        __tmp0 = new double DACE_ALIGN(64)[500000];

        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < 100; __i0 += 1) {
                for (auto __i1 = 0; __i1 < 100; __i1 += 1) {
                    for (auto __i2 = 0; __i2 < 50; __i2 += 1) {
                        {
                            double __in1 = B[(((5000 * __i0) + (50 * __i1)) + __i2)];
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * 2.0);
                            ///////////////////

                            __tmp0[(((5000 * __i0) + (50 * __i1)) + __i2)] = __out;
                        }
                    }
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < 100; __i0 += 1) {
                for (auto __i1 = 0; __i1 < 100; __i1 += 1) {
                    for (auto __i2 = 0; __i2 < 50; __i2 += 1) {
                        {
                            double __in1 = A[(((5000 * __i0) + (50 * __i1)) + __i2)];
                            double __in2 = __tmp0[(((5000 * __i0) + (50 * __i1)) + __i2)];
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            C[(((5000 * __i0) + (50 * __i1)) + __i2)] = __out;
                        }
                    }
                }
            }
        }
        delete[] __tmp0;

    }
}

DACE_EXPORTED void __program_tests_test_dace_integration_dace_operation(tests_test_dace_integration_dace_operation_state_t *__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C)
{
    __program_tests_test_dace_integration_dace_operation_internal(__state, A, B, C);
}

DACE_EXPORTED tests_test_dace_integration_dace_operation_state_t *__dace_init_tests_test_dace_integration_dace_operation()
{
    int __result = 0;
    tests_test_dace_integration_dace_operation_state_t *__state = new tests_test_dace_integration_dace_operation_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_tests_test_dace_integration_dace_operation(tests_test_dace_integration_dace_operation_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

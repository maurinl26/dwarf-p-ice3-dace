/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct tests_test_dace_integration_simple_add_state_t {

};

void __program_tests_test_dace_integration_simple_add_internal(tests_test_dace_integration_simple_add_state_t*__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C)
{

    {

        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < 10; __i0 += 1) {
                for (auto __i1 = 0; __i1 < 10; __i1 += 1) {
                    {
                        double __in1 = A[((10 * __i0) + __i1)];
                        double __in2 = B[((10 * __i0) + __i1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        C[((10 * __i0) + __i1)] = __out;
                    }
                }
            }
        }

    }
}

DACE_EXPORTED void __program_tests_test_dace_integration_simple_add(tests_test_dace_integration_simple_add_state_t *__state, double * __restrict__ A, double * __restrict__ B, double * __restrict__ C)
{
    __program_tests_test_dace_integration_simple_add_internal(__state, A, B, C);
}

DACE_EXPORTED tests_test_dace_integration_simple_add_state_t *__dace_init_tests_test_dace_integration_simple_add()
{
    int __result = 0;
    tests_test_dace_integration_simple_add_state_t *__state = new tests_test_dace_integration_simple_add_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_tests_test_dace_integration_simple_add(tests_test_dace_integration_simple_add_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

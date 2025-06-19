/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct add_state_t {

};

void __program_add_internal(add_state_t*__state, float * __restrict__ __return, float * __restrict__ a, float * __restrict__ b, int I, int J, int K)
{

    {

        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < I; __i0 += 1) {
                for (auto __i1 = 0; __i1 < J; __i1 += 1) {
                    for (auto __i2 = 0; __i2 < K; __i2 += 1) {
                        {
                            float __in1 = a[((((J * K) * __i0) + (K * __i1)) + __i2)];
                            float __in2 = b[((((J * K) * __i0) + (K * __i1)) + __i2)];
                            float __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __return[((((J * K) * __i0) + (K * __i1)) + __i2)] = __out;
                        }
                    }
                }
            }
        }

    }
}

DACE_EXPORTED void __program_add(add_state_t *__state, float * __restrict__ __return, float * __restrict__ a, float * __restrict__ b, int I, int J, int K)
{
    __program_add_internal(__state, __return, a, b, I, J, K);
}

DACE_EXPORTED add_state_t *__dace_init_add(int I, int J, int K)
{
    int __result = 0;
    add_state_t *__state = new add_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_add(add_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

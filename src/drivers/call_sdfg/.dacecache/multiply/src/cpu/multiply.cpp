/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct multiply_state_t {

};

inline void _MatMult_bmm_sdfg_0_0_3(multiply_state_t *__state, float* __restrict__ _a, float* __restrict__ _b, float* __restrict__ _c, int I, int J, int K) {

    {

        {
            #pragma omp parallel for
            for (auto _o0 = 0; _o0 < I; _o0 += 1) {
                for (auto _o1 = 0; _o1 < J; _o1 += 1) {
                    for (auto _o2 = 0; _o2 < K; _o2 += 1) {
                        {
                            float out;

                            ///////////////////
                            // Tasklet code (batched_matmul_init)
                            out = 0;
                            ///////////////////

                            _c[((((J * K) * _o0) + (K * _o1)) + _o2)] = out;
                        }
                    }
                }
            }
        }

    }
    {

        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < I; __i0 += 1) {
                for (auto __i1 = 0; __i1 < J; __i1 += 1) {
                    for (auto __i2 = 0; __i2 < K; __i2 += 1) {
                        for (auto __i3 = 0; __i3 < K; __i3 += 1) {
                            {
                                float __a = _a[((((J * K) * __i0) + (K * __i1)) + __i3)];
                                float __b = _b[((((J * K) * __i0) + (K * __i3)) + __i2)];
                                float __c;

                                ///////////////////
                                // Tasklet code (_BatchedBatchedMatMult_)
                                __c = (__a * __b);
                                ///////////////////

                                dace::wcr_fixed<dace::ReductionType::Sum, float>::reduce_atomic(_c + ((((J * K) * __i0) + (K * __i1)) + __i2), __c);
                            }
                        }
                    }
                }
            }
        }

    }
}

void __program_multiply_internal(multiply_state_t*__state, float * __restrict__ __return, float * __restrict__ a, float * __restrict__ b, int I, int J, int K)
{

    {

        _MatMult_bmm_sdfg_0_0_3(__state, &a[0], &b[0], &__return[0], I, J, K);

    }
}

DACE_EXPORTED void __program_multiply(multiply_state_t *__state, float * __restrict__ __return, float * __restrict__ a, float * __restrict__ b, int I, int J, int K)
{
    __program_multiply_internal(__state, __return, a, b, I, J, K);
}

DACE_EXPORTED multiply_state_t *__dace_init_multiply(int I, int J, int K)
{
    int __result = 0;
    multiply_state_t *__state = new multiply_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_multiply(multiply_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

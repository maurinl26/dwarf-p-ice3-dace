/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct add_state_t {

};

void __program_add_internal(add_state_t*__state, double * __restrict__ a, double * __restrict__ b, double * __restrict__ c, int I, int J, int K)
{

    {

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        double __tmp1;
                        {
                            double __in1 = a[((((J * K) * i) + (K * j)) + k)];
                            double __in2 = b[((((J * K) * i) + (K * j)) + k)];
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __tmp1 = __out;
                        }
                        {
                            double __inp = __tmp1;
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_15_8)
                            __out = __inp;
                            ///////////////////

                            c[((((J * K) * i) + (K * j)) + k)] = __out;
                        }
                    }
                }
            }
        }

    }
}

DACE_EXPORTED void __program_add(add_state_t *__state, double * __restrict__ a, double * __restrict__ b, double * __restrict__ c, int I, int J, int K)
{
    __program_add_internal(__state, a, b, c, I, J, K);
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

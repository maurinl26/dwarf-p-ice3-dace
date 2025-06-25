/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct sigrc_computation_state_t {

};

void __program_sigrc_computation_internal(sigrc_computation_state_t*__state, double * __restrict__ q1, double * __restrict__ sigrc, double * __restrict__ src_1d, int I, int J, int K, int64_t LAMBDA3)
{


    if ((! (LAMBDA3 == 0))) {
        {

            {
                #pragma omp parallel for
                for (auto i = 0; i < I; i += 1) {
                    for (auto j = 0; j < J; j += 1) {
                        for (auto k = 0; k < K; k += 1) {
                            double sigrc_computation_20_8___tmp1;
                            double sigrc_computation_20_8___tmp2;
                            double sigrc_computation_20_8___tmp3;
                            double __tmp4;
                            double __tmp5;
                            double inq1;
                            double __tmp7;
                            double inc;
                            double __tmp9;
                            double __tmp11[34]  DACE_ALIGN(64);
                            double __tmp14[34]  DACE_ALIGN(64);
                            double __tmp15[34]  DACE_ALIGN(64);
                            double __tmp16;
                            {
                                double __in1 = q1[((((J * K) * i) + (K * j)) + k)];
                                double __out;

                                ///////////////////
                                // Tasklet code (_numpy_floor_)
                                __out = floor(__in1);
                                ///////////////////

                                sigrc_computation_20_8___tmp1 = __out;
                            }
                            {
                                double __in2 = sigrc_computation_20_8___tmp1;
                                double __out;

                                ///////////////////
                                // Tasklet code (_Mult_)
                                __out = (double(2) * __in2);
                                ///////////////////

                                sigrc_computation_20_8___tmp2 = __out;
                            }
                            {
                                double __in_b = sigrc_computation_20_8___tmp2;
                                double __out;

                                ///////////////////
                                // Tasklet code (__min2)
                                __out = min(double(-100), __in_b);
                                ///////////////////

                                sigrc_computation_20_8___tmp3 = __out;
                            }
                            {
                                double __in_b = sigrc_computation_20_8___tmp3;
                                double __out;

                                ///////////////////
                                // Tasklet code (__max2)
                                __out = max(double(-22), __in_b);
                                ///////////////////

                                __tmp4 = __out;
                            }
                            {
                                double __in_b = __tmp4;
                                double __out;

                                ///////////////////
                                // Tasklet code (__min2)
                                __out = min(double(10), __in_b);
                                ///////////////////

                                __tmp5 = __out;
                            }
                            {
                                double __in1 = __tmp5;
                                double __out;

                                ///////////////////
                                // Tasklet code (_numpy_floor_)
                                __out = floor(__in1);
                                ///////////////////

                                inq1 = __out;
                            }
                            {
                                double __in2 = q1[((((J * K) * i) + (K * j)) + k)];
                                double __out;

                                ///////////////////
                                // Tasklet code (_Mult_)
                                __out = (double(2) * __in2);
                                ///////////////////

                                __tmp7 = __out;
                            }
                            {
                                double __in1 = __tmp7;
                                double __in2 = inq1;
                                double __out;

                                ///////////////////
                                // Tasklet code (_Sub_)
                                __out = (__in1 - __in2);
                                ///////////////////

                                inc = __out;
                            }
                            {
                                double __in2 = inc;
                                double __out;

                                ///////////////////
                                // Tasklet code (_Sub_)
                                __out = (double(1) - __in2);
                                ///////////////////

                                __tmp9 = __out;
                            }
                            {
                                for (auto __i0 = 0; __i0 < 34; __i0 += 1) {
                                    {
                                        double __in1 = __tmp9;
                                        double __in2 = src_1d[__i0];
                                        double __out;

                                        ///////////////////
                                        // Tasklet code (_Mult_)
                                        __out = (__in1 * __in2);
                                        ///////////////////

                                        __tmp11[__i0] = __out;
                                    }
                                }
                            }
                            {
                                for (auto __i0 = 0; __i0 < 34; __i0 += 1) {
                                    {
                                        double __in1 = inc;
                                        double __in2 = src_1d[__i0];
                                        double __out;

                                        ///////////////////
                                        // Tasklet code (_Mult_)
                                        __out = (__in1 * __in2);
                                        ///////////////////

                                        __tmp14[__i0] = __out;
                                    }
                                }
                            }
                            {
                                for (auto __i0 = 0; __i0 < 34; __i0 += 1) {
                                    {
                                        double __in1 = __tmp11[__i0];
                                        double __in2 = __tmp14[__i0];
                                        double __out;

                                        ///////////////////
                                        // Tasklet code (_Add_)
                                        __out = (__in1 + __in2);
                                        ///////////////////

                                        __tmp15[__i0] = __out;
                                    }
                                }
                            }
                            {
                                double* __in_b = &__tmp15[0];
                                double __out;

                                ///////////////////
                                // Tasklet code (__min2)
                                __out = min(double(1), __in_b);
                                ///////////////////

                                __tmp16 = __out;
                            }
                            {
                                double __inp = __tmp16;
                                double __out;

                                ///////////////////
                                // Tasklet code (assign_26_12)
                                __out = __inp;
                                ///////////////////

                                sigrc[((((J * K) * i) + (K * j)) + k)] = __out;
                            }
                        }
                    }
                }
            }

        }

    } else {
        {

            {
                #pragma omp parallel for
                for (auto i = 0; i < I; i += 1) {
                    for (auto j = 0; j < J; j += 1) {
                        for (auto k = 0; k < K; k += 1) {
                            double __tmp1;
                            double __tmp2;
                            double __tmp3;
                            {
                                double __in2 = q1[((((J * K) * i) + (K * j)) + k)];
                                double __out;

                                ///////////////////
                                // Tasklet code (_Sub_)
                                __out = (double(1) - __in2);
                                ///////////////////

                                __tmp1 = __out;
                            }
                            {
                                double __in_b = __tmp1;
                                double __out;

                                ///////////////////
                                // Tasklet code (__max2)
                                __out = max(double(1), __in_b);
                                ///////////////////

                                __tmp2 = __out;
                            }
                            {
                                double __in_b = __tmp2;
                                double __out;

                                ///////////////////
                                // Tasklet code (__min2)
                                __out = min(double(3), __in_b);
                                ///////////////////

                                __tmp3 = __out;
                            }
                            {
                                double __inp = __tmp3;
                                double __out;

                                ///////////////////
                                // Tasklet code (assign_17_12)
                                __out = __inp;
                                ///////////////////

                                dace::wcr_fixed<dace::ReductionType::Product, double>::reduce(sigrc + ((((J * K) * i) + (K * j)) + k), __out);
                            }
                        }
                    }
                }
            }

        }

    }

}

DACE_EXPORTED void __program_sigrc_computation(sigrc_computation_state_t *__state, double * __restrict__ q1, double * __restrict__ sigrc, double * __restrict__ src_1d, int I, int J, int K, int64_t LAMBDA3)
{
    __program_sigrc_computation_internal(__state, q1, sigrc, src_1d, I, J, K, LAMBDA3);
}

DACE_EXPORTED sigrc_computation_state_t *__dace_init_sigrc_computation(int I, int J, int K)
{
    int __result = 0;
    sigrc_computation_state_t *__state = new sigrc_computation_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_sigrc_computation(sigrc_computation_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct cloud_fraction_1_state_t {

};

inline void cloud_fraction_1_32_4_0_0_2(cloud_fraction_1_state_t *__state, const double&  __tmp_34_14_r, const double&  __tmp_34_32_r, const double&  __tmp_34_48_r, const double&  __tmp_35_14_r, const double&  __tmp_35_32_r, const double&  __tmp_39_26_r, const double&  __tmp_41_25_r, const double&  __tmp_44_30_r, const double&  __tmp_44_45_r, const double&  __tmp_44_60_r, const double&  __tmp_47_26_r, const double&  __tmp_52_24_r, const double&  __tmp_52_45_r, double&  __tmp_42_8_w, double&  __tmp_43_8_w, double&  __tmp_44_8_w, double&  __tmp_51_8_w) {
    double __tmp6;
    double __tmp12;
    double __tmp1;
    double w1;
    double __tmp3;
    double w2;
    double __tmp13;
    double __tmp7;


    __tmp1 = (__tmp_34_14_r - __tmp_34_32_r);

    w1 = (__tmp1 / __tmp_34_48_r);
    __tmp3 = (__tmp_35_14_r - __tmp_35_32_r);

    w2 = (__tmp3 / __tmp_34_48_r);

    if ((w1 < 0.0)) {
        {
            double __tmp5;

            {
                double __in = __tmp_39_26_r;
                double __out;

                ///////////////////
                // Tasklet code (_USub_)
                __out = (- __in);
                ///////////////////

                __tmp5 = __out;
            }
            {
                double __in_b = __tmp5;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(w1, __in_b);
                ///////////////////

                __tmp6 = __out;
            }

        }
        w1 = __tmp6;

    } else {

        __tmp7 = min(w1, __tmp_41_25_r);

        w1 = __tmp7;

    }
    {
        double __tmp8;
        double __tmp9;
        double __tmp10;

        {
            double __out;

            ///////////////////
            // Tasklet code (assign_42_8)
            __out = w1;
            ///////////////////

            dace::wcr_custom<double>:: template reduce([] (const double& x, const double& y) { return (x - y); }, &__tmp_42_8_w, __out);
        }
        {
            double __out;

            ///////////////////
            // Tasklet code (assign_43_8)
            __out = w1;
            ///////////////////

            dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_43_8_w, __out);
        }
        {
            double __in2 = __tmp_44_30_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (w1 * __in2);
            ///////////////////

            __tmp8 = __out;
        }
        {
            double __in1 = __tmp_44_45_r;
            double __in2 = __tmp_44_60_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp9 = __out;
        }
        {
            double __in1 = __tmp8;
            double __in2 = __tmp9;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp10 = __out;
        }
        {
            double __inp = __tmp10;
            double __out;

            ///////////////////
            // Tasklet code (assign_44_8)
            __out = __inp;
            ///////////////////

            dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_44_8_w, __out);
        }

    }
    if ((w2 < 0.0)) {
        {
            double __tmp11;

            {
                double __in = __tmp_47_26_r;
                double __out;

                ///////////////////
                // Tasklet code (_USub_)
                __out = (- __in);
                ///////////////////

                __tmp11 = __out;
            }
            {
                double __in_b = __tmp11;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(w2, __in_b);
                ///////////////////

                __tmp12 = __out;
            }

        }
        w2 = __tmp12;

    } else {

        __tmp13 = min(w2, __tmp_41_25_r);

        w2 = __tmp13;

    }
    {
        double __tmp14;
        double __tmp15;
        double __tmp16;
        double __tmp17;
        double __tmp18;
        double __tmp19;

        {
            double __in1 = __tmp_41_25_r;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + w2);
            ///////////////////

            __tmp14 = __out;
        }
        {
            double __inp = __tmp14;
            double __out;

            ///////////////////
            // Tasklet code (assign_50_8)
            __out = __inp;
            ///////////////////

            __tmp_42_8_w = __out;
        }
        {
            double __in1 = __tmp_47_26_r;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + w2);
            ///////////////////

            __tmp15 = __out;
        }
        {
            double __inp = __tmp15;
            double __out;

            ///////////////////
            // Tasklet code (assign_51_8)
            __out = __inp;
            ///////////////////

            __tmp_51_8_w = __out;
        }
        {
            double __in2 = __tmp_52_45_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (w2 * __in2);
            ///////////////////

            __tmp16 = __out;
        }
        {
            double __in1 = __tmp_44_45_r;
            double __in2 = __tmp_44_60_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp17 = __out;
        }
        {
            double __in1 = __tmp16;
            double __in2 = __tmp17;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp18 = __out;
        }
        {
            double __in1 = __tmp_52_24_r;
            double __in2 = __tmp18;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp19 = __out;
        }
        {
            double __inp = __tmp19;
            double __out;

            ///////////////////
            // Tasklet code (assign_52_8)
            __out = __inp;
            ///////////////////

            __tmp_44_8_w = __out;
        }

    }
}

void __program_cloud_fraction_1_internal(cloud_fraction_1_state_t*__state, double * __restrict__ cph, double * __restrict__ exnref, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ rc0, double * __restrict__ rc_tmp, double * __restrict__ rcs0, double * __restrict__ rcs1, double * __restrict__ ri0, double * __restrict__ ri_tmp, double * __restrict__ ris0, double * __restrict__ ris1, double * __restrict__ rvs0, double * __restrict__ rvs1, double * __restrict__ ths0, double * __restrict__ ths1, int I, int J, int K, double dt)
{

    {

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        cloud_fraction_1_32_4_0_0_2(__state, rc_tmp[((((J * K) * i) + (K * j)) + k)], rc0[((((J * K) * i) + (K * j)) + k)], dt, ri_tmp[((((J * K) * i) + (K * j)) + k)], ri0[((((J * K) * i) + (K * j)) + k)], rcs0[((((J * K) * i) + (K * j)) + k)], rvs0[((((J * K) * i) + (K * j)) + k)], lv[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], exnref[((((J * K) * i) + (K * j)) + k)], ris0[((((J * K) * i) + (K * j)) + k)], ths0[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)], rvs1[((((J * K) * i) + (K * j)) + k)], rcs1[((((J * K) * i) + (K * j)) + k)], ths1[((((J * K) * i) + (K * j)) + k)], ris1[((((J * K) * i) + (K * j)) + k)]);
                    }
                }
            }
        }

    }
}

DACE_EXPORTED void __program_cloud_fraction_1(cloud_fraction_1_state_t *__state, double * __restrict__ cph, double * __restrict__ exnref, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ rc0, double * __restrict__ rc_tmp, double * __restrict__ rcs0, double * __restrict__ rcs1, double * __restrict__ ri0, double * __restrict__ ri_tmp, double * __restrict__ ris0, double * __restrict__ ris1, double * __restrict__ rvs0, double * __restrict__ rvs1, double * __restrict__ ths0, double * __restrict__ ths1, int I, int J, int K, double dt)
{
    __program_cloud_fraction_1_internal(__state, cph, exnref, ls, lv, rc0, rc_tmp, rcs0, rcs1, ri0, ri_tmp, ris0, ris1, rvs0, rvs1, ths0, ths1, I, J, K, dt);
}

DACE_EXPORTED cloud_fraction_1_state_t *__dace_init_cloud_fraction_1(int I, int J, int K)
{
    int __result = 0;
    cloud_fraction_1_state_t *__state = new cloud_fraction_1_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_cloud_fraction_1(cloud_fraction_1_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct thermodynamic_fields_state_t {

};

inline void thermodynamic_fields_34_4_0_0_2(thermodynamic_fields_state_t *__state, const double&  __tmp_35_21_r, const double&  __tmp_35_36_r, const double&  __tmp_36_33_r, const double&  __tmp_36_63_r, const double&  __tmp_36_73_r, const double&  __tmp_36_81_r, const double&  __tmp_36_88_r, const double&  __tmp_37_32_r, const double&  __tmp_37_63_r, const double&  __tmp_37_81_r, double&  __tmp_35_8_w) {
    char __tmp10;
    char __tmp11;
    char __tmp18;
    char __tmp19;
    char __tmp2;
    char __tmp2_0;

    {
        double __tmp1;

        {
            double __in1 = __tmp_35_21_r;
            double __in2 = __tmp_35_36_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp1 = __out;
        }
        {
            double __inp = __tmp1;
            double __out;

            ///////////////////
            // Tasklet code (assign_35_8)
            __out = __inp;
            ///////////////////

            __tmp_35_8_w = __out;
        }
        {
            double __in1 = __tmp_36_73_r;
            double __in2 = __tmp_36_81_r;
            char __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (char(__in1) - char(__in2));
            ///////////////////

            __tmp10 = __out;
        }
        {
            double __in1 = __tmp_36_33_r;
            double __in2 = __tmp_36_88_r;
            char __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (char(__in1) - char(__in2));
            ///////////////////

            __tmp11 = __out;
        }

    }
    __tmp2 = (__tmp10 * __tmp11);
    {
        char __tmp3;

        {
            double __in1 = __tmp_36_63_r;
            char __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (char(__in1) + __tmp2);
            ///////////////////

            __tmp3 = __out;
        }
        {
            char __inp = __tmp3;
            double __out;

            ///////////////////
            // Tasklet code (assign_25_4)
            __out = __inp;
            ///////////////////

            __tmp_35_8_w = __out;
        }
        {
            double __in1 = __tmp_36_73_r;
            double __in2 = __tmp_37_81_r;
            char __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (char(__in1) - char(__in2));
            ///////////////////

            __tmp18 = __out;
        }
        {
            double __in1 = __tmp_37_32_r;
            double __in2 = __tmp_36_88_r;
            char __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (char(__in1) - char(__in2));
            ///////////////////

            __tmp19 = __out;
        }

    }
    __tmp2_0 = (__tmp18 * __tmp19);
    {
        char __tmp20;

        {
            double __in1 = __tmp_37_63_r;
            char __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (char(__in1) + __tmp2_0);
            ///////////////////

            __tmp20 = __out;
        }
        {
            char __inp = __tmp20;
            double __out;

            ///////////////////
            // Tasklet code (assign_45_4)
            __out = __inp;
            ///////////////////

            __tmp_35_8_w = __out;
        }

    }
}

inline void thermodynamic_fields_40_4_0_0_16(thermodynamic_fields_state_t *__state, const double&  __tmp_42_108_r, const double&  __tmp_42_122_r, const double&  __tmp_42_27_r, const double&  __tmp_42_33_r, const double&  __tmp_42_39_r, const double&  __tmp_42_53_r, const double&  __tmp_42_59_r, const double&  __tmp_42_73_r, const double&  __tmp_42_88_r, const double&  __tmp_42_94_r, double&  __tmp_42_12_w, int64_t NRR) {


    if ((NRR == 6)) {
        {
            double __tmp1;
            double __tmp2;
            double __tmp3;
            double __tmp4;
            double __tmp5;
            double __tmp6;
            double __tmp7;
            double __tmp8;
            double __tmp9;

            {
                double __in1 = __tmp_42_33_r;
                double __in2 = __tmp_42_39_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp1 = __out;
            }
            {
                double __in1 = __tmp_42_27_r;
                double __in2 = __tmp1;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp2 = __out;
            }
            {
                double __in1 = __tmp_42_59_r;
                double __in2 = __tmp_42_73_r;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp3 = __out;
            }
            {
                double __in1 = __tmp_42_53_r;
                double __in2 = __tmp3;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp4 = __out;
            }
            {
                double __in2 = __tmp4;
                double __in1 = __tmp2;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp5 = __out;
            }
            {
                double __in1 = __tmp_42_94_r;
                double __in2 = __tmp_42_108_r;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp6 = __out;
            }
            {
                double __in2 = __tmp_42_122_r;
                double __in1 = __tmp6;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp7 = __out;
            }
            {
                double __in1 = __tmp_42_88_r;
                double __in2 = __tmp7;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp8 = __out;
            }
            {
                double __in2 = __tmp8;
                double __in1 = __tmp5;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp9 = __out;
            }
            {
                double __inp = __tmp9;
                double __out;

                ///////////////////
                // Tasklet code (assign_42_12)
                __out = __inp;
                ///////////////////

                __tmp_42_12_w = __out;
            }

        }

    }

    if ((NRR == 5)) {
        {
            double __tmp10;
            double __tmp11;
            double __tmp12;
            double __tmp13;
            double __tmp14;
            double __tmp15;
            double __tmp16;
            double __tmp17;

            {
                double __in1 = __tmp_42_33_r;
                double __in2 = __tmp_42_39_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp10 = __out;
            }
            {
                double __in1 = __tmp_42_27_r;
                double __in2 = __tmp10;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp11 = __out;
            }
            {
                double __in1 = __tmp_42_59_r;
                double __in2 = __tmp_42_73_r;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp12 = __out;
            }
            {
                double __in1 = __tmp_42_53_r;
                double __in2 = __tmp12;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp13 = __out;
            }
            {
                double __in2 = __tmp13;
                double __in1 = __tmp11;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp14 = __out;
            }
            {
                double __in1 = __tmp_42_94_r;
                double __in2 = __tmp_42_108_r;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp15 = __out;
            }
            {
                double __in1 = __tmp_42_88_r;
                double __in2 = __tmp15;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp16 = __out;
            }
            {
                double __in1 = __tmp14;
                double __in2 = __tmp16;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp17 = __out;
            }
            {
                double __inp = __tmp17;
                double __out;

                ///////////////////
                // Tasklet code (assign_44_12)
                __out = __inp;
                ///////////////////

                __tmp_42_12_w = __out;
            }

        }

    }

    if ((NRR == 4)) {
        {
            double __tmp18;
            double __tmp19;
            double __tmp20;
            double __tmp21;
            double __tmp22;

            {
                double __in1 = __tmp_42_33_r;
                double __in2 = __tmp_42_39_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp18 = __out;
            }
            {
                double __in1 = __tmp_42_27_r;
                double __in2 = __tmp18;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp19 = __out;
            }
            {
                double __in1 = __tmp_42_59_r;
                double __in2 = __tmp_42_73_r;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp20 = __out;
            }
            {
                double __in1 = __tmp_42_53_r;
                double __in2 = __tmp20;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp21 = __out;
            }
            {
                double __in2 = __tmp21;
                double __in1 = __tmp19;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp22 = __out;
            }
            {
                double __inp = __tmp22;
                double __out;

                ///////////////////
                // Tasklet code (assign_46_12)
                __out = __inp;
                ///////////////////

                __tmp_42_12_w = __out;
            }

        }

    }

    if ((NRR == 2)) {
        {
            double __tmp23;
            double __tmp24;
            double __tmp25;
            double __tmp26;
            double __tmp27;
            double __tmp28;

            {
                double __in1 = __tmp_42_33_r;
                double __in2 = __tmp_42_39_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp23 = __out;
            }
            {
                double __in1 = __tmp_42_27_r;
                double __in2 = __tmp23;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp24 = __out;
            }
            {
                double __in1 = __tmp_42_53_r;
                double __in2 = __tmp_42_59_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp25 = __out;
            }
            {
                double __in1 = __tmp24;
                double __in2 = __tmp25;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp26 = __out;
            }
            {
                double __in1 = __tmp_42_88_r;
                double __in2 = __tmp_42_94_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp27 = __out;
            }
            {
                double __in1 = __tmp26;
                double __in2 = __tmp27;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp28 = __out;
            }
            {
                double __inp = __tmp28;
                double __out;

                ///////////////////
                // Tasklet code (assign_48_12)
                __out = __inp;
                ///////////////////

                __tmp_42_12_w = __out;
            }

        }

    }

}

void __program_thermodynamic_fields_internal(thermodynamic_fields_state_t*__state, double * __restrict__ cph, double * __restrict__ exn, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ rc, double * __restrict__ rg, double * __restrict__ ri, double * __restrict__ rr, double * __restrict__ rs, double * __restrict__ rv, double * __restrict__ t, double * __restrict__ th, double CI, double CL, double CPD, double CPV, int I, int J, int K, double LSTT, double LVTT, int NRR, double TT)
{

    {

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        thermodynamic_fields_34_4_0_0_2(__state, exn[((((J * K) * i) + (K * j)) + k)], th[((((J * K) * i) + (K * j)) + k)], lv[((((J * K) * i) + (K * j)) + k)], LVTT, CPV, CL, TT, ls[((((J * K) * i) + (K * j)) + k)], LSTT, CI, t[((((J * K) * i) + (K * j)) + k)]);
                    }
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        thermodynamic_fields_40_4_0_0_16(__state, rs[((((J * K) * i) + (K * j)) + k)], rg[((((J * K) * i) + (K * j)) + k)], CPD, CPV, rv[((((J * K) * i) + (K * j)) + k)], CL, rc[((((J * K) * i) + (K * j)) + k)], rr[((((J * K) * i) + (K * j)) + k)], CI, ri[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], NRR);
                    }
                }
            }
        }

    }
}

DACE_EXPORTED void __program_thermodynamic_fields(thermodynamic_fields_state_t *__state, double * __restrict__ cph, double * __restrict__ exn, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ rc, double * __restrict__ rg, double * __restrict__ ri, double * __restrict__ rr, double * __restrict__ rs, double * __restrict__ rv, double * __restrict__ t, double * __restrict__ th, double CI, double CL, double CPD, double CPV, int I, int J, int K, double LSTT, double LVTT, int NRR, double TT)
{
    __program_thermodynamic_fields_internal(__state, cph, exn, ls, lv, rc, rg, ri, rr, rs, rv, t, th, CI, CL, CPD, CPV, I, J, K, LSTT, LVTT, NRR, TT);
}

DACE_EXPORTED thermodynamic_fields_state_t *__dace_init_thermodynamic_fields(int I, int J, int K, int NRR)
{
    int __result = 0;
    thermodynamic_fields_state_t *__state = new thermodynamic_fields_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_thermodynamic_fields(thermodynamic_fields_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct ice_adjust_state_t {

};

inline void ice3_stencils_thermo_thermodynamic_fields_34_4_0_0_2(ice_adjust_state_t *__state, const double&  __tmp_35_21_r, const double&  __tmp_35_36_r, const double&  __tmp_36_33_r, const double&  __tmp_36_63_r, const double&  __tmp_36_73_r, const double&  __tmp_36_81_r, const double&  __tmp_36_88_r, const double&  __tmp_37_32_r, const double&  __tmp_37_63_r, const double&  __tmp_37_81_r, double&  __tmp_35_8_w) {
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

inline void ice3_stencils_condensation_split_condensation_58_4_0_1_2(ice_adjust_state_t *__state, const double&  __tmp_101_14_r, const double&  __tmp_101_19_r, const double&  __tmp_106_31_r, const double&  __tmp_106_56_r, const double&  __tmp_110_27_r, const bool&  __tmp_117_11_r, const bool&  __tmp_117_27_r, const double&  __tmp_121_25_r, const double&  __tmp_122_23_r, const double&  __tmp_63_22_r, const double&  __tmp_63_37_r, const double&  __tmp_63_52_r, const bool&  __tmp_66_15_r, const double&  __tmp_67_20_r, const double&  __tmp_67_45_r, const double&  __tmp_67_51_r, const double&  __tmp_67_58_r, const double&  __tmp_70_19_r, const double&  __tmp_73_20_r, const double&  __tmp_73_46_r, const double&  __tmp_73_52_r, const double&  __tmp_73_59_r, const double&  __tmp_93_37_r, const double&  __tmp_93_72_r, double&  __tmp_146_16_w, double&  __tmp_157_16_w, double&  __tmp_158_16_w, double&  __tmp_166_12_w, double&  __tmp_67_33_w, double&  __tmp_68_12_w, double&  __tmp_74_12_w) {
    double __tmp_63_8_w;
    double __tmp40;
    double __tmp45;
    double __tmp96;
    double __tmp97;
    double __tmp103;
    double __tmp107;
    double qsl;
    double a;
    double sbar;
    int64_t frac_tmp;
    bool __tmp9;
    bool __tmp36;
    int64_t __tmp56;
    int64_t __tmp60;
    int64_t q1;
    int64_t sigma;
    bool __tmp87;
    bool __tmp88;
    double cond_tmp;
    bool __tmp114;
    bool __tmp115;
    double __tmp37;


    frac_tmp = 0;
    __tmp9 = (! __tmp_66_15_r);
    {
        double __tmp6;
        double __tmp7;
        double __tmp8;

        {
            double __in1 = __tmp_63_22_r;
            double __in2 = __tmp_63_37_r;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp6 = __out;
        }
        {
            double __in1 = __tmp_63_52_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * double(1));
            ///////////////////

            __tmp7 = __out;
        }
        {
            double __in2 = __tmp7;
            double __in1 = __tmp6;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp8 = __out;
        }
        {
            double __inp = __tmp8;
            double __out;

            ///////////////////
            // Tasklet code (assign_63_8)
            __out = __inp;
            ///////////////////

            __tmp_63_8_w = __out;
        }

    }
    if (__tmp9) {
        {
            double __tmp15;
            double __tmp16;
            double __tmp17;
            double __tmp18;
            double __tmp19;
            double __tmp20;

            {
                double __in1 = __tmp_67_51_r;
                double __in2 = __tmp_67_20_r;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp15 = __out;
            }
            {
                double __in1 = __tmp_67_20_r;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_log_)
                __out = log(__in1);
                ///////////////////

                __tmp17 = __out;
            }
            {
                double __in1 = __tmp_67_45_r;
                double __in2 = __tmp15;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp16 = __out;
            }
            {
                double __in1 = __tmp_67_58_r;
                double __in2 = __tmp17;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp18 = __out;
            }
            {
                double __in2 = __tmp18;
                double __in1 = __tmp16;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp19 = __out;
            }
            {
                double __in1 = __tmp19;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_exp_)
                __out = exp(__in1);
                ///////////////////

                __tmp20 = __out;
            }
            {
                double __inp = __tmp20;
                double __out;

                ///////////////////
                // Tasklet code (assign_24_4)
                __out = __inp;
                ///////////////////

                __tmp_67_33_w = __out;
            }

        }
        {
            double __tmp21;
            double __tmp22;
            double __tmp34;
            double __tmp35;
            double __tmp28;
            double __tmp29;
            double __tmp30;
            double __tmp31;
            double __tmp32;
            double __tmp33;

            {
                double __in2 = __tmp_70_19_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (0.99 * __in2);
                ///////////////////

                __tmp21 = __out;
            }
            {
                double __in_a = __tmp_67_20_r;
                double __in_b = __tmp21;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(__in_a, __in_b);
                ///////////////////

                __tmp22 = __out;
            }
            {
                double __inp = __tmp22;
                double __out;

                ///////////////////
                // Tasklet code (assign_68_12)
                __out = __inp;
                ///////////////////

                __tmp_68_12_w = __out;
            }
            {
                double __in2 = __tmp_70_19_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (0.99 * __in2);
                ///////////////////

                __tmp34 = __out;
            }
            {
                double __in_b = __tmp34;
                double __in_a = __tmp_73_20_r;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(__in_a, __in_b);
                ///////////////////

                __tmp35 = __out;
            }
            {
                double __inp = __tmp35;
                double __out;

                ///////////////////
                // Tasklet code (assign_74_12)
                __out = __inp;
                ///////////////////

                __tmp_74_12_w = __out;
            }
            {
                double __in1 = __tmp_73_52_r;
                double __in2 = __tmp_73_20_r;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp28 = __out;
            }
            {
                double __in1 = __tmp_73_20_r;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_log_)
                __out = log(__in1);
                ///////////////////

                __tmp30 = __out;
            }
            {
                double __in1 = __tmp_73_46_r;
                double __in2 = __tmp28;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp29 = __out;
            }
            {
                double __in1 = __tmp_73_59_r;
                double __in2 = __tmp30;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp31 = __out;
            }
            {
                double __in2 = __tmp31;
                double __in1 = __tmp29;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp32 = __out;
            }
            {
                double __in1 = __tmp32;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_exp_)
                __out = exp(__in1);
                ///////////////////

                __tmp33 = __out;
            }
            {
                double __inp = __tmp33;
                double __out;

                ///////////////////
                // Tasklet code (assign_44_4)
                __out = __inp;
                ///////////////////

                __tmp_67_33_w = __out;
            }

        }
        __tmp36 = (! __tmp_66_15_r);

    } else {

        __tmp36 = (! __tmp_66_15_r);

    }

    if ((! __tmp36)) {

        __tmp56 = (1 - 0);
        __tmp60 = (1 - 0);
        q1 = 0;
        sigma = 0;
        __tmp87 = (! __tmp_117_27_r);

    } else {

        __tmp37 = (__tmp_63_37_r + __tmp_63_52_r);

        if ((__tmp37 > 1e-20)) {
            {
                double __tmp39;

                {
                    double __in1 = __tmp_63_37_r;
                    double __in2 = __tmp_63_52_r;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp39 = __out;
                }
                {
                    double __in1 = __tmp_63_37_r;
                    double __in2 = __tmp39;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Div_)
                    __out = (__in1 / __in2);
                    ///////////////////

                    __tmp40 = __out;
                }

            }
            frac_tmp = __tmp40;

        } else {

            frac_tmp = 0;

        }
        {
            double __tmp41;
            double __tmp42;
            double __tmp43;
            double __tmp44;

            {
                double __in1 = __tmp_93_37_r;
                double __in2 = __tmp_67_33_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp41 = __out;
            }
            {
                double __in2 = __tmp_93_72_r;
                double __in1 = __tmp_93_37_r;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp42 = __out;
            }
            {
                double __in2 = __tmp42;
                double __in1 = __tmp41;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp43 = __out;
            }
            {
                double __in_b = __tmp43;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(double(1), __in_b);
                ///////////////////

                __tmp44 = __out;
            }
            {
                double __in_b = __tmp44;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(double(0), __in_b);
                ///////////////////

                __tmp45 = __out;
            }

        }
        frac_tmp = __tmp45;

        __tmp56 = (1 - frac_tmp);
        __tmp60 = (1 - frac_tmp);
        q1 = 0;
        sigma = 0;
        __tmp87 = (! __tmp_117_27_r);

    }
    {
        double __tmp48;
        double __tmp49;
        double __tmp50;
        double __tmp52;
        double __tmp53;
        double __tmp54;
        double __tmp57;
        double __tmp58;
        double __tmp59;
        double __tmp61;
        double __tmp62;
        double __tmp64;
        double __tmp65;
        double __tmp66;
        double __tmp67;
        double __tmp68;
        double __tmp69;
        double __tmp70;
        double __tmp72;
        double __tmp73;
        double __tmp74;
        double __tmp77;
        double __tmp78;
        double __tmp79;
        double __tmp80;
        double __tmp81;
        double __tmp82;
        double __tmp83;
        double qsi;
        double lvs;
        double ah;

        {
            double __in1 = __tmp_101_14_r;
            double __in2 = __tmp_101_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp48 = __out;
        }
        {
            double __in1 = __tmp_101_14_r;
            double __in2 = __tmp_101_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp52 = __out;
        }
        {
            double __in2 = __tmp_68_12_w;
            double __in1 = __tmp48;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp49 = __out;
        }
        {
            double __in1 = __tmp_70_19_r;
            double __in2 = __tmp_68_12_w;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp50 = __out;
        }
        {
            double __in2 = __tmp50;
            double __in1 = __tmp49;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            qsl = __out;
        }
        {
            double __in2 = qsl;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (double(__tmp56) * __in2);
            ///////////////////

            __tmp57 = __out;
        }
        {
            double __in2 = __tmp_74_12_w;
            double __in1 = __tmp52;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp53 = __out;
        }
        {
            double __in2 = __tmp_74_12_w;
            double __in1 = __tmp_70_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp54 = __out;
        }
        {
            double __in2 = __tmp54;
            double __in1 = __tmp53;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            qsi = __out;
        }
        {
            double __in2 = qsi;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (double(frac_tmp) * __in2);
            ///////////////////

            __tmp58 = __out;
        }
        {
            double __in2 = __tmp58;
            double __in1 = __tmp57;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp59 = __out;
        }
        {
            double __inp = __tmp59;
            double __out;

            ///////////////////
            // Tasklet code (assign_105_8)
            __out = __inp;
            ///////////////////

            qsl = __out;
        }
        {
            double __in2 = qsl;
            double __in1 = __tmp_101_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp68 = __out;
        }
        {
            double __in1 = __tmp68;
            double __in2 = __tmp_101_14_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp69 = __out;
        }
        {
            double __in2 = __tmp69;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (double(1) + __in2);
            ///////////////////

            __tmp70 = __out;
        }
        {
            double __in2 = __tmp_106_31_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (double(__tmp60) * __in2);
            ///////////////////

            __tmp61 = __out;
        }
        {
            double __in2 = __tmp_106_56_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (double(frac_tmp) * __in2);
            ///////////////////

            __tmp62 = __out;
        }
        {
            double __in2 = __tmp62;
            double __in1 = __tmp61;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            lvs = __out;
        }
        {
            double __in1 = lvs;
            double __in2 = qsl;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp64 = __out;
        }
        {
            double __in1 = __tmp_67_33_w;
            double __out;

            ///////////////////
            // Tasklet code (_Pow_)
            __out = (dace::math::ipow(__in1, 2));
            ///////////////////

            __tmp65 = __out;
        }
        {
            double __in2 = __tmp65;
            double __in1 = __tmp_101_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp66 = __out;
        }
        {
            double __in2 = __tmp66;
            double __in1 = __tmp64;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp67 = __out;
        }
        {
            double __in2 = __tmp70;
            double __in1 = __tmp67;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            ah = __out;
        }
        {
            double __in1 = ah;
            double __in2 = lvs;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp78 = __out;
        }
        {
            double __in2 = __tmp_110_27_r;
            double __in1 = lvs;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp72 = __out;
        }
        {
            double __in1 = __tmp72;
            double __in2 = ah;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp73 = __out;
        }
        {
            double __in2 = __tmp73;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (double(1) + __in2);
            ///////////////////

            __tmp74 = __out;
        }
        {
            double __in2 = __tmp74;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (double(1) / __in2);
            ///////////////////

            a = __out;
        }
        {
            double __in1 = __tmp_63_8_w;
            double __in2 = qsl;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp77 = __out;
        }
        {
            double __in1 = __tmp_63_52_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * double(1));
            ///////////////////

            __tmp79 = __out;
        }
        {
            double __in1 = __tmp_63_37_r;
            double __in2 = __tmp79;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp80 = __out;
        }
        {
            double __in2 = __tmp80;
            double __in1 = __tmp78;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp81 = __out;
        }
        {
            double __in1 = __tmp81;
            double __in2 = __tmp_110_27_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp82 = __out;
        }
        {
            double __in2 = __tmp82;
            double __in1 = __tmp77;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp83 = __out;
        }
        {
            double __in2 = __tmp83;
            double __in1 = a;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            sbar = __out;
        }

    }
    __tmp88 = (__tmp_117_11_r && __tmp87);

    if (__tmp88) {
        {
            double __tmp89;
            double __tmp90;
            double __tmp91;
            double __tmp92;
            double __tmp93;
            double __tmp94;
            double __tmp95;

            {
                double __in2 = __tmp_121_25_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double(2) * __in2);
                ///////////////////

                __tmp89 = __out;
            }
            {
                double __in1 = __tmp89;
                double __out;

                ///////////////////
                // Tasklet code (_Pow_)
                __out = (dace::math::ipow(__in1, 2));
                ///////////////////

                __tmp90 = __out;
            }
            {
                double __in1 = __tmp_122_23_r;
                double __in2 = qsl;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp91 = __out;
            }
            {
                double __in2 = a;
                double __in1 = __tmp91;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp92 = __out;
            }
            {
                double __in1 = __tmp92;
                double __out;

                ///////////////////
                // Tasklet code (_Pow_)
                __out = (dace::math::ipow(__in1, 2));
                ///////////////////

                __tmp93 = __out;
            }
            {
                double __in2 = __tmp93;
                double __in1 = __tmp90;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp94 = __out;
            }
            {
                double __in1 = __tmp94;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_sqrt_)
                __out = sqrt(__in1);
                ///////////////////

                __tmp95 = __out;
            }
            {
                double __in_b = __tmp95;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(1e-10, __in_b);
                ///////////////////

                __tmp96 = __out;
            }

        }
        sigma = __tmp96;


    }
    {

        {
            double __in1 = sbar;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / double(sigma));
            ///////////////////

            __tmp97 = __out;
        }

    }
    q1 = __tmp97;

    if ((! (q1 > 0.0))) {
        {
            double __tmp105;
            double __tmp106;

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (1.2 * double(q1));
                ///////////////////

                __tmp105 = __out;
            }
            {
                double __in1 = __tmp105;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - 1.0);
                ///////////////////

                __tmp106 = __out;
            }
            {
                double __in1 = __tmp106;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_exp_)
                __out = exp(__in1);
                ///////////////////

                __tmp107 = __out;
            }

        }
        cond_tmp = __tmp107;

    } else {

        if ((q1 <= 2.0)) {
            {
                double __tmp98;
                double __tmp99;
                double __tmp100;
                double __tmp101;
                double __tmp102;

                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_exp_)
                    __out = exp(-1.0);
                    ///////////////////

                    __tmp98 = __out;
                }
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (0.66 * double(q1));
                    ///////////////////

                    __tmp99 = __out;
                }
                {
                    double __in1 = __tmp98;
                    double __in2 = __tmp99;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp100 = __out;
                }
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_Pow_)
                    __out = (dace::math::ipow(double(q1), 2));
                    ///////////////////

                    __tmp101 = __out;
                }
                {
                    double __in2 = __tmp101;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (0.086 * __in2);
                    ///////////////////

                    __tmp102 = __out;
                }
                {
                    double __in2 = __tmp102;
                    double __in1 = __tmp100;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp103 = __out;
                }

            }
            cond_tmp = min(__tmp103, 2);

        } else {

            cond_tmp = q1;

        }


    }

    cond_tmp = (cond_tmp * sigma);

    if ((! (cond_tmp > 1e-12))) {
        {

            {
                double __out;

                ///////////////////
                // Tasklet code (assign_150_16)
                __out = 0;
                ///////////////////

                __tmp_146_16_w = __out;
            }

        }
        __tmp114 = (__tmp_146_16_w == 0);

    } else {
        {
            double __tmp108;
            double __tmp109;
            double __tmp110;
            double __tmp111;
            double __tmp112;
            double __tmp113;

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (1.55 * double(q1));
                ///////////////////

                __tmp108 = __out;
            }
            {
                double __in1 = __tmp108;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_arctan_)
                __out = atan(__in1);
                ///////////////////

                __tmp109 = __out;
            }
            {
                double __in2 = __tmp109;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (0.36 * __in2);
                ///////////////////

                __tmp110 = __out;
            }
            {
                double __in2 = __tmp110;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (0.5 + __in2);
                ///////////////////

                __tmp111 = __out;
            }
            {
                double __in_b = __tmp111;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(1, __in_b);
                ///////////////////

                __tmp112 = __out;
            }
            {
                double __in_b = __tmp112;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(0, __in_b);
                ///////////////////

                __tmp113 = __out;
            }
            {
                double __inp = __tmp113;
                double __out;

                ///////////////////
                // Tasklet code (assign_146_16)
                __out = __inp;
                ///////////////////

                __tmp_146_16_w = __out;
            }

        }
        __tmp114 = (__tmp_146_16_w == 0);

    }

    if (__tmp114) {

        cond_tmp = 0;
        __tmp115 = (! __tmp_66_15_r);

    } else {

        __tmp115 = (! __tmp_66_15_r);

    }

    if (__tmp115) {
        {
            double __tmp117;
            double __tmp118;
            double __tmp119;
            double __tmp120;
            double __tmp121;
            double __tmp122;
            double __tmp123;
            double __tmp124;

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double((1 - frac_tmp)) * cond_tmp);
                ///////////////////

                __tmp117 = __out;
            }
            {
                double __inp = __tmp117;
                double __out;

                ///////////////////
                // Tasklet code (assign_157_16)
                __out = __inp;
                ///////////////////

                __tmp_157_16_w = __out;
            }
            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double(frac_tmp) * cond_tmp);
                ///////////////////

                __tmp118 = __out;
            }
            {
                double __inp = __tmp118;
                double __out;

                ///////////////////
                // Tasklet code (assign_158_16)
                __out = __inp;
                ///////////////////

                __tmp_158_16_w = __out;
            }
            {
                double __in2 = __tmp_63_37_r;
                double __in1 = __tmp_157_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp119 = __out;
            }
            {
                double __in2 = __tmp_106_31_r;
                double __in1 = __tmp119;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp120 = __out;
            }
            {
                double __in2 = __tmp_63_52_r;
                double __in1 = __tmp_158_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp121 = __out;
            }
            {
                double __in2 = __tmp_106_56_r;
                double __in1 = __tmp121;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp122 = __out;
            }
            {
                double __in2 = __tmp122;
                double __in1 = __tmp120;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp123 = __out;
            }
            {
                double __in2 = __tmp_110_27_r;
                double __in1 = __tmp123;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp124 = __out;
            }
            {
                double __inp = __tmp124;
                double __out;

                ///////////////////
                // Tasklet code (assign_159_16)
                __out = __inp;
                ///////////////////

                dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_67_33_w, __out);
            }

        }

    }
    {

        {
            double __out;

            ///////////////////
            // Tasklet code (assign_166_12)
            __out = min(3, max(1, (1 - q1)));
            ///////////////////

            dace::wcr_fixed<dace::ReductionType::Product, double>::reduce(&__tmp_166_12_w, __out);
        }

    }
}

inline void ice3_stencils_cloud_fraction_split_cloud_fraction_1_32_4_0_1_38(ice_adjust_state_t *__state, const double&  __tmp_34_14_r, const double&  __tmp_34_32_r, const double&  __tmp_34_48_r, const double&  __tmp_35_14_r, const double&  __tmp_35_32_r, const double&  __tmp_39_26_r, const double&  __tmp_41_25_r, const double&  __tmp_44_30_r, const double&  __tmp_44_45_r, const double&  __tmp_44_60_r, const double&  __tmp_47_26_r, const double&  __tmp_52_24_r, const double&  __tmp_52_45_r, double&  __tmp_42_8_w, double&  __tmp_43_8_w, double&  __tmp_44_8_w, double&  __tmp_51_8_w) {
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

inline void ice3_stencils_cloud_fraction_split_cloud_fraction_2_87_4_0_2_2(ice_adjust_state_t *__state, const double&  __tmp_103_53_r, const double&  __tmp_107_35_r, const double&  __tmp_107_54_r, const double&  __tmp_107_70_r, const double&  __tmp_107_85_r, const double&  __tmp_109_21_r, const double&  __tmp_109_31_r, const double&  __tmp_114_48_r, const double&  __tmp_143_16_r, const double&  __tmp_144_23_r, const double&  __tmp_144_35_r, const double&  __tmp_144_48_r, const double&  __tmp_144_54_r, const double&  __tmp_151_48_r, const bool&  __tmp_89_15_r, const double&  __tmp_90_16_r, const double&  __tmp_90_32_r, const double&  __tmp_90_47_r, const double&  __tmp_96_17_r, const double&  __tmp_97_17_r, const double&  __tmp_99_25_r, double&  __tmp_104_12_w, double&  __tmp_105_12_w, double&  __tmp_106_12_w, double&  __tmp_107_12_w, double&  __tmp_113_20_w, double&  __tmp_114_20_w, double&  __tmp_150_20_w, double&  __tmp_151_20_w, double&  __tmp_91_16_w, int64_t SUBG_MF_PDF) {
    double __tmp3;
    double __tmp7;
    double __tmp47;
    double __tmp108;
    double w1;
    double w2;
    double criaut;
    double hcf;
    double hr;
    double hri;
    bool __tmp1;
    bool __tmp8;
    double __tmp90;
    double __tmp91;
    double __tmp109;
    bool __tmp110;
    double __tmp84;
    double __tmp85;
    double __tmp27;
    double __tmp28;
    double __tmp48;
    bool __tmp49;
    double __tmp21;
    double __tmp22;
    bool __tmp4;


    __tmp1 = (! __tmp_89_15_r);

    if ((! __tmp1)) {
        {

            {
                double __in1 = __tmp_96_17_r;
                double __in2 = __tmp_90_47_r;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                w1 = __out;
            }
            {
                double __in1 = __tmp_97_17_r;
                double __in2 = __tmp_90_47_r;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                w2 = __out;
            }
            {
                double __in1 = w1;
                double __in2 = w2;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp7 = __out;
            }

        }
        __tmp8 = (__tmp7 > __tmp_99_25_r);

        if (__tmp8) {
            {
                double __tmp9;
                double __tmp10;
                double __tmp11;

                {
                    double __in1 = w1;
                    double __in2 = w2;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp9 = __out;
                }
                {
                    double __in1 = __tmp_99_25_r;
                    double __in2 = __tmp9;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Div_)
                    __out = (__in1 / __in2);
                    ///////////////////

                    __tmp10 = __out;
                }
                {
                    double __in2 = __tmp10;
                    double __in1 = w1;
                    double __out;

                    ///////////////////
                    // Tasklet code (augassign_100_16)
                    __out = (__in1 * __in2);
                    ///////////////////

                    w1 = __out;
                }
                {
                    double __in1 = __tmp_99_25_r;
                    double __in2 = w1;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Sub_)
                    __out = (__in1 - __in2);
                    ///////////////////

                    __tmp11 = __out;
                }
                {
                    double __inp = __tmp11;
                    double __out;

                    ///////////////////
                    // Tasklet code (assign_101_16)
                    __out = __inp;
                    ///////////////////

                    w2 = __out;
                }

            }

        }
        {
            double __tmp12;
            double __tmp13;
            double __tmp14;
            double __tmp15;
            double __tmp16;
            double __tmp17;
            double __tmp18;
            double __tmp19;

            {
                double __in1 = __tmp_91_16_w;
                double __in2 = __tmp_103_53_r;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp12 = __out;
            }
            {
                double __in_b = __tmp12;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(double(1), __in_b);
                ///////////////////

                __tmp13 = __out;
            }
            {
                double __inp = __tmp13;
                double __out;

                ///////////////////
                // Tasklet code (assign_103_12)
                __out = __inp;
                ///////////////////

                __tmp_91_16_w = __out;
            }
            {
                double __inp = w1;
                double __out;

                ///////////////////
                // Tasklet code (assign_104_12)
                __out = __inp;
                ///////////////////

                dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_104_12_w, __out);
            }
            {
                double __in2 = w2;
                double __in1 = w1;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp14 = __out;
            }
            {
                double __inp = __tmp14;
                double __out;

                ///////////////////
                // Tasklet code (assign_106_12)
                __out = __inp;
                ///////////////////

                dace::wcr_custom<double>:: template reduce([] (const double& x, const double& y) { return (x - y); }, &__tmp_106_12_w, __out);
            }
            {
                double __inp = w2;
                double __out;

                ///////////////////
                // Tasklet code (assign_105_12)
                __out = __inp;
                ///////////////////

                dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_105_12_w, __out);
            }
            {
                double __in2 = __tmp_107_35_r;
                double __in1 = w1;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp15 = __out;
            }
            {
                double __in2 = __tmp_107_54_r;
                double __in1 = w2;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp16 = __out;
            }
            {
                double __in2 = __tmp16;
                double __in1 = __tmp15;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp17 = __out;
            }
            {
                double __in1 = __tmp_107_70_r;
                double __in2 = __tmp_107_85_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp18 = __out;
            }
            {
                double __in2 = __tmp18;
                double __in1 = __tmp17;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp19 = __out;
            }
            {
                double __inp = __tmp19;
                double __out;

                ///////////////////
                // Tasklet code (assign_107_12)
                __out = __inp;
                ///////////////////

                dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_107_12_w, __out);
            }
            {
                double __in1 = __tmp_109_21_r;
                double __in2 = __tmp_109_31_r;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                criaut = __out;
            }

        }
        if ((SUBG_MF_PDF == 0)) {

            __tmp21 = (w1 * __tmp_90_47_r);
            __tmp22 = (__tmp_103_53_r * criaut);

            if ((__tmp21 > __tmp22)) {
                {
                    double __tmp24;
                    double __tmp25;
                    double __tmp26;

                    {
                        double __in1 = w1;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp24 = __out;
                    }
                    {
                        double __inp = __tmp24;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_113_20)
                        __out = __inp;
                        ///////////////////

                        dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_113_20_w, __out);
                    }
                    {
                        double __in1 = __tmp_114_48_r;
                        double __in2 = __tmp_103_53_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp25 = __out;
                    }
                    {
                        double __in_b = __tmp25;
                        double __out;

                        ///////////////////
                        // Tasklet code (__min2)
                        __out = min(1, __in_b);
                        ///////////////////

                        __tmp26 = __out;
                    }
                    {
                        double __inp = __tmp26;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_114_20)
                        __out = __inp;
                        ///////////////////

                        __tmp_114_20_w = __out;
                    }

                }

            }


        }

        if ((SUBG_MF_PDF == 1)) {

            __tmp27 = (w1 * __tmp_90_47_r);
            __tmp28 = (__tmp_103_53_r * criaut);

            if ((__tmp27 > __tmp28)) {
                {
                    double __tmp30;
                    double __tmp31;
                    double __tmp32;
                    double __tmp33;
                    double __tmp34;
                    double __tmp35;
                    double __tmp37;
                    double __tmp38;
                    double __tmp39;
                    double __tmp40;
                    double __tmp41;
                    double __tmp42;
                    double __tmp43;
                    double __tmp44;

                    {
                        double __in1 = criaut;
                        double __in2 = __tmp_103_53_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp30 = __out;
                    }
                    {
                        double __in1 = w1;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp31 = __out;
                    }
                    {
                        double __in_b = __tmp31;
                        double __out;

                        ///////////////////
                        // Tasklet code (__max2)
                        __out = max(1e-20, __in_b);
                        ///////////////////

                        __tmp32 = __out;
                    }
                    {
                        double __in1 = __tmp30;
                        double __in2 = __tmp32;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Div_)
                        __out = (__in1 / __in2);
                        ///////////////////

                        __tmp33 = __out;
                    }
                    {
                        double __in1 = __tmp33;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Pow_)
                        __out = (dace::math::ipow(__in1, 2));
                        ///////////////////

                        __tmp34 = __out;
                    }
                    {
                        double __in2 = __tmp34;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (0.5 * __in2);
                        ///////////////////

                        __tmp35 = __out;
                    }
                    {
                        double __in2 = __tmp35;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (1.0 - __in2);
                        ///////////////////

                        hcf = __out;
                    }
                    {
                        double __in1 = criaut;
                        double __in2 = __tmp_103_53_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp38 = __out;
                    }
                    {
                        double __in1 = __tmp38;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Pow_)
                        __out = (dace::math::ipow(__in1, 3));
                        ///////////////////

                        __tmp39 = __out;
                    }
                    {
                        double __in1 = w1;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp37 = __out;
                    }
                    {
                        double __in1 = w1;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp40 = __out;
                    }
                    {
                        double __in_b = __tmp40;
                        double __out;

                        ///////////////////
                        // Tasklet code (__max2)
                        __out = max(1e-20, __in_b);
                        ///////////////////

                        __tmp41 = __out;
                    }
                    {
                        double __in1 = __tmp41;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Pow_)
                        __out = (dace::math::ipow(__in1, 2));
                        ///////////////////

                        __tmp42 = __out;
                    }
                    {
                        double __in2 = __tmp42;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (double(3) * __in2);
                        ///////////////////

                        __tmp43 = __out;
                    }
                    {
                        double __in2 = __tmp43;
                        double __in1 = __tmp39;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Div_)
                        __out = (__in1 / __in2);
                        ///////////////////

                        __tmp44 = __out;
                    }
                    {
                        double __in1 = __tmp37;
                        double __in2 = __tmp44;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (__in1 - __in2);
                        ///////////////////

                        hr = __out;
                    }

                }

            } else {

                __tmp48 = (__tmp_103_53_r * criaut);
                {
                    double __tmp46;

                    {
                        double __in2 = w1;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (2.0 * __in2);
                        ///////////////////

                        __tmp46 = __out;
                    }
                    {
                        double __in2 = __tmp_90_47_r;
                        double __in1 = __tmp46;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp47 = __out;
                    }

                }
                __tmp49 = (__tmp47 <= __tmp48);

                if ((! __tmp49)) {
                    {
                        double __tmp50;
                        double __tmp51;
                        double __tmp52;
                        double __tmp53;
                        double __tmp54;
                        double __tmp55;
                        double __tmp56;
                        double __tmp57;
                        double __tmp58;
                        double __tmp59;
                        double __tmp60;
                        double __tmp61;
                        double __tmp62;
                        double __tmp63;
                        double __tmp64;
                        double __tmp65;
                        double __tmp66;
                        double __tmp67;
                        double __tmp68;
                        double __tmp69;
                        double __tmp70;
                        double __tmp71;
                        double __tmp72;
                        double __tmp73;
                        double __tmp74;
                        double __tmp75;
                        double __tmp76;

                        {
                            double __in2 = w1;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (2.0 * __in2);
                            ///////////////////

                            __tmp50 = __out;
                        }
                        {
                            double __in2 = __tmp_90_47_r;
                            double __in1 = __tmp50;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp51 = __out;
                        }
                        {
                            double __in1 = w1;
                            double __in2 = __tmp_90_47_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp55 = __out;
                        }
                        {
                            double __in_b = __tmp55;
                            double __out;

                            ///////////////////
                            // Tasklet code (__max2)
                            __out = max(1e-20, __in_b);
                            ///////////////////

                            __tmp56 = __out;
                        }
                        {
                            double __in1 = __tmp56;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp57 = __out;
                        }
                        {
                            double __in2 = __tmp57;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (2.0 * __in2);
                            ///////////////////

                            __tmp58 = __out;
                        }
                        {
                            double __in1 = criaut;
                            double __in2 = __tmp_103_53_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp52 = __out;
                        }
                        {
                            double __in1 = __tmp51;
                            double __in2 = __tmp52;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Sub_)
                            __out = (__in1 - __in2);
                            ///////////////////

                            __tmp53 = __out;
                        }
                        {
                            double __in1 = __tmp53;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp54 = __out;
                        }
                        {
                            double __in2 = __tmp58;
                            double __in1 = __tmp54;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Div_)
                            __out = (__in1 / __in2);
                            ///////////////////

                            __tmp59 = __out;
                        }
                        {
                            double __inp = __tmp59;
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_128_20)
                            __out = __inp;
                            ///////////////////

                            hcf = __out;
                        }
                        {
                            double __in2 = w1;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (3.0 * __in2);
                            ///////////////////

                            __tmp63 = __out;
                        }
                        {
                            double __in1 = w1;
                            double __in2 = __tmp_90_47_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp60 = __out;
                        }
                        {
                            double __in1 = __tmp60;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 3));
                            ///////////////////

                            __tmp61 = __out;
                        }
                        {
                            double __in2 = __tmp61;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (4.0 * __in2);
                            ///////////////////

                            __tmp62 = __out;
                        }
                        {
                            double __in1 = __tmp63;
                            double __in2 = __tmp_90_47_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp64 = __out;
                        }
                        {
                            double __in2 = __tmp_90_47_r;
                            double __in1 = w1;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp72 = __out;
                        }
                        {
                            double __in_b = __tmp72;
                            double __out;

                            ///////////////////
                            // Tasklet code (__max2)
                            __out = max(1e-20, __in_b);
                            ///////////////////

                            __tmp73 = __out;
                        }
                        {
                            double __in1 = __tmp73;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp74 = __out;
                        }
                        {
                            double __in2 = __tmp74;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (double(3) * __in2);
                            ///////////////////

                            __tmp75 = __out;
                        }
                        {
                            double __in1 = criaut;
                            double __in2 = __tmp_103_53_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp65 = __out;
                        }
                        {
                            double __in1 = __tmp65;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp66 = __out;
                        }
                        {
                            double __in2 = __tmp66;
                            double __in1 = __tmp64;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp67 = __out;
                        }
                        {
                            double __in2 = __tmp67;
                            double __in1 = __tmp62;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Sub_)
                            __out = (__in1 - __in2);
                            ///////////////////

                            __tmp68 = __out;
                        }
                        {
                            double __in1 = __tmp_103_53_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 3));
                            ///////////////////

                            __tmp69 = __out;
                        }
                        {
                            double __in2 = __tmp69;
                            double __in1 = criaut;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp70 = __out;
                        }
                        {
                            double __in2 = __tmp70;
                            double __in1 = __tmp68;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __tmp71 = __out;
                        }
                        {
                            double __in2 = __tmp75;
                            double __in1 = __tmp71;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Div_)
                            __out = (__in1 / __in2);
                            ///////////////////

                            __tmp76 = __out;
                        }
                        {
                            double __inp = __tmp76;
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_131_20)
                            __out = __inp;
                            ///////////////////

                            hr = __out;
                        }

                    }

                } else {
                    {

                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_124_20)
                            __out = 0.0;
                            ///////////////////

                            hcf = __out;
                        }
                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_125_20)
                            __out = 0.0;
                            ///////////////////

                            hr = __out;
                        }

                    }

                }


            }
            {
                double __tmp77;
                double __tmp78;

                {
                    double __in2 = __tmp_103_53_r;
                    double __in1 = hcf;
                    double __out;

                    ///////////////////
                    // Tasklet code (augassign_137_16)
                    __out = (__in1 * __in2);
                    ///////////////////

                    hcf = __out;
                }
                {
                    double __in1 = __tmp_114_20_w;
                    double __in2 = hcf;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp77 = __out;
                }
                {
                    double __in_b = __tmp77;
                    double __out;

                    ///////////////////
                    // Tasklet code (__min2)
                    __out = min(1, __in_b);
                    ///////////////////

                    __tmp78 = __out;
                }
                {
                    double __inp = __tmp78;
                    double __out;

                    ///////////////////
                    // Tasklet code (assign_138_16)
                    __out = __inp;
                    ///////////////////

                    __tmp_114_20_w = __out;
                }
                {
                    double __inp = hr;
                    double __out;

                    ///////////////////
                    // Tasklet code (assign_139_16)
                    __out = __inp;
                    ///////////////////

                    dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_113_20_w, __out);
                }

            }

        }
        {
            double __tmp79;
            double __tmp80;
            double __tmp81;
            double __tmp82;
            double __tmp83;

            {
                double __in1 = __tmp_144_35_r;
                double __in2 = __tmp_144_48_r;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp79 = __out;
            }
            {
                double __in1 = __tmp_144_23_r;
                double __in2 = __tmp79;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp80 = __out;
            }
            {
                double __in2 = __tmp_144_54_r;
                double __in1 = __tmp80;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp81 = __out;
            }
            {
                double __in2 = __tmp81;
                double __out;

                ///////////////////
                // Tasklet code (_Pow_)
                __out = dace::math::pow(double(10), __in2);
                ///////////////////

                __tmp82 = __out;
            }
            {
                double __in_a = __tmp_143_16_r;
                double __in_b = __tmp82;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(__in_a, __in_b);
                ///////////////////

                __tmp83 = __out;
            }
            {
                double __inp = __tmp83;
                double __out;

                ///////////////////
                // Tasklet code (assign_142_12)
                __out = __inp;
                ///////////////////

                criaut = __out;
            }

        }
        if ((SUBG_MF_PDF == 0)) {

            __tmp84 = (w2 * __tmp_90_47_r);
            __tmp85 = (__tmp_103_53_r * criaut);

            if ((__tmp84 > __tmp85)) {
                {
                    double __tmp87;
                    double __tmp88;
                    double __tmp89;

                    {
                        double __in1 = w2;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp87 = __out;
                    }
                    {
                        double __inp = __tmp87;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_150_20)
                        __out = __inp;
                        ///////////////////

                        dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_150_20_w, __out);
                    }
                    {
                        double __in1 = __tmp_151_48_r;
                        double __in2 = __tmp_103_53_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp88 = __out;
                    }
                    {
                        double __in_b = __tmp88;
                        double __out;

                        ///////////////////
                        // Tasklet code (__min2)
                        __out = min(1, __in_b);
                        ///////////////////

                        __tmp89 = __out;
                    }
                    {
                        double __inp = __tmp89;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_151_20)
                        __out = __inp;
                        ///////////////////

                        __tmp_151_20_w = __out;
                    }

                }

            }


        }

        if ((SUBG_MF_PDF == 1)) {

            __tmp90 = (w2 * __tmp_90_47_r);
            __tmp91 = (__tmp_103_53_r * criaut);

            if ((__tmp90 > __tmp91)) {
                {
                    double __tmp93;
                    double __tmp94;
                    double __tmp95;
                    double __tmp96;
                    double __tmp97;
                    double __tmp98;
                    double __tmp99;
                    double __tmp100;
                    double __tmp101;
                    double __tmp102;
                    double __tmp103;
                    double __tmp104;
                    double __tmp105;

                    {
                        double __in1 = criaut;
                        double __in2 = __tmp_103_53_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp93 = __out;
                    }
                    {
                        double __in1 = w2;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp94 = __out;
                    }
                    {
                        double __in2 = __tmp94;
                        double __in1 = __tmp93;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Div_)
                        __out = (__in1 / __in2);
                        ///////////////////

                        __tmp95 = __out;
                    }
                    {
                        double __in1 = __tmp95;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Pow_)
                        __out = (dace::math::ipow(__in1, 2));
                        ///////////////////

                        __tmp96 = __out;
                    }
                    {
                        double __in2 = __tmp96;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (0.5 * __in2);
                        ///////////////////

                        __tmp97 = __out;
                    }
                    {
                        double __in2 = __tmp97;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (1.0 - __in2);
                        ///////////////////

                        __tmp98 = __out;
                    }
                    {
                        double __inp = __tmp98;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_156_20)
                        __out = __inp;
                        ///////////////////

                        hcf = __out;
                    }
                    {
                        double __in1 = criaut;
                        double __in2 = __tmp_103_53_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp100 = __out;
                    }
                    {
                        double __in1 = __tmp100;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Pow_)
                        __out = (dace::math::ipow(__in1, 3));
                        ///////////////////

                        __tmp101 = __out;
                    }
                    {
                        double __in1 = w2;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp99 = __out;
                    }
                    {
                        double __in1 = w2;
                        double __in2 = __tmp_90_47_r;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp102 = __out;
                    }
                    {
                        double __in1 = __tmp102;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Pow_)
                        __out = (dace::math::ipow(__in1, 2));
                        ///////////////////

                        __tmp103 = __out;
                    }
                    {
                        double __in2 = __tmp103;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (double(3) * __in2);
                        ///////////////////

                        __tmp104 = __out;
                    }
                    {
                        double __in2 = __tmp104;
                        double __in1 = __tmp101;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Div_)
                        __out = (__in1 / __in2);
                        ///////////////////

                        __tmp105 = __out;
                    }
                    {
                        double __in2 = __tmp105;
                        double __in1 = __tmp99;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (__in1 - __in2);
                        ///////////////////

                        hri = __out;
                    }

                }

            } else {

                __tmp109 = (__tmp_103_53_r * criaut);
                {
                    double __tmp107;

                    {
                        double __in2 = w2;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (double(2) * __in2);
                        ///////////////////

                        __tmp107 = __out;
                    }
                    {
                        double __in2 = __tmp_90_47_r;
                        double __in1 = __tmp107;
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (__in1 * __in2);
                        ///////////////////

                        __tmp108 = __out;
                    }

                }
                __tmp110 = (__tmp108 <= __tmp109);

                if ((! __tmp110)) {
                    {
                        double __tmp111;
                        double __tmp112;
                        double __tmp113;
                        double __tmp114;
                        double __tmp115;
                        double __tmp116;
                        double __tmp117;
                        double __tmp118;
                        double __tmp119;
                        double __tmp120;
                        double __tmp121;
                        double __tmp122;
                        double __tmp123;
                        double __tmp124;
                        double __tmp125;
                        double __tmp126;
                        double __tmp127;
                        double __tmp128;
                        double __tmp129;
                        double __tmp130;
                        double __tmp131;
                        double __tmp132;
                        double __tmp133;
                        double __tmp134;
                        double __tmp135;

                        {
                            double __in2 = w2;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (2.0 * __in2);
                            ///////////////////

                            __tmp111 = __out;
                        }
                        {
                            double __in2 = __tmp_90_47_r;
                            double __in1 = __tmp111;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp112 = __out;
                        }
                        {
                            double __in1 = w2;
                            double __in2 = __tmp_90_47_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp116 = __out;
                        }
                        {
                            double __in1 = __tmp116;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp117 = __out;
                        }
                        {
                            double __in2 = __tmp117;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (2.0 * __in2);
                            ///////////////////

                            __tmp118 = __out;
                        }
                        {
                            double __in1 = criaut;
                            double __in2 = __tmp_103_53_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp113 = __out;
                        }
                        {
                            double __in1 = __tmp112;
                            double __in2 = __tmp113;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Sub_)
                            __out = (__in1 - __in2);
                            ///////////////////

                            __tmp114 = __out;
                        }
                        {
                            double __in1 = __tmp114;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp115 = __out;
                        }
                        {
                            double __in2 = __tmp118;
                            double __in1 = __tmp115;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Div_)
                            __out = (__in1 / __in2);
                            ///////////////////

                            __tmp119 = __out;
                        }
                        {
                            double __inp = __tmp119;
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_164_20)
                            __out = __inp;
                            ///////////////////

                            hcf = __out;
                        }
                        {
                            double __in2 = w2;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (3.0 * __in2);
                            ///////////////////

                            __tmp123 = __out;
                        }
                        {
                            double __in1 = w2;
                            double __in2 = __tmp_90_47_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp120 = __out;
                        }
                        {
                            double __in1 = __tmp120;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 3));
                            ///////////////////

                            __tmp121 = __out;
                        }
                        {
                            double __in2 = __tmp121;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (4.0 * __in2);
                            ///////////////////

                            __tmp122 = __out;
                        }
                        {
                            double __in1 = __tmp123;
                            double __in2 = __tmp_90_47_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp124 = __out;
                        }
                        {
                            double __in1 = w2;
                            double __in2 = __tmp_90_47_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp132 = __out;
                        }
                        {
                            double __in1 = __tmp132;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp133 = __out;
                        }
                        {
                            double __in2 = __tmp133;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (3.0 * __in2);
                            ///////////////////

                            __tmp134 = __out;
                        }
                        {
                            double __in1 = criaut;
                            double __in2 = __tmp_103_53_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp125 = __out;
                        }
                        {
                            double __in1 = __tmp125;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 2));
                            ///////////////////

                            __tmp126 = __out;
                        }
                        {
                            double __in2 = __tmp126;
                            double __in1 = __tmp124;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp127 = __out;
                        }
                        {
                            double __in2 = __tmp127;
                            double __in1 = __tmp122;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Sub_)
                            __out = (__in1 - __in2);
                            ///////////////////

                            __tmp128 = __out;
                        }
                        {
                            double __in1 = criaut;
                            double __in2 = __tmp_103_53_r;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp129 = __out;
                        }
                        {
                            double __in1 = __tmp129;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Pow_)
                            __out = (dace::math::ipow(__in1, 3));
                            ///////////////////

                            __tmp130 = __out;
                        }
                        {
                            double __in2 = __tmp130;
                            double __in1 = __tmp128;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __tmp131 = __out;
                        }
                        {
                            double __in2 = __tmp134;
                            double __in1 = __tmp131;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Div_)
                            __out = (__in1 / __in2);
                            ///////////////////

                            __tmp135 = __out;
                        }
                        {
                            double __inp = __tmp135;
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_167_20)
                            __out = __inp;
                            ///////////////////

                            hri = __out;
                        }

                    }

                } else {
                    {

                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_160_20)
                            __out = 0.0;
                            ///////////////////

                            hcf = __out;
                        }
                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_161_20)
                            __out = 0.0;
                            ///////////////////

                            hri = __out;
                        }

                    }

                }


            }
            {
                double __tmp136;
                double __tmp137;

                {
                    double __in2 = __tmp_103_53_r;
                    double __in1 = hcf;
                    double __out;

                    ///////////////////
                    // Tasklet code (augassign_173_16)
                    __out = (__in1 * __in2);
                    ///////////////////

                    hcf = __out;
                }
                {
                    double __in1 = __tmp_151_20_w;
                    double __in2 = hcf;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp136 = __out;
                }
                {
                    double __in_b = __tmp136;
                    double __out;

                    ///////////////////
                    // Tasklet code (__min2)
                    __out = min(1, __in_b);
                    ///////////////////

                    __tmp137 = __out;
                }
                {
                    double __inp = __tmp137;
                    double __out;

                    ///////////////////
                    // Tasklet code (assign_174_16)
                    __out = __inp;
                    ///////////////////

                    __tmp_151_20_w = __out;
                }
                {
                    double __inp = hri;
                    double __out;

                    ///////////////////
                    // Tasklet code (assign_175_16)
                    __out = __inp;
                    ///////////////////

                    dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_150_20_w, __out);
                }

            }

        }


    } else {
        {
            double __tmp2;

            {
                double __in1 = __tmp_90_16_r;
                double __in2 = __tmp_90_32_r;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp2 = __out;
            }
            {
                double __in2 = __tmp_90_47_r;
                double __in1 = __tmp2;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp3 = __out;
            }

        }
        __tmp4 = (__tmp3 > 1e-12);

        if ((! __tmp4)) {
            {

                {
                    double __out;

                    ///////////////////
                    // Tasklet code (assign_93_16)
                    __out = 0.0;
                    ///////////////////

                    __tmp_91_16_w = __out;
                }

            }

        } else {
            {

                {
                    double __out;

                    ///////////////////
                    // Tasklet code (assign_91_16)
                    __out = 1.0;
                    ///////////////////

                    __tmp_91_16_w = __out;
                }

            }

        }


    }

}

void __program_ice_adjust_internal(ice_adjust_state_t*__state, double * __restrict__ cf_mf, double * __restrict__ cldfr, double * __restrict__ exn, double * __restrict__ hlc_hcf, double * __restrict__ hlc_hrc, double * __restrict__ hli_hcf, double * __restrict__ hli_hri, double * __restrict__ pabs, double * __restrict__ rc0, double * __restrict__ rc_mf, double * __restrict__ rcs0, double * __restrict__ rcs1, double * __restrict__ rg0, double * __restrict__ rhodref, double * __restrict__ ri0, double * __restrict__ ri_mf, double * __restrict__ ris0, double * __restrict__ ris1, double * __restrict__ rr0, double * __restrict__ rs0, double * __restrict__ rv0, double * __restrict__ rvs0, double * __restrict__ rvs1, double * __restrict__ sigqsat, double * __restrict__ sigrc, double * __restrict__ sigs, double * __restrict__ th0, double * __restrict__ ths0, double * __restrict__ ths1, double ACRIAUTI, double ALPI, double ALPW, double BCRIAUTI, double BETAI, double BETAW, double CI, double CL, double CPD, double CPV, double CRIAUTC, double CRIAUTI, bool FRAC_ICE_ADJUST, double GAMI, double GAMW, int I, int J, int K, bool LAMBDA3, bool LSIGMAS, bool LSTATNW, double LSTT, bool LSUBG_COND, double LVTT, int64_t NRR, bool OCND2, double RD, double RV, int64_t SUBG_MF_PDF, double TMAXMIX, double TMINMIX, double TT, double dt)
{
    double *cph;
    cph = new double DACE_ALIGN(64)[((I * J) * K)];
    double *lv;
    lv = new double DACE_ALIGN(64)[((I * J) * K)];
    double *ls;
    ls = new double DACE_ALIGN(64)[((I * J) * K)];
    double *t;
    t = new double DACE_ALIGN(64)[((I * J) * K)];
    double *rc_out;
    rc_out = new double DACE_ALIGN(64)[((I * J) * K)];
    double *ri_out;
    ri_out = new double DACE_ALIGN(64)[((I * J) * K)];
    int64_t __sym_SUBG_MF_PDF;

    {

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        ice3_stencils_thermo_thermodynamic_fields_34_4_0_0_2(__state, exn[((((J * K) * i) + (K * j)) + k)], th0[((((J * K) * i) + (K * j)) + k)], lv[((((J * K) * i) + (K * j)) + k)], LVTT, CPV, CL, TT, ls[((((J * K) * i) + (K * j)) + k)], LSTT, CI, t[((((J * K) * i) + (K * j)) + k)]);
                    }
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
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
                            double __in1 = CPV;
                            double __in2 = rv0[((((J * K) * i) + (K * j)) + k)];
                            double __out;

                            ///////////////////
                            // Tasklet code (_Mult_)
                            __out = (__in1 * __in2);
                            ///////////////////

                            __tmp1 = __out;
                        }
                        {
                            double __in2 = __tmp1;
                            double __in1 = CPD;
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __tmp2 = __out;
                        }
                        {
                            double __in1 = rc0[((((J * K) * i) + (K * j)) + k)];
                            double __in2 = rr0[((((J * K) * i) + (K * j)) + k)];
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __tmp3 = __out;
                        }
                        {
                            double __in2 = __tmp3;
                            double __in1 = CL;
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
                            double __in1 = ri0[((((J * K) * i) + (K * j)) + k)];
                            double __in2 = rs0[((((J * K) * i) + (K * j)) + k)];
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __tmp6 = __out;
                        }
                        {
                            double __in1 = __tmp6;
                            double __in2 = rg0[((((J * K) * i) + (K * j)) + k)];
                            double __out;

                            ///////////////////
                            // Tasklet code (_Add_)
                            __out = (__in1 + __in2);
                            ///////////////////

                            __tmp7 = __out;
                        }
                        {
                            double __in2 = __tmp7;
                            double __in1 = CI;
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

                            cph[((((J * K) * i) + (K * j)) + k)] = __out;
                        }
                    }
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_52_8)
                            __out = 0.0;
                            ///////////////////

                            cldfr[((((J * K) * i) + (K * j)) + k)] = __out;
                        }
                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_54_8)
                            __out = 0.0;
                            ///////////////////

                            rc_out[((((J * K) * i) + (K * j)) + k)] = __out;
                        }
                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_55_8)
                            __out = 0.0;
                            ///////////////////

                            ri_out[((((J * K) * i) + (K * j)) + k)] = __out;
                        }
                    }
                }
            }
        }

    }
    {
        double __tmp47;
        double *pv;
        pv = new double DACE_ALIGN(64)[((I * J) * K)];
        double *piv;
        piv = new double DACE_ALIGN(64)[((I * J) * K)];

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        ice3_stencils_condensation_split_condensation_58_4_0_1_2(__state, RD, RV, lv[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], LSIGMAS, LSTATNW, sigs[((((J * K) * i) + (K * j)) + k)], sigqsat[((((J * K) * i) + (K * j)) + k)], rv0[((((J * K) * i) + (K * j)) + k)], rc0[((((J * K) * i) + (K * j)) + k)], ri0[((((J * K) * i) + (K * j)) + k)], OCND2, pv[((((J * K) * i) + (K * j)) + k)], ALPW, BETAW, GAMW, pabs[((((J * K) * i) + (K * j)) + k)], piv[((((J * K) * i) + (K * j)) + k)], ALPI, BETAI, GAMI, TMAXMIX, TMINMIX, cldfr[((((J * K) * i) + (K * j)) + k)], rc_out[((((J * K) * i) + (K * j)) + k)], ri_out[((((J * K) * i) + (K * j)) + k)], sigrc[((((J * K) * i) + (K * j)) + k)], t[((((J * K) * i) + (K * j)) + k)], pv[((((J * K) * i) + (K * j)) + k)], piv[((((J * K) * i) + (K * j)) + k)]);
                    }
                }
            }
        }
        {
            double __tmp46;

            ///////////////////
            // Tasklet code (scalar)
            __tmp46 = 50.0;
            ///////////////////

            __tmp47 = __tmp46;
        }
        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        ice3_stencils_cloud_fraction_split_cloud_fraction_1_32_4_0_1_38(__state, rc_out[((((J * K) * i) + (K * j)) + k)], rc0[((((J * K) * i) + (K * j)) + k)], __tmp47, ri_out[((((J * K) * i) + (K * j)) + k)], ri0[((((J * K) * i) + (K * j)) + k)], rcs0[((((J * K) * i) + (K * j)) + k)], rvs0[((((J * K) * i) + (K * j)) + k)], lv[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], exn[((((J * K) * i) + (K * j)) + k)], ris0[((((J * K) * i) + (K * j)) + k)], ths0[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)], rvs1[((((J * K) * i) + (K * j)) + k)], rcs1[((((J * K) * i) + (K * j)) + k)], ths1[((((J * K) * i) + (K * j)) + k)], ris1[((((J * K) * i) + (K * j)) + k)]);
                    }
                }
            }
        }
        delete[] pv;
        delete[] piv;

    }
    __sym_SUBG_MF_PDF = SUBG_MF_PDF;
    {

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        ice3_stencils_cloud_fraction_split_cloud_fraction_2_87_4_0_2_2(__state, cf_mf[((((J * K) * i) + (K * j)) + k)], lv[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], exn[((((J * K) * i) + (K * j)) + k)], CRIAUTC, rhodref[((((J * K) * i) + (K * j)) + k)], hlc_hcf[((((J * K) * i) + (K * j)) + k)], CRIAUTI, ACRIAUTI, t[((((J * K) * i) + (K * j)) + k)], TT, BCRIAUTI, hli_hcf[((((J * K) * i) + (K * j)) + k)], LSUBG_COND, rcs1[((((J * K) * i) + (K * j)) + k)], ris1[((((J * K) * i) + (K * j)) + k)], dt, rc_mf[((((J * K) * i) + (K * j)) + k)], ri_mf[((((J * K) * i) + (K * j)) + k)], rvs1[((((J * K) * i) + (K * j)) + k)], rcs1[((((J * K) * i) + (K * j)) + k)], ris1[((((J * K) * i) + (K * j)) + k)], rvs1[((((J * K) * i) + (K * j)) + k)], ths1[((((J * K) * i) + (K * j)) + k)], hlc_hrc[((((J * K) * i) + (K * j)) + k)], hlc_hcf[((((J * K) * i) + (K * j)) + k)], hli_hri[((((J * K) * i) + (K * j)) + k)], hli_hcf[((((J * K) * i) + (K * j)) + k)], cldfr[((((J * K) * i) + (K * j)) + k)], __sym_SUBG_MF_PDF);
                    }
                }
            }
        }

    }
    delete[] cph;
    delete[] lv;
    delete[] ls;
    delete[] t;
    delete[] rc_out;
    delete[] ri_out;
}

DACE_EXPORTED void __program_ice_adjust(ice_adjust_state_t *__state, double * __restrict__ cf_mf, double * __restrict__ cldfr, double * __restrict__ exn, double * __restrict__ hlc_hcf, double * __restrict__ hlc_hrc, double * __restrict__ hli_hcf, double * __restrict__ hli_hri, double * __restrict__ pabs, double * __restrict__ rc0, double * __restrict__ rc_mf, double * __restrict__ rcs0, double * __restrict__ rcs1, double * __restrict__ rg0, double * __restrict__ rhodref, double * __restrict__ ri0, double * __restrict__ ri_mf, double * __restrict__ ris0, double * __restrict__ ris1, double * __restrict__ rr0, double * __restrict__ rs0, double * __restrict__ rv0, double * __restrict__ rvs0, double * __restrict__ rvs1, double * __restrict__ sigqsat, double * __restrict__ sigrc, double * __restrict__ sigs, double * __restrict__ th0, double * __restrict__ ths0, double * __restrict__ ths1, double ACRIAUTI, double ALPI, double ALPW, double BCRIAUTI, double BETAI, double BETAW, double CI, double CL, double CPD, double CPV, double CRIAUTC, double CRIAUTI, bool FRAC_ICE_ADJUST, double GAMI, double GAMW, int I, int J, int K, bool LAMBDA3, bool LSIGMAS, bool LSTATNW, double LSTT, bool LSUBG_COND, double LVTT, int64_t NRR, bool OCND2, double RD, double RV, int64_t SUBG_MF_PDF, double TMAXMIX, double TMINMIX, double TT, double dt)
{
    __program_ice_adjust_internal(__state, cf_mf, cldfr, exn, hlc_hcf, hlc_hrc, hli_hcf, hli_hri, pabs, rc0, rc_mf, rcs0, rcs1, rg0, rhodref, ri0, ri_mf, ris0, ris1, rr0, rs0, rv0, rvs0, rvs1, sigqsat, sigrc, sigs, th0, ths0, ths1, ACRIAUTI, ALPI, ALPW, BCRIAUTI, BETAI, BETAW, CI, CL, CPD, CPV, CRIAUTC, CRIAUTI, FRAC_ICE_ADJUST, GAMI, GAMW, I, J, K, LAMBDA3, LSIGMAS, LSTATNW, LSTT, LSUBG_COND, LVTT, NRR, OCND2, RD, RV, SUBG_MF_PDF, TMAXMIX, TMINMIX, TT, dt);
}

DACE_EXPORTED ice_adjust_state_t *__dace_init_ice_adjust(int I, int J, int K)
{
    int __result = 0;
    ice_adjust_state_t *__state = new ice_adjust_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_ice_adjust(ice_adjust_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

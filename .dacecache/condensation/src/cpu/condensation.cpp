/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct condensation_state_t {

};

inline void condensation_58_4_0_1_2(condensation_state_t *__state, const double&  __tmp_101_14_r, const double&  __tmp_101_19_r, const double&  __tmp_106_31_r, const double&  __tmp_106_56_r, const double&  __tmp_110_27_r, const bool&  __tmp_115_11_r, const bool&  __tmp_115_27_r, const double&  __tmp_119_25_r, const double&  __tmp_120_23_r, const double&  __tmp_63_22_r, const double&  __tmp_63_37_r, const double&  __tmp_63_52_r, const bool&  __tmp_66_15_r, const double&  __tmp_67_20_r, const double&  __tmp_67_45_r, const double&  __tmp_67_51_r, const double&  __tmp_67_58_r, const double&  __tmp_70_19_r, const double&  __tmp_73_20_r, const double&  __tmp_73_46_r, const double&  __tmp_73_52_r, const double&  __tmp_73_59_r, const double&  __tmp_93_37_r, const double&  __tmp_93_72_r, double&  __tmp_144_16_w, double&  __tmp_155_16_w, double&  __tmp_156_16_w, double&  __tmp_158_16_w, double&  __tmp_164_12_w, double&  __tmp_67_33_w, double&  __tmp_68_12_w, double&  __tmp_74_12_w, int64_t FRAC_ICE_ADJUST, int64_t LAMBDA3) {
    double __tmp_63_8_w;
    double __tmp40;
    double __tmp45;
    double __tmp96;
    double __tmp102;
    double __tmp106;
    double qsl;
    double a;
    double sbar;
    double sigma;
    int64_t frac_tmp;
    bool __tmp9;
    bool __tmp36;
    int64_t __tmp56;
    int64_t __tmp60;
    int64_t q1;
    bool __tmp86;
    bool __tmp87;
    double cond_tmp;
    bool __tmp113;
    bool __tmp114;
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
        __tmp86 = (! __tmp_115_27_r);

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

        if (FRAC_ICE_ADJUST) {
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

        } else {

            frac_tmp = max(0, min(1, frac_tmp));

        }

        __tmp56 = (1 - frac_tmp);
        __tmp60 = (1 - frac_tmp);
        q1 = 0;
        __tmp86 = (! __tmp_115_27_r);

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
    __tmp87 = (__tmp_115_11_r && __tmp86);

    if (__tmp87) {
        {
            double __tmp88;
            double __tmp89;
            double __tmp90;
            double __tmp91;
            double __tmp92;
            double __tmp93;
            double __tmp94;

            {
                double __in2 = __tmp_119_25_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double(2) * __in2);
                ///////////////////

                __tmp88 = __out;
            }
            {
                double __in1 = __tmp88;
                double __out;

                ///////////////////
                // Tasklet code (_Pow_)
                __out = (dace::math::ipow(__in1, 2));
                ///////////////////

                __tmp89 = __out;
            }
            {
                double __in1 = __tmp_120_23_r;
                double __in2 = qsl;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp90 = __out;
            }
            {
                double __in2 = a;
                double __in1 = __tmp90;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp91 = __out;
            }
            {
                double __in1 = __tmp91;
                double __out;

                ///////////////////
                // Tasklet code (_Pow_)
                __out = (dace::math::ipow(__in1, 2));
                ///////////////////

                __tmp92 = __out;
            }
            {
                double __in2 = __tmp92;
                double __in1 = __tmp89;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp93 = __out;
            }
            {
                double __in1 = __tmp93;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_sqrt_)
                __out = sqrt(__in1);
                ///////////////////

                __tmp94 = __out;
            }
            {
                double __in_b = __tmp94;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(1e-10, __in_b);
                ///////////////////

                sigma = __out;
            }
            {
                double __in1 = sbar;
                double __in2 = sigma;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp96 = __out;
            }

        }
        q1 = __tmp96;

    }

    if ((! (q1 > 0.0))) {
        {
            double __tmp104;
            double __tmp105;

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (1.2 * double(q1));
                ///////////////////

                __tmp104 = __out;
            }
            {
                double __in1 = __tmp104;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - 1.0);
                ///////////////////

                __tmp105 = __out;
            }
            {
                double __in1 = __tmp105;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_exp_)
                __out = exp(__in1);
                ///////////////////

                __tmp106 = __out;
            }

        }
        cond_tmp = __tmp106;

    } else {

        if ((q1 <= 2.0)) {
            {
                double __tmp97;
                double __tmp98;
                double __tmp99;
                double __tmp100;
                double __tmp101;

                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_exp_)
                    __out = exp(-1.0);
                    ///////////////////

                    __tmp97 = __out;
                }
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (0.66 * double(q1));
                    ///////////////////

                    __tmp98 = __out;
                }
                {
                    double __in1 = __tmp97;
                    double __in2 = __tmp98;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp99 = __out;
                }
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_Pow_)
                    __out = (dace::math::ipow(double(q1), 2));
                    ///////////////////

                    __tmp100 = __out;
                }
                {
                    double __in2 = __tmp100;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (0.086 * __in2);
                    ///////////////////

                    __tmp101 = __out;
                }
                {
                    double __in2 = __tmp101;
                    double __in1 = __tmp99;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp102 = __out;
                }

            }
            cond_tmp = min(__tmp102, 2);

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
                // Tasklet code (assign_148_16)
                __out = 0;
                ///////////////////

                __tmp_144_16_w = __out;
            }

        }
        __tmp113 = (__tmp_144_16_w == 0);

    } else {
        {
            double __tmp107;
            double __tmp108;
            double __tmp109;
            double __tmp110;
            double __tmp111;
            double __tmp112;

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (1.55 * double(q1));
                ///////////////////

                __tmp107 = __out;
            }
            {
                double __in1 = __tmp107;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_arctan_)
                __out = atan(__in1);
                ///////////////////

                __tmp108 = __out;
            }
            {
                double __in2 = __tmp108;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (0.36 * __in2);
                ///////////////////

                __tmp109 = __out;
            }
            {
                double __in2 = __tmp109;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (0.5 + __in2);
                ///////////////////

                __tmp110 = __out;
            }
            {
                double __in_b = __tmp110;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(1, __in_b);
                ///////////////////

                __tmp111 = __out;
            }
            {
                double __in_b = __tmp111;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(0, __in_b);
                ///////////////////

                __tmp112 = __out;
            }
            {
                double __inp = __tmp112;
                double __out;

                ///////////////////
                // Tasklet code (assign_144_16)
                __out = __inp;
                ///////////////////

                __tmp_144_16_w = __out;
            }

        }
        __tmp113 = (__tmp_144_16_w == 0);

    }

    if (__tmp113) {

        cond_tmp = 0;
        __tmp114 = (! __tmp_66_15_r);

    } else {

        __tmp114 = (! __tmp_66_15_r);

    }

    if (__tmp114) {
        {
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

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double((1 - frac_tmp)) * cond_tmp);
                ///////////////////

                __tmp116 = __out;
            }
            {
                double __inp = __tmp116;
                double __out;

                ///////////////////
                // Tasklet code (assign_155_16)
                __out = __inp;
                ///////////////////

                __tmp_155_16_w = __out;
            }
            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double(frac_tmp) * cond_tmp);
                ///////////////////

                __tmp117 = __out;
            }
            {
                double __inp = __tmp117;
                double __out;

                ///////////////////
                // Tasklet code (assign_156_16)
                __out = __inp;
                ///////////////////

                __tmp_156_16_w = __out;
            }
            {
                double __in1 = __tmp_156_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * double(1));
                ///////////////////

                __tmp125 = __out;
            }
            {
                double __in2 = __tmp_63_37_r;
                double __in1 = __tmp_155_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp118 = __out;
            }
            {
                double __in2 = __tmp_106_31_r;
                double __in1 = __tmp118;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp119 = __out;
            }
            {
                double __in2 = __tmp_63_52_r;
                double __in1 = __tmp_156_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp120 = __out;
            }
            {
                double __in2 = __tmp_106_56_r;
                double __in1 = __tmp120;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp121 = __out;
            }
            {
                double __in2 = __tmp121;
                double __in1 = __tmp119;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp122 = __out;
            }
            {
                double __in2 = __tmp_110_27_r;
                double __in1 = __tmp122;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp123 = __out;
            }
            {
                double __inp = __tmp123;
                double __out;

                ///////////////////
                // Tasklet code (assign_157_16)
                __out = __inp;
                ///////////////////

                dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_67_33_w, __out);
            }
            {
                double __in1 = __tmp_63_8_w;
                double __in2 = __tmp_155_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp124 = __out;
            }
            {
                double __in1 = __tmp124;
                double __in2 = __tmp125;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp126 = __out;
            }
            {
                double __inp = __tmp126;
                double __out;

                ///////////////////
                // Tasklet code (assign_158_16)
                __out = __inp;
                ///////////////////

                __tmp_158_16_w = __out;
            }

        }

    }

    if (LAMBDA3) {
        {

            {
                double __out;

                ///////////////////
                // Tasklet code (assign_164_12)
                __out = min(3, max(1, (1 - q1)));
                ///////////////////

                dace::wcr_fixed<dace::ReductionType::Product, double>::reduce(&__tmp_164_12_w, __out);
            }

        }

    }

}

void __program_condensation_internal(condensation_state_t*__state, double * __restrict__ cldfr, double * __restrict__ cph, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ pabs, double * __restrict__ rc0, double * __restrict__ rc_out, double * __restrict__ ri0, double * __restrict__ ri_out, double * __restrict__ rv0, double * __restrict__ rv_out, double * __restrict__ sigqsat, double * __restrict__ sigrc, double * __restrict__ sigs, double * __restrict__ t, double ALPI, double ALPW, double BETAI, double BETAW, bool FRAC_ICE_ADJUST, double GAMI, double GAMW, int I, int J, int K, bool LAMBDA3, bool LSIGMAS, bool LSTATNW, bool OCND2, double RD, double RV, double TMAXMIX, double TMINMIX)
{

    {

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
                            // Tasklet code (assign_53_8)
                            __out = 0.0;
                            ///////////////////

                            rv_out[((((J * K) * i) + (K * j)) + k)] = __out;
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
        double *pv;
        pv = new double DACE_ALIGN(64)[((I * J) * K)];
        double *piv;
        piv = new double DACE_ALIGN(64)[((I * J) * K)];

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        condensation_58_4_0_1_2(__state, RD, RV, lv[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], LSIGMAS, LSTATNW, sigs[((((J * K) * i) + (K * j)) + k)], sigqsat[((((J * K) * i) + (K * j)) + k)], rv0[((((J * K) * i) + (K * j)) + k)], rc0[((((J * K) * i) + (K * j)) + k)], ri0[((((J * K) * i) + (K * j)) + k)], OCND2, pv[((((J * K) * i) + (K * j)) + k)], ALPW, BETAW, GAMW, pabs[((((J * K) * i) + (K * j)) + k)], piv[((((J * K) * i) + (K * j)) + k)], ALPI, BETAI, GAMI, TMAXMIX, TMINMIX, cldfr[((((J * K) * i) + (K * j)) + k)], rc_out[((((J * K) * i) + (K * j)) + k)], ri_out[((((J * K) * i) + (K * j)) + k)], rv_out[((((J * K) * i) + (K * j)) + k)], sigrc[((((J * K) * i) + (K * j)) + k)], t[((((J * K) * i) + (K * j)) + k)], pv[((((J * K) * i) + (K * j)) + k)], piv[((((J * K) * i) + (K * j)) + k)], FRAC_ICE_ADJUST, LAMBDA3);
                    }
                }
            }
        }
        delete[] pv;
        delete[] piv;

    }
}

DACE_EXPORTED void __program_condensation(condensation_state_t *__state, double * __restrict__ cldfr, double * __restrict__ cph, double * __restrict__ ls, double * __restrict__ lv, double * __restrict__ pabs, double * __restrict__ rc0, double * __restrict__ rc_out, double * __restrict__ ri0, double * __restrict__ ri_out, double * __restrict__ rv0, double * __restrict__ rv_out, double * __restrict__ sigqsat, double * __restrict__ sigrc, double * __restrict__ sigs, double * __restrict__ t, double ALPI, double ALPW, double BETAI, double BETAW, bool FRAC_ICE_ADJUST, double GAMI, double GAMW, int I, int J, int K, bool LAMBDA3, bool LSIGMAS, bool LSTATNW, bool OCND2, double RD, double RV, double TMAXMIX, double TMINMIX)
{
    __program_condensation_internal(__state, cldfr, cph, ls, lv, pabs, rc0, rc_out, ri0, ri_out, rv0, rv_out, sigqsat, sigrc, sigs, t, ALPI, ALPW, BETAI, BETAW, FRAC_ICE_ADJUST, GAMI, GAMW, I, J, K, LAMBDA3, LSIGMAS, LSTATNW, OCND2, RD, RV, TMAXMIX, TMINMIX);
}

DACE_EXPORTED condensation_state_t *__dace_init_condensation(bool FRAC_ICE_ADJUST, int I, int J, int K, bool LAMBDA3)
{
    int __result = 0;
    condensation_state_t *__state = new condensation_state_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED int __dace_exit_condensation(condensation_state_t *__state)
{
    int __err = 0;
    delete __state;
    return __err;
}

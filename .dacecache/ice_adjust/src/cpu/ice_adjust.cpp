/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct ice_adjust_state_t {

};

inline void ice3_stencils_thermo_thermodynamic_fields_32_4_0_0_2(ice_adjust_state_t *__state, const double&  __tmp_33_21_r, const double&  __tmp_33_36_r, const double&  __tmp_34_22_r, const double&  __tmp_34_30_r, const double&  __tmp_34_36_r, const double&  __tmp_34_56_r, const double&  __tmp_35_22_r, const double&  __tmp_35_36_r, double&  __tmp_33_8_w, double&  __tmp_34_8_w, double&  __tmp_35_8_w) {

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
            double __in1 = __tmp_33_21_r;
            double __in2 = __tmp_33_36_r;
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
            // Tasklet code (assign_33_8)
            __out = __inp;
            ///////////////////

            __tmp_33_8_w = __out;
        }
        {
            double __in1 = __tmp_34_30_r;
            double __in2 = __tmp_34_36_r;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp2 = __out;
        }
        {
            double __in2 = __tmp_34_56_r;
            double __in1 = __tmp_33_8_w;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp3 = __out;
        }
        {
            double __in2 = __tmp3;
            double __in1 = __tmp2;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp4 = __out;
        }
        {
            double __in1 = __tmp_33_8_w;
            double __in2 = __tmp_34_56_r;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp7 = __out;
        }
        {
            double __in1 = __tmp_34_22_r;
            double __in2 = __tmp4;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp5 = __out;
        }
        {
            double __inp = __tmp5;
            double __out;

            ///////////////////
            // Tasklet code (assign_34_8)
            __out = __inp;
            ///////////////////

            __tmp_34_8_w = __out;
        }
        {
            double __in2 = __tmp_35_36_r;
            double __in1 = __tmp_34_30_r;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp6 = __out;
        }
        {
            double __in1 = __tmp6;
            double __in2 = __tmp7;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp8 = __out;
        }
        {
            double __in1 = __tmp_35_22_r;
            double __in2 = __tmp8;
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
            // Tasklet code (assign_35_8)
            __out = __inp;
            ///////////////////

            __tmp_35_8_w = __out;
        }

    }
}

inline void ice3_stencils_condensation_split_condensation_55_4_0_1_2(ice_adjust_state_t *__state, const double&  __tmp_103_31_r, const double&  __tmp_103_56_r, const double&  __tmp_107_27_r, const bool&  __tmp_111_11_r, const bool&  __tmp_111_27_r, const double&  __tmp_115_25_r, const double&  __tmp_116_23_r, const double&  __tmp_60_22_r, const double&  __tmp_60_36_r, const double&  __tmp_60_50_r, const bool&  __tmp_63_15_r, const double&  __tmp_64_33_r, const double&  __tmp_64_40_r, const double&  __tmp_64_48_r, const double&  __tmp_64_61_r, const double&  __tmp_67_19_r, const double&  __tmp_70_34_r, const double&  __tmp_70_41_r, const double&  __tmp_70_62_r, const double&  __tmp_90_37_r, const double&  __tmp_90_72_r, const double&  __tmp_98_14_r, const double&  __tmp_98_19_r, double&  __tmp_140_16_w, double&  __tmp_151_16_w, double&  __tmp_152_16_w, double&  __tmp_153_16_w, double&  __tmp_160_12_w) {
    double __tmp_60_8_w;
    double __tmp_64_12_w;
    double __tmp_70_12_w;
    double __tmp30;
    double __tmp35;
    double __tmp91;
    double __tmp95;
    double qsl;
    double a;
    double sbar;
    double sigma;
    int64_t frac_tmp;
    bool __tmp9;
    bool __tmp26;
    int64_t __tmp46;
    int64_t __tmp50;
    bool __tmp75;
    bool __tmp76;
    double q1;
    double cond_tmp;
    bool __tmp102;
    bool __tmp103;
    double __tmp27;


    frac_tmp = 0;
    __tmp9 = (! __tmp_63_15_r);
    {
        double __tmp6;
        double __tmp7;
        double __tmp8;

        {
            double __in1 = __tmp_60_22_r;
            double __in2 = __tmp_60_36_r;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp6 = __out;
        }
        {
            double __in1 = __tmp_60_50_r;
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
            // Tasklet code (assign_60_8)
            __out = __inp;
            ///////////////////

            __tmp_60_8_w = __out;
        }

    }
    if (__tmp9) {
        {
            double __tmp10;
            double __tmp11;
            double __tmp12;
            double __tmp13;
            double __tmp14;
            double __tmp15;
            double __tmp16;
            double __tmp17;
            double __tmp18;
            double __tmp19;
            double __tmp20;
            double __tmp21;
            double __tmp22;
            double __tmp23;
            double __tmp24;
            double __tmp25;

            {
                double __in1 = __tmp_64_40_r;
                double __in2 = __tmp_64_48_r;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp10 = __out;
            }
            {
                double __in1 = __tmp_64_48_r;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_log_)
                __out = log(__in1);
                ///////////////////

                __tmp12 = __out;
            }
            {
                double __in1 = __tmp_64_33_r;
                double __in2 = __tmp10;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp11 = __out;
            }
            {
                double __in1 = __tmp_64_61_r;
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
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp14 = __out;
            }
            {
                double __in1 = __tmp14;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_exp_)
                __out = exp(__in1);
                ///////////////////

                __tmp15 = __out;
            }
            {
                double __inp = __tmp15;
                double __out;

                ///////////////////
                // Tasklet code (assign_64_12)
                __out = __inp;
                ///////////////////

                __tmp_64_12_w = __out;
            }
            {
                double __in2 = __tmp_67_19_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (0.99 * __in2);
                ///////////////////

                __tmp16 = __out;
            }
            {
                double __in_b = __tmp16;
                double __in_a = __tmp_64_12_w;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(__in_a, __in_b);
                ///////////////////

                __tmp17 = __out;
            }
            {
                double __inp = __tmp17;
                double __out;

                ///////////////////
                // Tasklet code (assign_65_12)
                __out = __inp;
                ///////////////////

                __tmp_64_12_w = __out;
            }
            {
                double __in1 = __tmp_64_48_r;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_log_)
                __out = log(__in1);
                ///////////////////

                __tmp20 = __out;
            }
            {
                double __in2 = __tmp_67_19_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (0.99 * __in2);
                ///////////////////

                __tmp24 = __out;
            }
            {
                double __in1 = __tmp_70_41_r;
                double __in2 = __tmp_64_48_r;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp18 = __out;
            }
            {
                double __in1 = __tmp_70_34_r;
                double __in2 = __tmp18;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp19 = __out;
            }
            {
                double __in1 = __tmp_70_62_r;
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
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp22 = __out;
            }
            {
                double __in1 = __tmp22;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_exp_)
                __out = exp(__in1);
                ///////////////////

                __tmp23 = __out;
            }
            {
                double __inp = __tmp23;
                double __out;

                ///////////////////
                // Tasklet code (assign_70_12)
                __out = __inp;
                ///////////////////

                __tmp_70_12_w = __out;
            }
            {
                double __in_b = __tmp24;
                double __in_a = __tmp_70_12_w;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(__in_a, __in_b);
                ///////////////////

                __tmp25 = __out;
            }
            {
                double __inp = __tmp25;
                double __out;

                ///////////////////
                // Tasklet code (assign_71_12)
                __out = __inp;
                ///////////////////

                __tmp_70_12_w = __out;
            }

        }
        __tmp26 = (! __tmp_63_15_r);

    } else {

        __tmp26 = (! __tmp_63_15_r);

    }

    if ((! __tmp26)) {

        __tmp46 = (1 - 0);
        __tmp50 = (1 - 0);
        __tmp75 = (! __tmp_111_27_r);

    } else {

        __tmp27 = (__tmp_60_36_r + __tmp_60_50_r);

        if ((__tmp27 > 1e-20)) {
            {
                double __tmp29;

                {
                    double __in1 = __tmp_60_36_r;
                    double __in2 = __tmp_60_50_r;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp29 = __out;
                }
                {
                    double __in1 = __tmp_60_36_r;
                    double __in2 = __tmp29;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Div_)
                    __out = (__in1 / __in2);
                    ///////////////////

                    __tmp30 = __out;
                }

            }
            frac_tmp = __tmp30;

        } else {

            frac_tmp = 0;

        }
        {
            double __tmp31;
            double __tmp32;
            double __tmp33;
            double __tmp34;

            {
                double __in1 = __tmp_90_37_r;
                double __in2 = __tmp_64_48_r;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp31 = __out;
            }
            {
                double __in2 = __tmp_90_72_r;
                double __in1 = __tmp_90_37_r;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp32 = __out;
            }
            {
                double __in2 = __tmp32;
                double __in1 = __tmp31;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp33 = __out;
            }
            {
                double __in_b = __tmp33;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(double(1), __in_b);
                ///////////////////

                __tmp34 = __out;
            }
            {
                double __in_b = __tmp34;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(double(0), __in_b);
                ///////////////////

                __tmp35 = __out;
            }

        }
        frac_tmp = __tmp35;

        __tmp46 = (1 - frac_tmp);
        __tmp50 = (1 - frac_tmp);
        __tmp75 = (! __tmp_111_27_r);

    }
    {
        double __tmp38;
        double __tmp39;
        double __tmp40;
        double __tmp42;
        double __tmp43;
        double __tmp44;
        double __tmp47;
        double __tmp48;
        double __tmp49;
        double __tmp51;
        double __tmp52;
        double __tmp54;
        double __tmp55;
        double __tmp56;
        double __tmp57;
        double __tmp58;
        double __tmp59;
        double __tmp60;
        double __tmp62;
        double __tmp63;
        double __tmp64;
        double __tmp67;
        double __tmp68;
        double __tmp69;
        double __tmp70;
        double __tmp71;
        double __tmp72;
        double __tmp73;
        double qsi;
        double lvs;
        double ah;

        {
            double __in1 = __tmp_98_14_r;
            double __in2 = __tmp_98_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp38 = __out;
        }
        {
            double __in1 = __tmp_98_14_r;
            double __in2 = __tmp_98_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp42 = __out;
        }
        {
            double __in2 = __tmp_64_12_w;
            double __in1 = __tmp38;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp39 = __out;
        }
        {
            double __in1 = __tmp_67_19_r;
            double __in2 = __tmp_64_12_w;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp40 = __out;
        }
        {
            double __in2 = __tmp40;
            double __in1 = __tmp39;
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
            __out = (double(__tmp46) * __in2);
            ///////////////////

            __tmp47 = __out;
        }
        {
            double __in2 = __tmp_70_12_w;
            double __in1 = __tmp42;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp43 = __out;
        }
        {
            double __in2 = __tmp_70_12_w;
            double __in1 = __tmp_67_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp44 = __out;
        }
        {
            double __in2 = __tmp44;
            double __in1 = __tmp43;
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

            __tmp48 = __out;
        }
        {
            double __in2 = __tmp48;
            double __in1 = __tmp47;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp49 = __out;
        }
        {
            double __inp = __tmp49;
            double __out;

            ///////////////////
            // Tasklet code (assign_102_8)
            __out = __inp;
            ///////////////////

            qsl = __out;
        }
        {
            double __in2 = qsl;
            double __in1 = __tmp_98_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp58 = __out;
        }
        {
            double __in1 = __tmp58;
            double __in2 = __tmp_98_14_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp59 = __out;
        }
        {
            double __in2 = __tmp59;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (double(1) + __in2);
            ///////////////////

            __tmp60 = __out;
        }
        {
            double __in2 = __tmp_103_31_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (double(__tmp50) * __in2);
            ///////////////////

            __tmp51 = __out;
        }
        {
            double __in2 = __tmp_103_56_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (double(frac_tmp) * __in2);
            ///////////////////

            __tmp52 = __out;
        }
        {
            double __in2 = __tmp52;
            double __in1 = __tmp51;
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

            __tmp54 = __out;
        }
        {
            double __in1 = __tmp_64_48_r;
            double __out;

            ///////////////////
            // Tasklet code (_Pow_)
            __out = (dace::math::ipow(__in1, 2));
            ///////////////////

            __tmp55 = __out;
        }
        {
            double __in2 = __tmp55;
            double __in1 = __tmp_98_19_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp56 = __out;
        }
        {
            double __in2 = __tmp56;
            double __in1 = __tmp54;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp57 = __out;
        }
        {
            double __in2 = __tmp60;
            double __in1 = __tmp57;
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

            __tmp68 = __out;
        }
        {
            double __in2 = __tmp_107_27_r;
            double __in1 = lvs;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp62 = __out;
        }
        {
            double __in1 = __tmp62;
            double __in2 = ah;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp63 = __out;
        }
        {
            double __in2 = __tmp63;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (double(1) + __in2);
            ///////////////////

            __tmp64 = __out;
        }
        {
            double __in2 = __tmp64;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (double(1) / __in2);
            ///////////////////

            a = __out;
        }
        {
            double __in1 = __tmp_60_8_w;
            double __in2 = qsl;
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (__in1 - __in2);
            ///////////////////

            __tmp67 = __out;
        }
        {
            double __in1 = __tmp_60_50_r;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * double(1));
            ///////////////////

            __tmp69 = __out;
        }
        {
            double __in1 = __tmp_60_36_r;
            double __in2 = __tmp69;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp70 = __out;
        }
        {
            double __in2 = __tmp70;
            double __in1 = __tmp68;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            __tmp71 = __out;
        }
        {
            double __in1 = __tmp71;
            double __in2 = __tmp_107_27_r;
            double __out;

            ///////////////////
            // Tasklet code (_Div_)
            __out = (__in1 / __in2);
            ///////////////////

            __tmp72 = __out;
        }
        {
            double __in2 = __tmp72;
            double __in1 = __tmp67;
            double __out;

            ///////////////////
            // Tasklet code (_Add_)
            __out = (__in1 + __in2);
            ///////////////////

            __tmp73 = __out;
        }
        {
            double __in2 = __tmp73;
            double __in1 = a;
            double __out;

            ///////////////////
            // Tasklet code (_Mult_)
            __out = (__in1 * __in2);
            ///////////////////

            sbar = __out;
        }

    }
    __tmp76 = (__tmp_111_11_r && __tmp75);

    if (__tmp76) {
        {
            double __tmp77;
            double __tmp78;
            double __tmp79;
            double __tmp80;
            double __tmp81;
            double __tmp82;
            double __tmp83;

            {
                double __in2 = __tmp_115_25_r;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double(2) * __in2);
                ///////////////////

                __tmp77 = __out;
            }
            {
                double __in1 = __tmp77;
                double __out;

                ///////////////////
                // Tasklet code (_Pow_)
                __out = (dace::math::ipow(__in1, 2));
                ///////////////////

                __tmp78 = __out;
            }
            {
                double __in1 = __tmp_116_23_r;
                double __in2 = qsl;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp79 = __out;
            }
            {
                double __in2 = a;
                double __in1 = __tmp79;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp80 = __out;
            }
            {
                double __in1 = __tmp80;
                double __out;

                ///////////////////
                // Tasklet code (_Pow_)
                __out = (dace::math::ipow(__in1, 2));
                ///////////////////

                __tmp81 = __out;
            }
            {
                double __in2 = __tmp81;
                double __in1 = __tmp78;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp82 = __out;
            }
            {
                double __in1 = __tmp82;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_sqrt_)
                __out = sqrt(__in1);
                ///////////////////

                __tmp83 = __out;
            }
            {
                double __in_b = __tmp83;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(1e-10, __in_b);
                ///////////////////

                sigma = __out;
            }

        }
        q1 = (sbar / sigma);

    } else {

        q1 = (sbar / sigma);

    }

    if ((! (q1 > 0.0))) {
        {
            double __tmp93;
            double __tmp94;

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (1.2 * q1);
                ///////////////////

                __tmp93 = __out;
            }
            {
                double __in1 = __tmp93;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - 1.0);
                ///////////////////

                __tmp94 = __out;
            }
            {
                double __in1 = __tmp94;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_exp_)
                __out = exp(__in1);
                ///////////////////

                __tmp95 = __out;
            }

        }
        cond_tmp = __tmp95;

    } else {

        if ((q1 <= 2.0)) {
            {
                double __tmp86;
                double __tmp87;
                double __tmp88;
                double __tmp89;
                double __tmp90;

                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_exp_)
                    __out = exp(-1.0);
                    ///////////////////

                    __tmp86 = __out;
                }
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (0.66 * q1);
                    ///////////////////

                    __tmp87 = __out;
                }
                {
                    double __in1 = __tmp86;
                    double __in2 = __tmp87;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp88 = __out;
                }
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_Pow_)
                    __out = (dace::math::ipow(q1, 2));
                    ///////////////////

                    __tmp89 = __out;
                }
                {
                    double __in2 = __tmp89;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Mult_)
                    __out = (0.086 * __in2);
                    ///////////////////

                    __tmp90 = __out;
                }
                {
                    double __in2 = __tmp90;
                    double __in1 = __tmp88;
                    double __out;

                    ///////////////////
                    // Tasklet code (_Add_)
                    __out = (__in1 + __in2);
                    ///////////////////

                    __tmp91 = __out;
                }

            }
            cond_tmp = min(__tmp91, 2);

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
                // Tasklet code (assign_144_16)
                __out = 0;
                ///////////////////

                __tmp_140_16_w = __out;
            }

        }
        __tmp102 = (__tmp_140_16_w == 0);

    } else {
        {
            double __tmp96;
            double __tmp97;
            double __tmp98;
            double __tmp99;
            double __tmp100;
            double __tmp101;

            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (1.55 * q1);
                ///////////////////

                __tmp96 = __out;
            }
            {
                double __in1 = __tmp96;
                double __out;

                ///////////////////
                // Tasklet code (_numpy_arctan_)
                __out = atan(__in1);
                ///////////////////

                __tmp97 = __out;
            }
            {
                double __in2 = __tmp97;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (0.36 * __in2);
                ///////////////////

                __tmp98 = __out;
            }
            {
                double __in2 = __tmp98;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (0.5 + __in2);
                ///////////////////

                __tmp99 = __out;
            }
            {
                double __in_b = __tmp99;
                double __out;

                ///////////////////
                // Tasklet code (__min2)
                __out = min(1, __in_b);
                ///////////////////

                __tmp100 = __out;
            }
            {
                double __in_b = __tmp100;
                double __out;

                ///////////////////
                // Tasklet code (__max2)
                __out = max(0, __in_b);
                ///////////////////

                __tmp101 = __out;
            }
            {
                double __inp = __tmp101;
                double __out;

                ///////////////////
                // Tasklet code (assign_140_16)
                __out = __inp;
                ///////////////////

                __tmp_140_16_w = __out;
            }

        }
        __tmp102 = (__tmp_140_16_w == 0);

    }

    if (__tmp102) {

        cond_tmp = 0;
        __tmp103 = (! __tmp_63_15_r);

    } else {

        __tmp103 = (! __tmp_63_15_r);

    }

    if (__tmp103) {
        {
            double __tmp105;
            double __tmp106;
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
                __out = (double((1 - frac_tmp)) * cond_tmp);
                ///////////////////

                __tmp105 = __out;
            }
            {
                double __inp = __tmp105;
                double __out;

                ///////////////////
                // Tasklet code (assign_151_16)
                __out = __inp;
                ///////////////////

                __tmp_151_16_w = __out;
            }
            {
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (double(frac_tmp) * cond_tmp);
                ///////////////////

                __tmp106 = __out;
            }
            {
                double __inp = __tmp106;
                double __out;

                ///////////////////
                // Tasklet code (assign_152_16)
                __out = __inp;
                ///////////////////

                __tmp_152_16_w = __out;
            }
            {
                double __in2 = __tmp_60_36_r;
                double __in1 = __tmp_151_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp107 = __out;
            }
            {
                double __in2 = __tmp_103_31_r;
                double __in1 = __tmp107;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp108 = __out;
            }
            {
                double __in2 = __tmp_60_50_r;
                double __in1 = __tmp_152_16_w;
                double __out;

                ///////////////////
                // Tasklet code (_Sub_)
                __out = (__in1 - __in2);
                ///////////////////

                __tmp109 = __out;
            }
            {
                double __in2 = __tmp_103_56_r;
                double __in1 = __tmp109;
                double __out;

                ///////////////////
                // Tasklet code (_Mult_)
                __out = (__in1 * __in2);
                ///////////////////

                __tmp110 = __out;
            }
            {
                double __in2 = __tmp110;
                double __in1 = __tmp108;
                double __out;

                ///////////////////
                // Tasklet code (_Add_)
                __out = (__in1 + __in2);
                ///////////////////

                __tmp111 = __out;
            }
            {
                double __in2 = __tmp_107_27_r;
                double __in1 = __tmp111;
                double __out;

                ///////////////////
                // Tasklet code (_Div_)
                __out = (__in1 / __in2);
                ///////////////////

                __tmp112 = __out;
            }
            {
                double __inp = __tmp112;
                double __out;

                ///////////////////
                // Tasklet code (assign_153_16)
                __out = __inp;
                ///////////////////

                dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce(&__tmp_153_16_w, __out);
            }

        }

    }
    {
        double __tmp116;
        double __tmp117;
        double __tmp118;

        {
            double __out;

            ///////////////////
            // Tasklet code (_Sub_)
            __out = (double(1) - q1);
            ///////////////////

            __tmp116 = __out;
        }
        {
            double __in_b = __tmp116;
            double __out;

            ///////////////////
            // Tasklet code (__max2)
            __out = max(double(1), __in_b);
            ///////////////////

            __tmp117 = __out;
        }
        {
            double __in_b = __tmp117;
            double __out;

            ///////////////////
            // Tasklet code (__min2)
            __out = min(double(3), __in_b);
            ///////////////////

            __tmp118 = __out;
        }
        {
            double __inp = __tmp118;
            double __out;

            ///////////////////
            // Tasklet code (assign_160_12)
            __out = __inp;
            ///////////////////

            dace::wcr_fixed<dace::ReductionType::Product, double>::reduce(&__tmp_160_12_w, __out);
        }

    }
}

inline void ice3_stencils_cloud_fraction_split_cloud_fraction_1_32_4_0_1_33(ice_adjust_state_t *__state, const double&  __tmp_34_14_r, const double&  __tmp_34_32_r, const double&  __tmp_34_47_r, const double&  __tmp_35_14_r, const double&  __tmp_35_32_r, const double&  __tmp_39_26_r, const double&  __tmp_41_25_r, const double&  __tmp_44_30_r, const double&  __tmp_44_45_r, const double&  __tmp_44_60_r, const double&  __tmp_47_26_r, const double&  __tmp_52_24_r, const double&  __tmp_52_45_r, double&  __tmp_42_8_w, double&  __tmp_43_8_w, double&  __tmp_44_8_w, double&  __tmp_51_8_w) {
    double __tmp6;
    double __tmp12;
    double __tmp1;
    double w1;
    double __tmp3;
    double w2;
    double __tmp13;
    double __tmp7;


    __tmp1 = (__tmp_34_14_r - __tmp_34_32_r);

    w1 = (__tmp1 / __tmp_34_47_r);
    __tmp3 = (__tmp_35_14_r - __tmp_35_32_r);

    w2 = (__tmp3 / __tmp_34_47_r);

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

void __program_ice_adjust_internal(ice_adjust_state_t*__state, double * __restrict__ cldfr, double * __restrict__ exn, double * __restrict__ pabs, double * __restrict__ rc0, double * __restrict__ rcs0, double * __restrict__ rcs1, double * __restrict__ rg0, double * __restrict__ ri0, double * __restrict__ ris0, double * __restrict__ ris1, double * __restrict__ rr0, double * __restrict__ rs0, double * __restrict__ rv0, double * __restrict__ rvs0, double * __restrict__ rvs1, double * __restrict__ sigqsat, double * __restrict__ sigrc, double * __restrict__ sigs, double * __restrict__ th0, double * __restrict__ ths0, double * __restrict__ ths1, double ALPI, double ALPW, double BETAI, double BETAW, double CI, double CL, double CPD, double CPV, double GAMI, double GAMW, int I, int J, int K, bool LSIGMAS, bool LSTATNW, double LSTT, double LVTT, bool OCND2, double RD, double RV, double TMAXMIX, double TMINMIX, double TT, double dt)
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

    {

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        ice3_stencils_thermo_thermodynamic_fields_32_4_0_0_2(__state, exn[((((J * K) * i) + (K * j)) + k)], th0[((((J * K) * i) + (K * j)) + k)], LVTT, CPV, CL, TT, LSTT, CI, t[((((J * K) * i) + (K * j)) + k)], lv[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)]);
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
                            // Tasklet code (assign_40_12)
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
                            // Tasklet code (assign_49_8)
                            __out = 0.0;
                            ///////////////////

                            cldfr[((((J * K) * i) + (K * j)) + k)] = __out;
                        }
                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_51_8)
                            __out = 0.0;
                            ///////////////////

                            rc_out[((((J * K) * i) + (K * j)) + k)] = __out;
                        }
                        {
                            double __out;

                            ///////////////////
                            // Tasklet code (assign_52_8)
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

        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        ice3_stencils_condensation_split_condensation_55_4_0_1_2(__state, lv[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], LSIGMAS, LSTATNW, sigs[((((J * K) * i) + (K * j)) + k)], sigqsat[((((J * K) * i) + (K * j)) + k)], rv0[((((J * K) * i) + (K * j)) + k)], rc0[((((J * K) * i) + (K * j)) + k)], ri0[((((J * K) * i) + (K * j)) + k)], OCND2, ALPW, BETAW, t[((((J * K) * i) + (K * j)) + k)], GAMW, pabs[((((J * K) * i) + (K * j)) + k)], ALPI, BETAI, GAMI, TMAXMIX, TMINMIX, RD, RV, cldfr[((((J * K) * i) + (K * j)) + k)], rc_out[((((J * K) * i) + (K * j)) + k)], ri_out[((((J * K) * i) + (K * j)) + k)], t[((((J * K) * i) + (K * j)) + k)], sigrc[((((J * K) * i) + (K * j)) + k)]);
                    }
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto i = 0; i < I; i += 1) {
                for (auto j = 0; j < J; j += 1) {
                    for (auto k = 0; k < K; k += 1) {
                        ice3_stencils_cloud_fraction_split_cloud_fraction_1_32_4_0_1_33(__state, rc_out[((((J * K) * i) + (K * j)) + k)], rc0[((((J * K) * i) + (K * j)) + k)], dt, ri_out[((((J * K) * i) + (K * j)) + k)], ri0[((((J * K) * i) + (K * j)) + k)], rcs0[((((J * K) * i) + (K * j)) + k)], rvs0[((((J * K) * i) + (K * j)) + k)], lv[((((J * K) * i) + (K * j)) + k)], cph[((((J * K) * i) + (K * j)) + k)], exn[((((J * K) * i) + (K * j)) + k)], ris0[((((J * K) * i) + (K * j)) + k)], ths0[((((J * K) * i) + (K * j)) + k)], ls[((((J * K) * i) + (K * j)) + k)], rvs1[((((J * K) * i) + (K * j)) + k)], rcs1[((((J * K) * i) + (K * j)) + k)], ths1[((((J * K) * i) + (K * j)) + k)], ris1[((((J * K) * i) + (K * j)) + k)]);
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

DACE_EXPORTED void __program_ice_adjust(ice_adjust_state_t *__state, double * __restrict__ cldfr, double * __restrict__ exn, double * __restrict__ pabs, double * __restrict__ rc0, double * __restrict__ rcs0, double * __restrict__ rcs1, double * __restrict__ rg0, double * __restrict__ ri0, double * __restrict__ ris0, double * __restrict__ ris1, double * __restrict__ rr0, double * __restrict__ rs0, double * __restrict__ rv0, double * __restrict__ rvs0, double * __restrict__ rvs1, double * __restrict__ sigqsat, double * __restrict__ sigrc, double * __restrict__ sigs, double * __restrict__ th0, double * __restrict__ ths0, double * __restrict__ ths1, double ALPI, double ALPW, double BETAI, double BETAW, double CI, double CL, double CPD, double CPV, double GAMI, double GAMW, int I, int J, int K, bool LSIGMAS, bool LSTATNW, double LSTT, double LVTT, bool OCND2, double RD, double RV, double TMAXMIX, double TMINMIX, double TT, double dt)
{
    __program_ice_adjust_internal(__state, cldfr, exn, pabs, rc0, rcs0, rcs1, rg0, ri0, ris0, ris1, rr0, rs0, rv0, rvs0, rvs1, sigqsat, sigrc, sigs, th0, ths0, ths1, ALPI, ALPW, BETAI, BETAW, CI, CL, CPD, CPV, GAMI, GAMW, I, J, K, LSIGMAS, LSTATNW, LSTT, LVTT, OCND2, RD, RV, TMAXMIX, TMINMIX, TT, dt);
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

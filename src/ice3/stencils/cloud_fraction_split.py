# -*- coding: utf-8 -*-
from __future__ import annotations

import numpy as np

import dace
from dace.dtypes import StorageType, ScheduleType

from ice3.utils.typingx import dtype_float, dtype_int
from ice3.functions.ice_adjust import sublimation_latent_heat, vaporisation_latent_heat

I, J, K = (dace.symbol(s) for s in ['I', 'J', 'K'])


@dace.program
def thermodynamic_fields(
    th: dtype_float[I, J, K] ,
    exn: dtype_float[I, J, K] ,
    rv: dtype_float[I, J, K] @ StorageType.GPU_Global,
    rc: dtype_float[I, J, K] @ StorageType.GPU_Global,
    rr: dtype_float[I, J, K] @ StorageType.GPU_Global,
    ri: dtype_float[I, J, K] @ StorageType.GPU_Global,
    rs: dtype_float[I, J, K] @ StorageType.GPU_Global,
    rg: dtype_float[I, J, K] @ StorageType.GPU_Global,
    lv: dtype_float[I, J, K] @ StorageType.GPU_Global,
    ls: dtype_float[I, J, K] @ StorageType.GPU_Global,
    cph: dtype_float[I, J, K] @ StorageType.GPU_Global,
    NRR: dtype_float,
    CPD: dtype_float,
    CPV: dtype_float,
    CL: dtype_float,
    CI: dtype_float
):

    # 2.3 Compute the variation of mixing ratio
    for i, j, k in dace.map[0:I, 0:J, 0:K] @ ScheduleType.GPU_Device:
        t[i, j, k] = exn[i, j, k] * th[i, j, k]
        vaporisation_latent_heat(lv[i, j, k], t[i, j, k])
        sublimation_latent_heat(ls[i, j, k], t[i, j, k])

    # 2.4 specific heat for moist air at t+1
    for i, j, k in dace.map[0:I, 0:J, 0:K] @ ScheduleType.GPU_Device:
        if NRR == 6:
            cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k]) + CI * (ri[i, j, k] + rs[i, j, k] + rg[i, j, k])
        # if NRR == 5:
        #     cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k]) + CI * (ri[i, j, k] + rs[i, j, k])
        # if NRR == 4:
        #     cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k])
        # if NRR == 2:
        #     cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * rc[i, j, k] + CI * ri[i, j, k]

    return t, ls, lv, cph


@dace.program
def cloud_fraction_1(
    lv: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ls: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    cph: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    exnref: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rc: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ri: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rc_tmp: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ri_tmp: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ths0: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rvs0: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rcs0: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ris0: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ths1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rvs1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rcs1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ris1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    dt: dtype_float,
):
    """Cloud fraction computation (after condensation loop)"""

    ##### 5.     COMPUTE THE SOURCES AND STORES THE CLOUD FRACTION #####
    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        # 5.0 compute the variation of mixing ratio
        w1 = (rc_tmp[i, j, k] - rc[i, j, k]) / dt
        w2 = (ri_tmp[i, j, k] - ri[i, j, k]) / dt

        # 5.1 compute the sources
        w1 = max(w1, -rcs0[i, j, k]) if w1 < 0.0 else min(w1, rvs0[i, j, k])
        rvs1[i, j, k] -= w1[i, j, k]
        rcs1[i, j, k] += w1[i, j, k]
        ths1[i, j, k] += w1[i, j, k] * lv[i, j, k] / (cph[i, j, k] * exnref[i, j, k])

        w2 = max(w2, -ris0[i, j, k]) if w2 < 0.0 else min(w2, rvs0[i, j, k])
        rvs1[i, j, k] = rvs0[i, j, k] + w2
        ris1[i, j, k] = ris0[i, j, k] + w2
        ths1[i, j, k] = ths0[i, j, k] + w2 * ls[i, j, k] / (cph[i, j, k] * exnref[i, j, k])

        #### split


@dace.program
def cloud_fraction_2(
    rhodref: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    exnref: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    t: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    cph: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    lv: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ls: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ths1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rvs1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rcs1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ris1: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    rc_mf: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    ri_mf: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    cf_mf: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    cldfr: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    hlc_hrc: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    hlc_hcf: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    hli_hri: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    hli_hcf: dtype_float[I, J, K] @ ScheduleType.GPU_Device,
    dt: dtype_float,
    ext: dace.compiletime
):

    # 5.2  compute the cloud fraction cldfr
    for i, j, k in dace.map[0:I, 0:J, 0:K]:

        if not ext.LSUBG_COND:
            cldfr[i, j, k] = 1.0 if (([i, j, k] + ris1[i, j, k])*dt > 1e-12) else 0.0

        else:
            w1 = rc_mf[i, j, k] / dt
            w2 = ri_mf[i, j, k] / dt

            if w1 + w2 > rvs1[i, j, k]:
                w1 *= rvs1[i, j, k] / (w1 + w2)
                w2 = rvs1[i, j, k] - w1

            cldfr[i, j, k] = min(1, cldfr[i, j, k] + cf_mf[i, j, k])
            rcs1[i, j, k] += w1
            ris1[i, j, k] += w2
            rvs1[i, j, k] -= (w1 + w2)
            ths1[i, j, k] += (w1 * lv[i, j, k] + w2 * ls[i, j, k]) / (cph[i, j, k] * exnref[i, j, k])

            criaut = ext.CRIAUTC / rhodref[i, j, k]

            if ext.SUBG_MF_PDF == 0:
                if w1 * dt > cf_mf[i, j, k] * criaut:
                    hlc_hrc[i, j, k] += w1 * dt
                    hlc_hcf[i, j, k] = min(1.0, hlc_hcf[i, j, k] + cf_mf[i, j, k])

            if ext.SUBG_MF_PDF == 1:
                if w1 * dt > cf_mf[i, j, k] * criaut:
                    hcf = 1.0 - 0.5 * (criaut * cf_mf[i, j, k] / max(1e-20, w1 * dt)) ** 2
                    hr = w1 * dt - (criaut * cf_mf[i, j, k]) ** 3 / (
                        3 * max(1e-20, w1 * dt) ** 2
                    )

                elif 2.0 * w1 * dt <= cf_mf[i, j, k] * criaut:
                    hcf = 0.0
                    hr = 0.0

                else:
                    hcf = (2.0 * w1 * dt - criaut * cf_mf[i, j, k]) ** 2 / (
                        2.0 * max(1.0e-20, w1 * dt) ** 2
                    )
                    hr = (
                        4.0 * (w1 * dt) ** 3
                        - 3.0 * w1 * dt * (criaut * cf_mf[i, j, k]) ** 2
                        + (criaut * cf_mf[i, j, k] ** 3)
                    ) / (3 * max(1.0e-20, w1 * dt) ** 2)

                hcf *= cf_mf[i, j, k]
                hlc_hcf[i, j, k] = min(1.0, hlc_hcf[i, j, k] + hcf)
                hlc_hrc[i, j, k] += hr

            # Ice subgrid autoconversion
            criaut = min(
                ext.CRIAUTI,
                10 ** (ext.ACRIAUTI * (t[i, j, k] - ext.TT) + ext.BCRIAUTI),
            )

            # LLNONE in ice_adjust.F90
            if ext.SUBG_MF_PDF == 0:
                if w2 * dt > cf_mf * criaut:
                    hli_hri[i, j, k] += w2 * dt
                    hli_hcf[i, j, k] = min(1.0, hli_hcf[i, j, k] + cf_mf[i, j, k])

            # LLTRIANGLE in ice_adjust.F90
            if ext.SUBG_MF_PDF == 1:
                if w2 * dt > cf_mf[i, j, k] * criaut:
                    hcf = 1.0 - 0.5 * ((criaut * cf_mf[i, j, k]) / (w2 * dt)) ** 2
                    hri = w2 * dt - (criaut * cf_mf[i, j, k]) ** 3 / (3 * (w2 * dt) ** 2)

                elif 2 * w2 * dt <= cf_mf[i, j, k] * criaut:
                    hcf = 0.0
                    hri = 0.0

                else:
                    hcf = (2.0 * w2 * dt - criaut * cf_mf[i, j, k]) ** 2 / (
                        2.0 * (w2 * dt) ** 2
                    )
                    hri = (
                        4.0 * (w2 * dt) ** 3
                        - 3.0 * w2 * dt * (criaut * cf_mf[i, j, k]) ** 2
                        + (criaut * cf_mf[i, j, k]) ** 3
                    ) / (3.0 * (w2 * dt) ** 2)

                hcf *= cf_mf[i, j, k]
                hli_hcf[i, j, k] = min(1.0, hli_hcf[i, j, k] + hcf)
                hli_hri[i, j, k] += hri


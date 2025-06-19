# -*- coding: utf-8 -*-
from __future__ import annotations

import dace
from gt4py.cartesian.gtscript import PARALLEL, computation, interval, Field, __INLINED
from ifs_physics_common.framework.stencil import stencil_collection
from ifs_physics_common.utils.f2py import ported_method

from ice3_gt4py.functions.ice_adjust import sublimation_latent_heat, vaporisation_latent_heat


@dace.program
def thermodynamic_fields(
    th: Field["float"],
    exn: Field["float"],
    rv: Field["float"],
    rc: Field["float"],
    rr: Field["float"],
    ri: Field["float"],
    rs: Field["float"],
    rg: Field["float"],
    lv: Field["float"],
    ls: Field["float"],
    cph: Field["float"],
    t: Field["float"],
):
    from __externals__ import NRR, CPV, CPD, CL, CI

    # 2.3 Compute the variation of mixing ratio
    with computation(PARALLEL), interval(...):
        t = th * exn
        lv = vaporisation_latent_heat(t)
        ls = sublimation_latent_heat(t)

    # Translation note : in Fortran, ITERMAX = 1, DO JITER =1,ITERMAX
    # Translation note : version without iteration is kept (1 iteration)
    #                   IF jiter = 1; CALL ITERATION()
    # jiter > 0

    # numer of moist variables fixed to 6 (without hail)

    # Translation note :
    # 2.4 specific heat for moist air at t+1
    with computation(PARALLEL), interval(...):
        # Translation note : case(7) removed because hail is not taken into account
        # Translation note : l453 to l456 removed
        if __INLINED(NRR == 6):
            cph = CPD + CPV * rv + CL * (rc + rr) + CI * (ri + rs + rg)
        if __INLINED(NRR == 5):
            cph = CPD + CPV * rv + CL * (rc + rr) + CI * (ri + rs)
        if __INLINED(NRR == 4):
            cph = CPD + CPV * rv + CL * (rc + rr)
        if __INLINED(NRR == 2):
            cph = CPD + CPV * rv + CL * rc + CI * ri


@dace.program
def cloud_fraction_1(
    lv: Field["float"],
    ls: Field["float"],
    cph: Field["float"],
    exnref: Field["float"],
    rc: Field["float"],
    ri: Field["float"],
    rc_tmp: Field["float"],
    ri_tmp: Field["float"],
    ths0: Field["float"],
    rvs0: Field["float"],
    rcs0: Field["float"],
    ris0: Field["float"],
    ths1: Field["float"],
    rvs1: Field["float"],
    rcs1: Field["float"],
    ris1: Field["float"],
    dt: "float",
):
    """Cloud fraction computation (after condensation loop)"""
    # l274 in ice_adjust.F90
    ##### 5.     COMPUTE THE SOURCES AND STORES THE CLOUD FRACTION #####
    with computation(PARALLEL), interval(...):
        # 5.0 compute the variation of mixing ratio
        w1 = (rc_tmp - rc) / dt
        w2 = (ri_tmp - ri) / dt

        # 5.1 compute the sources
        w1 = max(w1, -rcs0) if w1 < 0.0 else min(w1, rvs0)
        rvs1 -= w1
        rcs1 += w1
        ths1 += w1 * lv / (cph * exnref)

        w2 = max(w2, -ris0) if w2 < 0.0 else min(w2, rvs0)
        rvs1 = rvs0 + w2
        ris1 = ris0 + w2
        ths1 = ths0 + w2 * ls / (cph * exnref)
        
        #### split
    

@dace.program
def cloud_fraction_2(
    rhodref: Field["float"],
    exnref: Field["float"],
    t: Field["float"],
    cph: Field["float"],
    lv: Field["float"],
    ls: Field["float"],
    ths1: Field["float"],
    rvs1: Field["float"],
    rcs1: Field["float"],
    ris1: Field["float"],
    rc_mf: Field["float"],
    ri_mf: Field["float"],
    cf_mf: Field["float"],
    cldfr: Field["float"],
    hlc_hrc: Field["float"],
    hlc_hcf: Field["float"],
    hli_hri: Field["float"],
    hli_hcf: Field["float"],
    dt: "float"
):
      
    from __externals__ import (
        LSUBG_COND,
        SUBG_MF_PDF,
        CRIAUTC,
        CRIAUTI,
        ACRIAUTI,
        BCRIAUTI,
        TT
    )

    # 5.2  compute the cloud fraction cldfr
    with computation(PARALLEL), interval(...):
        
        if __INLINED(not LSUBG_COND):
            cldfr = 1.0 if ((rcs1 + ris1)*dt > 1e-12) else 0.0
        # Translation note : OCOMPUTE_SRC is taken False
        # Translation note : l320 to l322 removed

        # Translation note : LSUBG_COND = TRUE for Arome
        else:
            # adding mass fluxes
            w1 = rc_mf / dt
            w2 = ri_mf / dt

            if w1 + w2 > rvs1:
                w1 *= rvs1 / (w1 + w2)
                w2 = rvs1 - w1

            cldfr = min(1, cldfr + cf_mf)
            rcs1 += w1
            ris1 += w2
            rvs1 -= (w1 + w2)
            ths1 += (w1 * lv + w2 * ls) / (cph * exnref)

            # Droplets subgrid autoconversion
            # LLHLC_H is True (AROME like) phlc_hrc and phlc_hcf are present
            # LLHLI_H is True (AROME like) phli_hri and phli_hcf are present
            criaut = CRIAUTC / rhodref
            
            # ice_adjust.F90 IF LLNONE; IF CSUBG_MF_PDF is None
            if __INLINED(SUBG_MF_PDF == 0):
                if w1 * dt > cf_mf * criaut:
                    hlc_hrc += w1 * dt
                    hlc_hcf = min(1.0, hlc_hcf + cf_mf)

            # Translation note : if LLTRIANGLE in .F90
            if __INLINED(SUBG_MF_PDF == 1):
                if w1 * dt > cf_mf * criaut:
                    hcf = 1.0 - 0.5 * (criaut * cf_mf / max(1e-20, w1 * dt)) ** 2
                    hr = w1 * dt - (criaut * cf_mf) ** 3 / (
                        3 * max(1e-20, w1 * dt) ** 2
                    )

                elif 2.0 * w1 * dt <= cf_mf * criaut:
                    hcf = 0.0
                    hr = 0.0

                else:
                    hcf = (2.0 * w1 * dt - criaut * cf_mf) ** 2 / (
                        2.0 * max(1.0e-20, w1 * dt) ** 2
                    )
                    hr = (
                        4.0 * (w1 * dt) ** 3
                        - 3.0 * w1 * dt * (criaut * cf_mf) ** 2
                        + (criaut * cf_mf ** 3)
                    ) / (3 * max(1.0e-20, w1 * dt) ** 2)

                hcf *= cf_mf
                hlc_hcf = min(1.0, hlc_hcf + hcf)
                hlc_hrc += hr

            # Ice subgrid autoconversion
            criaut = min(
                CRIAUTI,
                10 ** (ACRIAUTI * (t - TT) + BCRIAUTI),
            )

            # LLNONE in ice_adjust.F90
            if __INLINED(SUBG_MF_PDF == 0):
                if w2 * dt > cf_mf * criaut:
                    hli_hri += w2 * dt
                    hli_hcf = min(1.0, hli_hcf + cf_mf)

            # LLTRIANGLE in ice_adjust.F90
            if __INLINED(SUBG_MF_PDF == 1):
                if w2 * dt > cf_mf * criaut:
                    hcf = 1.0 - 0.5 * ((criaut * cf_mf) / (w2 * dt)) ** 2
                    hri = w2 * dt - (criaut * cf_mf) ** 3 / (3 * (w2 * dt) ** 2)

                elif 2 * w2 * dt <= cf_mf * criaut:
                    hcf = 0.0
                    hri = 0.0

                else:
                    hcf = (2.0 * w2 * dt - criaut * cf_mf) ** 2 / (
                        2.0 * (w2 * dt) ** 2
                    )
                    hri = (
                        4.0 * (w2 * dt) ** 3
                        - 3.0 * w2 * dt * (criaut * cf_mf) ** 2
                        + (criaut * cf_mf) ** 3
                    ) / (3.0 * (w2 * dt) ** 2)

                hcf *= cf_mf
                hli_hcf = min(1.0, hli_hcf + hcf)
                hli_hri += hri
    # Translation note : 402 -> 427 (removed pout_x not present )


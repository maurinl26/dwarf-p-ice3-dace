# -*- coding: utf-8 -*-
import dace
import numpy as np

from dace.dtypes import float64, compiletime
from ice3.stencils.condensation_split import condensation
from ice3.stencils.cloud_fraction_split import cloud_fraction_1
from ice3.stencils.thermo import thermodynamic_fields

from ice3.utils.typingx import dtype_float, dtype_int
from ice3.utils.dims import I, J, K


@dace.program
def ice_adjust(
    sigqsat: dtype_float[I, J, K],
    exn: dtype_float[I, J, K],
    pabs: dtype_float[I, J, K],
    sigs: dtype_float[I, J, K],
    th0: dtype_float[I, J, K],
    rv0: dtype_float[I, J, K],
    rc0: dtype_float[I, J, K],
    rr0: dtype_float[I, J, K],
    ri0: dtype_float[I, J, K],
    rs0: dtype_float[I, J, K],
    rg0: dtype_float[I, J, K],
    ths0: dtype_float[I, J, K],
    rvs0: dtype_float[I, J, K],
    rcs0: dtype_float[I, J, K],
    ris0: dtype_float[I, J, K],
    ths1: dtype_float[I, J, K],
    rvs1: dtype_float[I, J, K],
    rcs1: dtype_float[I, J, K],
    ris1: dtype_float[I, J, K],
    cldfr: dtype_float[I, J, K],
    sigrc: dtype_float[I, J, K],
    CPD: dtype_float,
    CPV: dtype_float,
    CL: dtype_float,
    CI: dtype_float,
    LVTT: dtype_float,
    LSTT: dtype_float,
    OCND2: dace.bool,
    RD: dtype_float,
    RV: dtype_float,
    TMAXMIX: dtype_float,
    TMINMIX: dtype_float,
    LSIGMAS: dace.bool,
    LSTATNW: dace.bool,
    ALPW: dtype_float,
    BETAW: dtype_float,
    GAMW: dtype_float,
    ALPI: dtype_float,
    BETAI: dtype_float,
    GAMI: dtype_float,
    TT: dtype_float,
    dt: dtype_float,
):
    cph = np.ndarray([I, J, K], dtype=dtype_float)
    lv = np.ndarray([I, J, K], dtype=dtype_float)
    ls = np.ndarray([I, J, K], dtype=dtype_float)
    t = np.ndarray([I, J, K], dtype=dtype_float)

    rv_out = np.ndarray([I, J, K], dtype=dtype_float)
    rc_out = np.ndarray([I, J, K], dtype=dtype_float)
    ri_out = np.ndarray([I, J, K], dtype=dtype_float)

    thermodynamic_fields(
        th=th0,
        exn=exn,
        rv=rv0,
        rc=rc0,
        rr=rr0,
        ri=ri0,
        rs=rs0,
        rg=rg0,
        cph=cph,
        lv=lv,
        ls=ls,
        t=t,
        NRR=6,
        CPD=CPD,
        CPV=CPV,
        CL=CL,
        CI=CI,
        LSTT=LSTT,
        LVTT=LVTT,
        TT=TT,
    )

    condensation(
        sigqsat=sigqsat,
        pabs=pabs,
        sigs=sigs,
        t=t,
        rv=rv0,
        ri=ri0,
        rc=rc0,
        rv_out=rv_out,
        rc_out=rc_out,
        ri_out=ri_out,
        cldfr=cldfr,
        cph=cph,
        lv=lv,
        ls=ls,
        sigrc=sigrc,
        OCND2=OCND2,
        FRAC_ICE_ADJUST=True,
        RD=RD,
        RV=RV,
        TMAXMIX=TMAXMIX,
        TMINMIX=TMINMIX,
        LSIGMAS=LSIGMAS,
        LSTATNW=LSTATNW,
        ALPW=ALPW,
        BETAW=BETAW,
        GAMW=GAMW,
        ALPI=ALPI,
        BETAI=BETAI,
        GAMI=GAMI,
        LAMBDA3=True,
    )

    cloud_fraction_1(
        lv=lv,
        ls=ls,
        cph=cph,
        exnref=exn,
        rc=rc0,
        ri=ri0,
        rc_tmp=rc_out,
        ri_tmp=ri_out,
        ths0=ths0,
        rvs0=rvs0,
        rcs0=rcs0,
        ris0=ris0,
        ths1=ths1,
        rvs1=rvs1,
        rcs1=rcs1,
        ris1=ris1,
        dt=dt,
    )


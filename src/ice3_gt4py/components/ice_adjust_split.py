# -*- coding: utf-8 -*-
from __future__ import annotations


import dace
import numpy as np

from ice3_gt4py.stencils.condensation_split import condensation
from ice3_gt4py.stencils.sigma_rc_dace import sigrc_computation
from ice3_gt4py.stencils.cloud_fraction_split import thermodynamic_fields, cloud_fraction_1, cloud_fraction_2
from ice3_gt4py.phyex_common.tables import SRC_1D

from ice3_gt4py.utils.typingx import dtype_float, dtype_int, FloatFieldIJK
from ice3_gt4py.utils.dims import I, J, K


@dace.program
def ice_adjust(
    th: dace.float64[I, J, K],
    exn: dace.float64[I, J, K],
    rhodref: dace.float64[I, J, K],
    sigqsat: dace.float64[I, J, K],
    pabs: dace.float64[I, J, K],
    cldfr: dace.float64[I, J, K],
    sigs: dace.float64[I, J, K],
    rc_mf: dace.float64[I, J, K],
    ri_mf: dace.float64[I, J, K],
    cf_mf: dace.float64[I, J, K],
    rv: dace.float64[I, J, K],
    rc: dace.float64[I, J, K],
    rr: dace.float64[I, J, K],
    ri: dace.float64[I, J, K],
    rs: dace.float64[I, J, K],
    rg: dace.float64[I, J, K],
    ths0: dace.float64[I, J, K],
    rvs0: dace.float64[I, J, K],
    rcs0: dace.float64[I, J, K],
    ris0: dace.float64[I, J, K],
    ths1: dace.float64[I, J, K],
    rvs1: dace.float64[I, J, K],
    rcs1: dace.float64[I, J, K],
    ris1: dace.float64[I, J, K],
    hlc_hrc: dace.float64[I, J, K],
    hlc_hcf: dace.float64[I, J, K],
    hli_hcf: dace.float64[I, J, K],
    hli_hri: dace.float64[I, J, K],
    externals: dace.compiletime
):

    cph = np.ndarray([I, J, K], dtype=dtype_float)
    lv = np.ndarray([I, J, K], dtype=dtype_float)
    ls = np.ndarray([I, J, K], dtype=dtype_float)
    t = np.ndarray([I, J, K], dtype=dtype_float)

    rc_out = np.ndarray([I, J, K], dtype=dtype_float)
    ri_out = np.ndarray([I, J, K], dtype=dtype_float)
    rv_out = np.ndarray([I, J, K], dtype=dtype_float)
    q1 = np.ndarray([I, J, K], dtype=dtype_float)

    sigrc = np.ndarray([I, J, K], dtype=dtype_float)
    inq1 = np.ndarray([I, J, K], dtype=dtype_int)

    thermodynamic_fields(
        th=th,
        exn=exn,
        rv=rv,
        rc=rc,
        rr=rr,
        ri=ri,
        rs=rs,
        rg=rg,
        cph=cph,
        lv=lv,
        ls=ls,
        t=t,
    )

    condensation(
        sigqsat=sigqsat,
        pabs=pabs,
        cldfr=cldfr,
        sigs=sigs,
        ri=ri,
        rc=rc,
        rv=rv,
        cph=cph,
        lv=lv,
        ls=ls,
        t=t,
        rv_out=rv_out,
        ri_out=ri_out,
        rc_out=rc_out,
        q1=q1,
    )

    sigrc_computation(
        q1=q1,
        inq1=inq1,
        src_1d=SRC_1D,
        sigrc=sigrc,
        LAMBDA3=0,
    )

    cloud_fraction_1(
        exnref=exn,
        rc=rc,
        ri=ri,
        ths0=ths0,
        rvs0=rvs0,
        rcs0=rcs0,
        ris0=ris0,
        ths1=ths1,
        rvs1=rvs1,
        rcs1=rcs1,
        ris1=ris1,
        lv=lv,
        ls=ls,
        cph=cph,
        rc_tmp=rc_out,
        ri_tmp=ri_out,
    )

    cloud_fraction_2(
        rhodref=rhodref,
        exnref=exn,
        rc_mf=rc_mf,
        ri_mf=ri_mf,
        cf_mf=cf_mf,
        cldfr=cldfr,
        hlc_hrc=hlc_hrc,
        hlc_hcf=hlc_hcf,
        hli_hri=hli_hri,
        hli_hcf=hli_hcf,
        ths=ths1,
        rvs=rvs1,
        rcs=rcs1,
        ris=ris1,
        lv=lv,
        ls=ls,
        cph=cph,
        t=t,
    )


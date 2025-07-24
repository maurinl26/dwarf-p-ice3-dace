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


if __name__ == "__main__":
    import numpy as np

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]

    sdfg = ice_adjust.to_sdfg()
    sdfg.save("ice_adjust.sdfg")
    csdfg = sdfg.compile()

    state = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "sigqsat",
            "rhodref",
            "exn",
            "pabs",
            "sigs",
            "rc_mf",
            "ri_mf",
            "cf_mf",
            "th0",
            "rv0",
            "rc0",
            "rr0",
            "ri0",
            "rs0",
            "rg0",
            "ths0",
            "rvs0",
            "rcs0",
            "ris0",
        ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "ths1",
            "rvs1",
            "rcs1",
            "ris1",
            "cldfr",
            "sigrc",
            "hlc_hrc",
            "hlc_hcf",
            "hli_hri",
            "hli_hcf",
        ]
    }

    print("Allocation \n")
    for key, storage in state.items():
        storage[:, :, :] = np.ones(domain, dtype=np.float64)
    for key, storage in outputs.items():
        storage[:, :, :] = np.zeros(domain, dtype=np.float64)

    print("Call ")
    csdfg(
        **state,
        **outputs,
        NRR=6,
        CPD=1.0,
        CPV=1.0,
        CL=1.0,
        CI=1.0,
        OCND2=True,
        FRAC_ICE_ADJUST=True,
        RD=1.0,
        RV=1.0,
        # condens=1,
        LSTT=1.0,
        LVTT=1.0,
        TMAXMIX=1.0,
        TMINMIX=1.0,
        LSIGMAS=True,
        LSTATNW=True,
        ALPW=1.0,
        BETAW=1.0,
        GAMW=1.0,
        ALPI=1.0,
        BETAI=1.0,
        GAMI=1.0,
        LAMBDA3=True,
        LSUBG_COND=True,
        CRIAUTC=1.0,
        SUBG_MF_PDF=1,
        CRIAUTI=1.0,
        ACRIAUTI=1.0,
        BCRIAUTI=1.0,
        TT=1.0,
        dt=50.0,
        I=I,
        J=J,
        K=K,
    )

    print(outputs["hlc_hrc"].mean())

# -*- coding: utf-8 -*-
import dace
import numpy as np

from dace.dtypes import float64, compiletime
from ice3.stencils.condensation_split import condensation
from ice3.stencils.cloud_fraction_split import cloud_fraction_1, cloud_fraction_2
from ice3.stencils.thermo import thermodynamic_fields

from ice3.utils.typingx import dtype_float, dtype_int
from ice3.utils.dims import I, J, K

class IceAdjustState:
    RD: float
    RV: float

    FRAC_ICE_ADJUST: int
    TMAXMIX: float
    TMINMIX: float

    OCND2: bool
    LSIGMAS: bool
    LSTATNW: bool
    LSUBG_COND: bool

    CONDENS: int
    NRR: int

    CPV: float
    CPD: float
    CL: float
    CI: float

    SUBG_MF_PDF: int
    CRIAUTC: float
    CRIAUTI: float
    ACRIAUTI: float
    BCRIAUTI: float
    TT: float
    LAMBDA3: bool

    def __init__(self, phyext: dict):
        self.RD = phyext["RD"]
        self.RV = phyext["RV"]

        self.FRAC_ICE_ADJUST = phyext["FRAC_ICE_ADJUST"]
        self.TMAXMIX = phyext["TMAXMIX"]
        self.TMINMIX = phyext["TMINMIX"]

        self.OCND2 = phyext["OCND2"]
        self.LSIGMAS = phyext["LSIGMAS"]
        self.LSTATNW = phyext["LSTATNW"]
        self.LSUBG_COND = phyext["LSUBG_COND"]

        self.CONDENS = phyext["CONDENS"]
        self.NRR = phyext["NRR"]

        self.CPV = phyext["CPV"]
        self.CPD = phyext["CPD"]
        self.CL = phyext["CL"]
        self.CI = phyext["CI"]

        self.SUBG_MF_PDF = phyext["SUBG_MF_PDF"]
        self.CRIAUTC = phyext["CRIAUTC"]
        self.CRIAUTI = phyext["CRIAUTI"]
        self.ACRIAUTI = phyext["ACRIAUTI"]
        self.BCRIAUTI = phyext["BCRIAUTI"]
        self.TT = phyext["TT"]
        self.LAMBDA3 = phyext["LAMBDA3"]


@dace.program
def ice_adjust(
    sigqsat: dtype_float[I, J, K],
    rhodref: dtype_float[I, J, K],
    exn: dtype_float[I, J, K],
    pabs: dtype_float[I, J, K],
    sigs: dtype_float[I, J, K],
    rc_mf: dtype_float[I, J, K],
    ri_mf: dtype_float[I, J, K],
    cf_mf: dtype_float[I, J, K],
    th: dtype_float[I, J, K],
    rv: dtype_float[I, J, K],
    rc: dtype_float[I, J, K],
    rr: dtype_float[I, J, K],
    ri: dtype_float[I, J, K],
    rs: dtype_float[I, J, K],
    rg: dtype_float[I, J, K],
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
    hlc_hrc: dtype_float[I, J, K],
    hlc_hcf: dtype_float[I, J, K],
    hli_hri: dtype_float[I, J, K],
    hli_hcf: dtype_float[I, J, K],
    NRR: dtype_int,
    CPD: dtype_float,
    CPV: dtype_float,
    CL: dtype_float,
    CI: dtype_float,
    LVTT: dtype_float,
    LSTT: dtype_float,
    OCND2: dace.bool,
    FRAC_ICE_ADJUST: dace.bool,
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
    LAMBDA3: dace.bool,
    LSUBG_COND: dace.bool,
    CRIAUTC: dtype_float,
    SUBG_MF_PDF: dtype_int,
    CRIAUTI: dtype_float,
    ACRIAUTI: dtype_float,
    BCRIAUTI: dtype_float,
    TT: dtype_float,
    dt: dtype_float
):

    cph = np.ndarray([I, J, K], dtype=dtype_float)
    lv = np.ndarray([I, J, K], dtype=dtype_float)
    ls = np.ndarray([I, J, K], dtype=dtype_float)
    t = np.ndarray([I, J, K], dtype=dtype_float)

    rv_out = np.ndarray([I, J, K], dtype=dtype_float)
    rc_out = np.ndarray([I, J, K], dtype=dtype_float)
    ri_out = np.ndarray([I, J, K], dtype=dtype_float)

    thermodynamic_fields(
        th,
        exn,
        rv,
        rc,
        rr,
        ri,
        rs,
        rg,
        cph,
        lv,
        ls,
        t,
        nrr=6,
        CPD=CPD,
        CPV=CPV,
        CL=CL,
        CI=CI,
        LSTT=LSTT,
        LVTT=LVTT,
        TT=TT
    )

    condensation(
        sigqsat=sigqsat,
        pabs=pabs,
        sigs=sigs,
        t=t,
        rv=rv,
        ri=ri,
        rc=rc,
        rv_out=rv_out,
        rc_out=rc_out,
        ri_out=ri_out,
        cldfr=cldfr,
        cph=cph,
        lv=lv,
        ls=ls,
        sigrc=sigrc,
        OCND2=OCND2,
        FRAC_ICE_ADJUST=FRAC_ICE_ADJUST,
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
        LAMBDA3=LAMBDA3,
    )

    cloud_fraction_1(
        lv=lv,
        ls=ls,
        cph=cph,
        exnref=exn,
        rc=rc,
        ri=ri,
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
        dt=50.0,
    )

    cloud_fraction_2(
        rhodref=rhodref,
        exnref=exn,
        t=t,
        cph=cph,
        lv=lv,
        ls=ls,
    ths1=ths1,
    rvs1=rvs1,
    rcs1=rcs1,
    ris1=ris1,
    rc_mf=rc_mf,
    ri_mf=ri_mf,
    cf_mf=cf_mf,
    cldfr=cldfr,
    hlc_hrc=hlc_hrc,
    hlc_hcf=hlc_hcf,
    hli_hri=hli_hri,
    hli_hcf=hli_hcf,
    dt=dt,
    LSUBG_COND=LSUBG_COND,
    CRIAUTC=CRIAUTC,
    subg_mf_pdf=SUBG_MF_PDF,
    CRIAUTI=CRIAUTI,
    ACRIAUTI=ACRIAUTI,
    BCRIAUTI=BCRIAUTI,
    TT=TT,
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
    "th",
    "rv",
    "rc",
    "rr",
    "ri",
    "rs",
    "rg",
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
    condens=1,
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
    subg_mf_pdf=1,
    CRIAUTI=1.0,
    ACRIAUTI=1.0,
    BCRIAUTI=1.0,
    TT=1.0,
    dt=50.0
    )

    print(outputs["rv_out"].mean())




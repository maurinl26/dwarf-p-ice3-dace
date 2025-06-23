import numpy as np

from ice3_gt4py.stencils.condensation_split import condensation
from ice3_gt4py.stencils.sigma_rc_dace import sigrc_computation
from ice3_gt4py.stencils.cloud_fraction_split import thermodynamic_fields, cloud_fraction_1, cloud_fraction_2
from ice3_gt4py.phyex_common.tables import SRC_1D


def test_thermodynamic_fields(grid):

    state = {
        name: np.ones(grid, dtype=np.float64)
        for name in [
            "th",
            "exn",
            "rv",
            "rc",
            "rr",
            "ri",
            "rs",
            "rg",
        ]
    }

    outputs = {
        name: np.zeros(grid, dtype=np.float64)
        for name in [
            "cph",
            "lv",
            "ls",
            "t",
        ]
    }

    thermodynamic_fields(
        **state,
        **outputs
    )


def test_condensation():

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


def test_sigrc_computation():

    sigrc_computation(
        q1=q1,
        inq1=inq1,
        src_1d=SRC_1D,
        sigrc=sigrc,
        LAMBDA3=0,
    )

def test_cloud_fraction_1():
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


def test_cloud_fraction_2():
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


   
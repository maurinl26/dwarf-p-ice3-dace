import numpy as np

from ice3.stencils.condensation_split import condensation
from ice3.stencils.sigma_rc_dace import sigrc_computation
from ice3.stencils.cloud_fraction_split import thermodynamic_fields, cloud_fraction_1, cloud_fraction_2
from ice3.phyex_common.tables import SRC_1D


def test_thermodynamic_fields(domain):

    I = domain[0]
    J = domain[1]
    K = domain[2]

    sdfg = thermodynamic_fields.to_sdfg()
    sdfg.save("thermo.sdfg")
    sdfg.compile()

    state = {
        name: np.ones(shape=(I, J, K), dtype=np.float64)
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
        name: np.zeros(shape=(I, J, K), dtype=np.float64)
        for name in [
            "cph",
            "lv",
            "ls",
            "t",
        ]
    }

    sdfg(
        **state,
        **outputs,
        NRR=6,
        CPD=1.0,
        CPV=1.0,
        CL=1.0,
        CI=1.0,
        I=I,
        J=J,
        K=K
    )


def test_condensation(domain):
    state = {
        name: np.ones(domain, dtype=np.float64)
        for name in [
            "sigqsat",
            "pabs",
            "cldfr",
            "sigs",
            "ri",
            "rc",
            "rv",
            "cph",
            "lv",
            "ls",
            "t",
        ]
    }

    outputs = {
        name: np.zeros(domain, dtype=np.float64)
        for name in [
            "rv_out",
            "ri_out",
            "rc_out",
            "q1",
        ]
    }

    condensation(
        **state,
        **outputs,
        I=domain[0],
        J=domain[1],
        K=domain[2]
    )


def test_sigrc_computation():

    sigrc_computation(
        q1=q1,
        inq1=inq1,
        src_1d=SRC_1D,
        sigrc=sigrc,
        LAMBDA3=0,
    )

def test_cloud_fraction_1(domain):

    state = {
        name: np.ones(domain, dtype=np.float64)
        for name in [
            "exnref",
            "rc",
            "ri",
            "ths0"
            "rvs0",
            "rcs0",
            "ris0",
        ]
    }

    outputs = {
        name: np.zeros(domain, dtype=np.float64)
        for name in [
             "ths1",
            "rvs1",
            "rcs1",
            "ris1",
            "lv",
            "ls",
            "cph",
            "rc_tmp",
            "ri_tmp",
        ]
    }

    cloud_fraction_1(
        **state,
        **outputs,
        I=domain[0],
        J=domain[1],
        K=domain[2]
    )


def test_cloud_fraction_2(domain):
    state = {
        name: np.ones(domain, dtype=np.float64)
        for name in [
            "rhodref",
            "exnref",
            "rc_mf",
            "ri_mf",
            "cf_mf",
            "cldfr",
        ]
    }

    outputs = {
        name: np.zeros(domain, dtype=np.float64)
        for name in [
             "hlc_hrc",
        "hlc_hcf",
        "hli_hri",
        "hli_hcf",
        "ths",
        "rvs",
        "rcs",
        "ris",
        "lv",
        "ls",
        "cph",
        "t",
        ]
    }

    cloud_fraction_2(
        **state,
        **outputs,
        I=domain[0],
        J=domain[1],
        K=domain[2]
    )


   
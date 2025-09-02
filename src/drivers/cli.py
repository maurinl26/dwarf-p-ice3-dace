# -*- coding: utf-8 -*-
import typer
import dace
import logging
import numpy as np

from ice3.components.ice_adjust_split import ice_adjust
from ice3.utils.allocate import allocate

from typing import Tuple

app = typer.Typer()

######################## drivers #######################
@app.command()
def generate_sdfg(
    domain: Tuple[int, int, int] = (50, 50, 15)
):
    """Run ice_adjust splitted version to avoid
    interpolation problems for sigrc
    """

    I = domain[0]
    J = domain[1]
    K = domain[2]
    
    logging.info("Generate SDFG")
    sdfg = ice_adjust.to_sdfg()
    sdfg.save("sdfg/ice_adjust.sdfg")
    
    logging.info("Compile SDFG")
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
    
    allocate(domain, state, outputs)

    logging.info("Call compiled SDFG")
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

    logging.info(f"hlc_hrc mean {outputs['hlc_hrc'].mean()}")


if __name__ == "__main__":
    app()


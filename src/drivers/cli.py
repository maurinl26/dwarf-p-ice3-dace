# -*- coding: utf-8 -*-
from pathlib import Path

import numpy as np
import typer
import logging
import time

from ice3_gt4py.components.ice_adjust_split import ice_adjust
from ice3_gt4py.initialisation.state_ice_adjust import (
    get_state_ice_adjust,
)
from ice3_gt4py.phyex_common.phyex import Phyex
from ice3_gt4py.utils.reader import NetCDFReader

from ice3_gt4py.utils.typingx import dtype_float, precision
from ice3_gt4py.utils.dims import I, J, K

app = typer.Typer()

######################## drivers #######################
@app.command()
def ice_adjust_split(
    dataset: str,
):
    """Run ice_adjust splitted version to avoid
    interpolation problems for sigrc
    """
    ##### Grid #####
    logging.info("Initializing grid ...")
    nx = 9472
    ny = 1
    nz = 15

    ################## Phyex #################
    logging.info("Initializing Phyex ...")
    phyext = Phyex("AROME").to_externals()

    ####### Create state for AroAdjust #######
    reader = NetCDFReader(Path(dataset))

    logging.info("Getting state for IceAdjust")
    # state = get_state_ice_adjust(
    #     netcdf_reader=reader,
    #     grid_shape=(nx, ny, nz)
    # )

    state = {
        name: np.ones(
            shape=(nx, ny, nz),
            dtype=np.float64,
        ) for name in [
            "th",
            "exn",
            "rhodref",
            "sigqsat",
            "pabs",
            "cldfr",
            "sigs",
            "rc_mf",
            "ri_mf",
            "cf_mf",
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
        name: np.zeros(
            (nx, ny, nz),
            dtype=(np.float64 if precision == "double" else np.float32)
        ) for name in [
            "ths1",
            "rvs1",
            "rcs1",
            "ris1",
            "hlc_hrc",
            "hlc_hcf",
            "hli_hcf",
            "hli_hri",
        ]
    }

    ###### Launching IceAdjust ###############
    logging.debug("Launching IceAdjust")
    logging.debug(f"State {list(state.keys())}")
    logging.debug(f"th {state['th'].shape}")

    print(state['th'].shape)

    I = nx
    J = ny
    K = nz

    start = time.time()
    ice_adjust(
        th=state["th"],
        exn=state["exn"],
        rhodref=state["rhodref"],
        sigqsat=state["sigqsat"],
        pabs=state["pabs"],
        cldfr=state["cldfr"],
        sigs=state["sigs"],
        rc_mf=state["rc_mf"],
        ri_mf=state["ri_mf"],
        cf_mf=state["cf_mf"],
        rv=state["rv"],
        rc=state["rc"],
        rr=state["rr"],
        ri=state["ri"],
        rs=state["rs"],
        rg=state["rg"],
        ths0=state["ths0"],
        rvs0=state["rvs0"],
        rcs0=state["rcs0"],
        ris0=state["ris0"],
        ths1=outputs["ths1"],
        rvs1=outputs["rvs1"],
        rcs1=outputs["rcs1"],
        ris1=outputs["ris1"],
        hlc_hrc=outputs["hlc_hrc"],
        hlc_hcf=outputs["hlc_hcf"],
        hli_hcf=outputs["hli_hcf"],
        hli_hri=outputs["hli_hri"],
    )
    stop = time.time()
    elapsed_time = stop - start
    logging.info(f"Execution duration for IceAdjust : {elapsed_time} s")


if __name__ == "__main__":
    app()


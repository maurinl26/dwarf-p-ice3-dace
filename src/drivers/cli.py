# -*- coding: utf-8 -*-
from pathlib import Path

import numpy as np
import typer
import logging
import time

from ice3.components.ice_adjust_split import ice_adjust, IceAdjustState
from ice3.initialisation.state_ice_adjust import (
    get_state_ice_adjust,
)
from ice3.phyex_common.phyex import Phyex
from ice3.utils.reader import NetCDFReader

from ice3.utils.typingx import dtype_float, precision
from ice3.utils.dims import I, J, K
from ice3.utils.dict_to_class import DictToClass

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
    ny = 2
    nz = 15

    I = 50
    J = 50
    K = 15

    ################## Phyex #################
    logging.info("Initializing Phyex ...")
    phyext = Phyex("AROME").to_externals()
    phyext.update({
        "OCND2": False
    })

    ####### Create state for AroAdjust #######
    reader = NetCDFReader(Path(dataset))

    logging.info("Getting state for IceAdjust")

    th = np.ones((I, J, K), dtype=np.float64)
    exn = np.ones((I, J, K), dtype=np.float64)
    rv = np.ones((I, J, K), dtype=np.float64)
    rc = np.ones((I, J, K), dtype=np.float64)
    rr = np.ones((I, J, K), dtype=np.float64)
    ri = np.ones((I, J, K), dtype=np.float64)
    rs = np.ones((I, J, K), dtype=np.float64)
    rg = np.ones((I, J, K), dtype=np.float64)


    start = time.time()
    ice_adjust(
        th[:,:,:],
        exn[:,:,:],
        rv[:,:,:],
        rc[:,:,:],
        rr[:,:,:],
        ri[:,:,:],
        rs[:,:,:],
        rg[:,:,:],
        NRR=phyext["NRR"],
        CPD=phyext["CPD"],
        CPV=phyext["CPV"],
        CL=phyext["CL"],
        CI=phyext["CI"],
        I=nx,
        J=ny,
        K=nz,
    )
    stop = time.time()
    elapsed_time = stop - start
    logging.info(f"Execution duration for IceAdjust : {elapsed_time} s")

    print(ri.shape)


if __name__ == "__main__":
    app()


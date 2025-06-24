# -*- coding: utf-8 -*-
from __future__ import annotations

import numpy as np

import dace
from dace.dtypes import StorageType, ScheduleType

from ice3.utils.typingx import dtype_float, dtype_int
from ice3.functions.ice_adjust import sublimation_latent_heat, vaporisation_latent_heat

IX, JY, KZ = (dace.symbol(s) for s in ['IX', 'JY', 'KZ'])

@dace.program
def thermodynamic_fields(
    th: dace.float32[IX, JY, KZ],
    exn: dace.float32[IX, JY, KZ],
    rv: dace.float32[IX, JY, KZ],
    rc: dace.float32[IX, JY, KZ],
    rr: dace.float32[IX, JY, KZ],
    ri: dace.float32[IX, JY, KZ],
    rs: dace.float32[IX, JY, KZ],
    rg: dace.float32[IX, JY, KZ],
    lv: dace.float32[IX, JY, KZ],
    ls: dace.float32[IX, JY, KZ],
    cph: dace.float32[IX, JY, KZ],
    t: dace.float32[IX, JY, KZ],
    NRR: dace.float32,
    CPD: dace.float32,
    CPV: dace.float32,
    CL: dace.float32,
    CI: dace.float32
):

    # 2.3 Compute the variation of mixing ratio
    for i, j, k in dace.map[0:IX, 0:JY, 0:KZ] @ ScheduleType.GPU_Device:
        t[i, j, k] = exn[i, j, k] * th[i, j, k]
        vaporisation_latent_heat(lv[i, j, k], t[i, j, k])
        sublimation_latent_heat(ls[i, j, k], t[i, j, k])

    # 2.4 specific heat for moist air at t+1
    for i, j, k in dace.map[0:I, 0:J, 0:K] @ ScheduleType.GPU_Device:
        if NRR == 6:
            cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k]) + CI * (ri[i, j, k] + rs[i, j, k] + rg[i, j, k])
        # if NRR == 5:
        #     cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k]) + CI * (ri[i, j, k] + rs[i, j, k])
        # if NRR == 4:
        #     cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k])
        # if NRR == 2:
        #     cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * rc[i, j, k] + CI * ri[i, j, k]






if __name__ == "__main__":

    IX, JY, KZ = 50, 50, 15

    sdfg = thermodynamic_fields.to_sdfg()
    sdfg.save("thermo.sdfg")
    sdfg.compile()

    state = {
        name: np.ones(shape=(IX, JY, KZ), dtype=np.float64)
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
        name: np.zeros(shape=(IX, JY, KZ), dtype=np.float64)
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
        IX=IX,
        JY=JY,
        KZ=KZ
    )




# -*- coding: utf-8 -*-
from __future__ import annotations
import numpy as np

import dace

from ice3.utils.typingx import dtype_int, dtype_float
from ice3.utils.dims import I, J, K
from ice3.functions.tiwmx import e_sat_i, e_sat_w

@dace.program
def condensation(
    sigqsat: dtype_float[I, J, K],
    pabs: dtype_float[I, J, K],
    sigs: dtype_float[I, J, K],
    t: dtype_float[I, J, K],
    rv: dtype_float[I, J, K],
    ri: dtype_float[I, J, K],
    rc: dtype_float[I, J, K],
    rv_out: dtype_float[I, J, K],
    rc_out: dtype_float[I, J, K],
    ri_out: dtype_float[I, J, K],
    cldfr: dtype_float[I, J, K],
    cph: dtype_float[I, J, K],
    lv: dtype_float[I, J, K],
    ls: dtype_float[I, J, K],
    q1: dtype_float[I, J, K],
    OCND2: dace.bool,
    FRAC_ICE_ADJUST: dtype_int,
    RD: dtype_float,
    RV: dtype_float,
    CONDENS: dtype_int,
    TMAXMIX: dtype_float,
    TMINMIX: dtype_float,
    LSIGMAS: dace.bool,
    LSTATNW: dace.bool
):
    """Microphysical adjustments for specific contents due to condensation."""

    rt = np.ndarray([I, J, K], dtype=dtype_float)
    pv = np.ndarray([I, J, K], dtype=dtype_float)
    piv = np.ndarray([I, J, K], dtype=dtype_float)

    # initialize values
    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        cldfr[i, j, k] = 0.0
        rv_out[i, j, k] = 0.0
        rc_out[i, j, k] = 0.0
        ri_out[i, j, k] = 0.0

    # 3. subgrid condensation scheme
    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        prifact = 1
        frac_tmp = 0

        # store total water mixing ratio (244 -> 248)
        rt[i, j, k] = rv[i, j, k] + rc[i, j, k] + ri[i, j, k] * prifact

        # l334 to l337
        if not OCND2:
            pv[i, j, k] = min(
            e_sat_w(t[i, j, k]),
            0.99 * pabs[i, j, k],
            )
            piv[i, j, k] = min(
            e_sat_i(t[i, j, k]),
            0.99 * pabs[i, j, k],
            )

        if not OCND2:
            frac_tmp =(
                rc[i, j, k] / (rc[i, j, k] + ri[i, j, k])
                if rc[i, j, k] + ri[i, j, k] > 1e-20 else 0
            )

            # Compute frac ice inlined
            # Default Mode (S)
            if FRAC_ICE_ADJUST == 3:
                frac_tmp = max(0, min(1, frac_tmp[i, j, k]))

            # AROME mode
            if FRAC_ICE_ADJUST == 0:
                frac_tmp = max(0,
                               min(1,
                                   ((TMAXMIX - t[i, j, k]) / (TMAXMIX - TMINMIX))
                                   ))

        
        # Supersaturation coefficients
        qsl = RD / RV * pv[i, j, k] / (pabs - pv[i, j, k])
        qsi = RD / RV * piv[i, j, k] / (pabs - piv[i, j, k])

        # interpolate between liquid and solid as a function of temperature
        qsl = (1 - frac_tmp) * qsl + frac_tmp * qsi
        lvs = (1 - frac_tmp) * lv[i, j, k] + frac_tmp * ls[i, j, k]

        # coefficients a et b
        ah = lvs * qsl / (RV * t[i, j, k]**2) * (1 + RV * qsl / RD)
        a = 1 / (1 + lvs / cph[i, j, k] * ah)
        b = ah * a
        sbar = a * (rt[i, j, k] - qsl + ah * lvs * (rc[i, j, k] + ri[i, j, k] * prifact) / cph[i, j, k])

        if LSIGMAS and not LSTATNW:
            sigma = (
                sqrt((2 * sigs[i, j, k]) ** 2 + (sigqsat[i, j, k] * qsl * a) ** 2)
                if sigqsat[i, j, k] != 0
                else 2 * sigs[i, j, k]
            )

        # Translation note : l407 - l411
        sigma = max(1e-10, sigma)
        q1[i, j, k] = sbar / sigma

        # 9.2.3 Fractional cloudiness and cloud condensate
        # HCONDENS = 0 is CB02 option
        if CONDENS == 0:
        # Translation note : l470 to l479
            if q1[i, j, k] > 0.0:
                cond_tmp = (
                min(exp(-1.0) + 0.66 * q1[i, j, k] + 0.086 * q1[i, j, k]**2, 2.0) if q1[i, j, k] <= 2.0 else q1[i, j, k]
            )  # we use the MIN function for continuity
            else:
                cond_tmp = exp(1.2 * q1[i, j, k] - 1.0)
            cond_tmp *= sigma

            # cloud fraction
            cldfr[i, j, k] = (
                max(0.0, min(1.0, 0.5 + 0.36 * atan(1.55 * q1[i, j, k]))) if cond_tmp >= 1e-12 else 0
            )

            # Translation note : l487 to l489
            cond_tmp = 0 if cldfr[i, j, k] == 0 else cond_tmp

            if not OCND2:
                rc_out[i, j, k] = (1 - frac_tmp) * cond_tmp  # liquid condensate
                ri_out[i, j, k] = frac_tmp * cond_tmp  # solid condensate
                t[i, j, k] += ((rc_out[i, j, k] - rc[i, j, k]) * lv[i, j, k] + (ri_out[i, j, k] - ri[i, j, k]) * ls[i, j, k]) / cph[i, j, k]
                rv_out[i, j, k] = rt[i, j, k] - rc_out[i, j, k] - ri_out[i, j, k] * prifact

        # Translation note : end jiter


if __name__ == "__main__":

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]

    sdfg = condensation.to_sdfg()
    sdfg.save("condensation.sdfg")
    csdfg = sdfg.compile()

    state = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "sigqsat",
            "pabs",
            "sigs",
            "t",
            "rv",
            "ri",
            "rc",
            "cph",
            "lv",
            "ls",
            "q1",
            "cldfr",
        ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "rv_out",
            "rc_out",
            "ri_out",
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
        OCND2=True,
        FRAC_ICE_ADJUST=0,
        RD=1.0,
        RV=1.0,
        CONDENS=1,
        TMAXMIX=1.0,
        TMINMIX=1.0,
        LSIGMAS=True,
        LSTATNW=True,
        I=I,
        J=J,
        K=K
    )



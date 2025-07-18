# -*- coding: utf-8 -*-
from __future__ import annotations

from gt4py.cartesian.gtscript import Field, computation, interval, PARALLEL, IJ
from ifs_physics_common.framework.stencil import stencil_collection
from ifs_physics_common.utils.f2py import ported_method


@dace.program
def rain_ice_thermo(
    exn: dtype_float[I, J, K],
    ls_fact: dtype_float[I, J, K],
    lv_fact: dtype_float[I, J, K],
    th_t: dtype_float[I, J, K],
    rv_t: dtype_float[I, J, K],
    rc_t: dtype_float[I, J, K],
    rr_t: dtype_float[I, J, K],
    ri_t: dtype_float[I, J, K],
    rs_t: dtype_float[I, J, K],
    rg_t: dtype_float[I, J, K],
    C_RTMIN: dtype_float,
    R_RTMIN: dtype_float,
    I_RTMIN: dtype_float,
    S_RTMIN: dtype_float,
    G_RTMIN: dtype_float,
    CPD: dtype_float,
    CPV: dtype_float,
    CI: dtype_float,
    CL: dtype_float,
    TT: dtype_float,
    LSTT: dtype_float,
    LVTT: dtype_float,
):
    """_summary_

    Args:
        ldmicro (Field[bool]): mask for microphysical computations
        exn (Field[float]): exner pressure
        ls_fact (Field[float]): sublimation latent heat over capacity
        lv_fact (Field[float]): vaporisation latent heat over capacity
        th_t (Field[float]): potential temperature at t
        rv_t (Field[float]): vapour m.r. at t
        rc_t (Field[float]): cloud droplet m.r. at t
        rr_t (Field[float]): rain m.r. at t
        ri_t (Field[float]): ice m.r. at t
        rs_t (Field[float]): snow m.r.
        rg_t (Field[float]): graupel m.r.
    """

    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        divider = CPD + CPV * rv_t[i, j, k] + CL * (rc_t[i, j, k] + rr_t[i, j, k]) + CI * (ri_t[i, j, k] + rs_t[i, j, k] + rg_t[i, j, k])
        t[i, j, k] = th_t[i, j, k] * exn[i, j, k]
        ls_fact[i, j, k] = (LSTT + (CPV - CI) * (t[i, j, k] - TT)) / divider
        lv_fact[i, j, k] = (LVTT + (CPV - CL) * (t[i, j, k] - TT)) / divider


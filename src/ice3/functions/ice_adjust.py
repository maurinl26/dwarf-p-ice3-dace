# -*- coding: utf-8 -*-
from __future__ import annotations

import dace
from ice3.utils.typingx import dtype_float

@dace.program
def vaporisation_latent_heat(
    t: dtype_float,
    lv: dtype_float,
    LVTT: dtype_float,
    CPV: dtype_float,
    CL: dtype_float,
    TT: dtype_float
):
    """Computes latent heat of vaporisation

    Args:
        t (Field[float]): field of temperature

    Returns:
        Field[float]: point wise vaporisation latent heat
    """

    lv = LVTT + (CPV - CL) * (t - TT)

@dace.program
def sublimation_latent_heat(
    t: dtype_float,
    ls: dtype_float,
    LSTT: dtype_float,
    CPV: dtype_float,
    CI: dtype_float,
    TT: dtype_float
):
    """Computes latent heat of sublimation

    Args:
        t (Field[float]): field of temperature

    Returns:
        Field[float]: point wise sublimation latent heat
    """

    ls = LSTT + (CPV - CI) * (t - TT)


@dace.program
def constant_pressure_heat_capacity(
    rv: dtype_float,
    rc: dtype_float,
    ri: dtype_float,
    rr: dtype_float,
    rs: dtype_float,
    rg: dtype_float,
    cph: dtype_float,
    CPD: dtype_float,
    CPV: dtype_float,
    CL: dtype_float,
    CI: dtype_float
):
    """Compute specific heat at constant pressure for a
    moist parcel given mixing ratios

    Returns:
        Field[float]: specific heat of parcel
    """
    cph = CPD + CPV * rv + CL * (rc + rr) + CI * (ri + rs + rg)


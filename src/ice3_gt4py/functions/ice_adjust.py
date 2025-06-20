# -*- coding: utf-8 -*-
from __future__ import annotations

import dace
from ice3_gt4py.utils.typingx import dtype_float


@dace.program
def vaporisation_latent_heat(
    t: dtype_float,
    lv: dtype_float,
    CL: dace.compiletime,
    CPV: dace.compiletime,
    LVTT: dace.compiletime,
    TT: dace.compiletime
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
    CI: dace.compiletime,
    CPV: dace.compiletime,
    LSTT: dace.compiletime,
    TT: dace.compiletime
):
    """Computes latent heat of sublimation

    Args:
        t (Field[float]): field of temperature

    Returns:
        Field[float]: point wise sublimation latent heat
    """

    ls = LSTT + (CPV - CI) * (t - TT)


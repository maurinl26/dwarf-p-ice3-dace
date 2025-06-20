# -*- coding: utf-8 -*-
from __future__ import annotations

import dace
from ice3_gt4py.utils.typingx import dtype_float, dtype_int


@dace.program
def e_sat_w(
        t: dtype_float,
        pv: dtype_float,
        ALPW: dace.compiletime,
        BETAW: dace.compiletime,
        GAMW: dace.compiletime
):
    """Saturation vapor pressure over liquid water

    Args:
        t (Field[float]): temperature

    Returns:
        Field[float]: saturation vapor pressure
    """

    pv = exp(ALPW - BETAW / t - GAMW * log(t))


@dace.program
def e_sat_i(
    t: dtype_float,
    piv: dtype_float,
    ALPI: dace.compiletime,
    BETAI: dace.compiletime,
    GAMI: dace.compiletime
):
    """Saturation vapor pressure over ice

    Args:
        t (Field[float]): temperature

    Returns:
        Field[float]: saturation vapor pressure
    """

    piv = exp(ALPI - BETAI / t - GAMI * log(t))


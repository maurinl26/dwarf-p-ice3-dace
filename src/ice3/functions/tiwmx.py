# -*- coding: utf-8 -*-
import numpy as np

import dace
from ice3.utils.typingx import dtype_float, dtype_int

@dace.program
def e_sat_w(
        t: dtype_float,
        pv: dtype_float,
        ALPW: dtype_float,
        BETAW: dtype_float,
        GAMW: dtype_float
):
    """Saturation vapor pressure over liquid water

    Args:
        t (Field[float]): temperature

    Returns:
        Field[float]: saturation vapor pressure
    """

    pv = np.exp(ALPW - BETAW / t - GAMW * np.log(t))


@dace.program
def e_sat_i(
    t: dtype_float,
    piv: dtype_float,
    ALPI: dtype_float,
    BETAI: dtype_float,
    GAMI: dtype_float
):
    """Saturation vapor pressure over ice

    Args:
        t (Field[float]): temperature

    Returns:
        Field[float]: saturation vapor pressure
    """

    piv = np.exp(ALPI - BETAI / t - GAMI * np.log(t))


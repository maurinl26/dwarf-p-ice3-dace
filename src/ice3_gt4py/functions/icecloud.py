# -*- coding: utf-8 -*-
from __future__ import annotations

from gt4py.cartesian.gtscript import IJ, Field, function, sqrt

from ice3_gt4py.functions.tiwmx import esati, esatw


@function
def icecloud(
    p: Field[IJ, float],
    z: Field[IJ, float],
    dz: Field[IJ, float],
    t: Field[IJ, float],
    r: Field[IJ, float],
    pblh: float,
    wcld: Field[IJ, float],
    w2d: float,
    sifrc: Field[IJ, float],
    ssio: Field[IJ, float],
    ssiu: Field[IJ, float],
    w2d_out: Field[IJ, float],
    rsi: Field[IJ, float],
):
    """
    Calculate subgridscale fraction of supersaturation with respect to ice.
    Assume a linear distubution of relative humidity and let the variability
     of humidity be a function of model level thickness.
    (Also a function of of humidity itself in the boundary layer)

    Args:
        p (Field[IJ, float]): pressure at model level (Pa)
        z (Field[IJ, float]): model level height (m)
        dz (Field[IJ, float]): model level thickness (m)
        t (Field[IJ, float]): temperature (K)
        r (Field[IJ, float]): model level humidity mixing ratio (kg/kg)
        tstep (float): timestep
        pblh (float): planetary layer height (m) (negative values means unknown)
        wcld (Field[IJ, float]): water and mixed phase cloud cover (negative value means unknown)
        w2d_in (float): quota between ice crystal concentration between dry and wet

        sifrc (Field[IJ, float]): subgridscale fraction with supersaturation respect to ice
        ssio (Field[IJ, float]): super-saturation with respect to ice in the supersaturated fraction
        ssiu (Field[IJ, float]): sub-saturation with respect to ice in the sub saturated fraction
        w2d_out (Field[IJ, float]): factor used ti get consistency between the mean value of the gridbox and parts of the grid box
        rsi (Field[IJ, float]): saturation mixing ratio over ice

    Returns:
        Tuple[Field]: sifrc, ssio, ssiu, w2d_out, rsi
    """

    from __externals__ import TSTEP, LVTT, GRAVITY0, RD, CPD, EPSILO

    sigmax = 3e-4  # assumed rh variation in x axis direction
    sigmay = sigmax  # assumed rh variation in y axis direction
    sigmaz = 1e-2

    xdist = 2500  # gridsize in  x axis (m)
    ydist = xdist  # gridsize in  y axis (m)

    zr = max(0, r[0, 0, 0] * TSTEP)
    sifrc = 0
    a = zr[0, 0, 0] * p[0, 0, 0] / (EPSILO + zr)

    # TODO : implementer esatw, esati
    rhw = a / esatw(t[0, 0, 0])
    rhi = a / esati(t[0, 0, 0])
    i2w = esatw(t[0, 0, 0]) / esati(t[0, 0, 0])

    ssiu = min(i2w, rhi)
    ssio = ssiu[0, 0, 0]
    w2d = 1

    if t[0, 0, 0] > 273.1 or r <= 0 or esati(t[0, 0, 0]) >= p[0, 0, 0] * 0.5:
        ssiu -= 1
        ssio = ssiu
        if wcld >= 0:
            sifrc = wcld[0, 0, 0]

    rhin = max(0.05, min(1, rhw))
    drhdz = (
        rhin * GRAVITY0 / (t[0, 0, 0] * RD) * (EPSILO * LVTT / (CPD * t[0, 0, 0]) - 1)
    )

    zz = 0
    if pblh < 0:
        # assume boundary layer height is not available
        zz = min(1, max(0, z[0, 0, 0] * 0.001))
    elif z[0, 0, 0] > 35 and z[0, 0, 0] > pblh:
        zz = 1

    rhdist = sqrt(
        xdist * sigmax**2
        + ydist * sigmay**2
        + (1 - zz) * (dz[0, 0, 0] * drhdz) ** 2
        + zz * dz[0, 0, 0] * sigmaz**2
    )

    # Compute rh variations in x, y, z direction as approximately independant
    # except for the z variation
    # z variation of rh is assumed to be fairly constantly increasing with height
    if zz > 0.1:
        rhdist /= 1 + rhdist

    rhlim = max(0.5, min(0.99, 1 - 0.5 * rhdist))
    if wcld < 0:
        rhdif = 1 - sqrt(max(0, (1 - rhw) / (1 - rhlim)))
        wcld = min(1, max(rhdif, 0))

    else:
        wcld = wcld[0, 0, 0]

    sifrc = wcld

    rhlimice = 1 + i2w * (rhlim - 1)
    if rhlim < 0.999:
        rhliminv = 1 / (1 - rhlimice)
        rhdif = (rhi - rhlimice) * rhliminv

        if wcld == 0:
            sifrc = min(1, 0.5 * max(0, rhdif))
        else:
            sifrc = min(1, a * 0.5 / (1 - rhlim))
            sifrc = min(1, wcld + sifrc)

    if sifrc > 0.01:
        ssiu = min(1, a * 0.5 / (1 - rhlim))
        ssio = (rhi - (1 - sifrc) * ssiu) / sifrc
    else:
        sifrc = 0
        a = min(1, a * 0.5 / (1 - rhlim))
        ssiu = max(0, sifrc + rhlimice * (1 - sifrc) + 2 * a)

    ssiu -= 1
    ssio -= 1

    if w2d > 1:
        w2d_out = 1 / (1 - (1 + w2d) * sifrc)

    return sifrc, ssio, ssiu, w2d_out, rsi

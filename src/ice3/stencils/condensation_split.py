import dace
import numpy as np

from ice3.utils.dims import I, J, K
from ice3.utils.typingx import dtype_int, dtype_float


FRAC_ICE_ADJUST = dace.symbol("FRAC_ICE_ADJUST", dtype=dace.bool)
LAMBDA3 = dace.symbol("LAMBDA3", dtype=dace.bool)

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
    sigrc: dtype_float[I, J, K],
    OCND2: dace.bool,
    RD: dtype_float,
    RV: dtype_float,
    TMAXMIX: dtype_float,
    TMINMIX: dtype_float,
    LSIGMAS: dace.bool,
    LSTATNW: dace.bool,
    ALPW: dtype_float,
    BETAW: dtype_float,
    GAMW: dtype_float,
    ALPI: dtype_float,
    BETAI: dtype_float,
    GAMI: dtype_float,
):
    """Microphysical adjustments for specific contents due to condensation."""

    rt = np.ndarray(shape=[I, J, K], dtype=dtype_float)
    pv = np.ndarray(shape=[I, J, K], dtype=dtype_float)
    piv = np.ndarray(shape=[I, J, K], dtype=dtype_float)

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
            pv[i, j, k] = np.exp(ALPW - BETAW / t[i, j, k] - GAMW * np.log(t[i, j, k]))
            pv[i, j, k] = min(
            pv[i, j, k],
            0.99 * pabs[i, j, k],
            )

            piv[i, j, k] = np.exp(ALPI - BETAI / t[i, j, k] - GAMI * np.log(t[i, j, k]))
            piv[i, j, k] = min(
            piv[i, j, k],
            0.99 * pabs[i, j, k],
            )

        if not OCND2:
            if rc[i, j, k] + ri[i, j, k] > 1e-20:
                frac_tmp = rc[i, j, k] / (rc[i, j, k] + ri[i, j, k])
            else:
                frac_tmp = 0

            # Compute frac ice inlined
            # Default Mode (S)


            # AROME mode
            if FRAC_ICE_ADJUST:
                frac_tmp = max(0,
                               min(1,
                                   ((TMAXMIX - t[i, j, k]) / (TMAXMIX - TMINMIX))
                                   ))

            else:
                frac_tmp = max(0, min(1, frac_tmp))

        
        # Supersaturation coefficients
        qsl = RD / RV * pv[i, j, k] / (pabs[i, j, k] - pv[i, j, k])
        qsi = RD / RV * piv[i, j, k] / (pabs[i, j, k] - piv[i, j, k])

        # interpolate between liquid and solid as a function of temperature
        qsl = (1 - frac_tmp) * qsl + frac_tmp * qsi
        lvs = (1 - frac_tmp) * lv[i, j, k] + frac_tmp * ls[i, j, k]

        # coefficients a et b
        ah = lvs * qsl / (RV * t[i, j, k]**2) * (1 + RV * qsl / RD)
        a = 1 / (1 + lvs / cph[i, j, k] * ah)
        b = ah * a
        sbar = a * (rt[i, j, k] - qsl + ah * lvs * (rc[i, j, k] + ri[i, j, k] * prifact) / cph[i, j, k])

        if LSIGMAS and not LSTATNW:
            sigma = max(
                1e-10,
                np.sqrt(
                    (2 * sigs[i, j, k]) ** 2
                    + (sigqsat[i, j, k] * qsl * a) ** 2
                )
            )


        # Translation note : l407 - l411
        q1 = sbar / sigma

        # 9.2.3 Fractional cloudiness and cloud condensate
        # HCONDENS = 0 is CB02 option
        # Translation note : l470 to l479
        if q1 > 0.0:
                if q1 <= 2.0:
                    cond_tmp = (
                min(np.exp(-1.0) + 0.66 * q1 + 0.086 * q1**2, 2.0)
            )  # we use the MIN function for continuity
                else:
                    cond_tmp = q1
        else:
                cond_tmp = np.exp(1.2 * q1 - 1.0)
        cond_tmp *= sigma

        # cloud fraction
        if cond_tmp > 1e-12:
                cldfr[i, j, k] = (
                max(0.0, min(1.0, 0.5 + 0.36 * np.arctan(1.55 * q1)))
            )
        else:
                cldfr[i, j, k] = 0

        # Translation note : l487 to l489
        if cldfr[i, j, k] == 0:
                cond_tmp = 0

        if not OCND2:
                rc_out[i, j, k] = (1 - frac_tmp) * cond_tmp  # liquid condensate
                ri_out[i, j, k] = frac_tmp * cond_tmp  # solid condensate
                t[i, j, k] += ((rc_out[i, j, k] - rc[i, j, k]) * lv[i, j, k] + (ri_out[i, j, k] - ri[i, j, k]) * ls[i, j, k]) / cph[i, j, k]
                rv_out[i, j, k] = rt[i, j, k] - rc_out[i, j, k] - ri_out[i, j, k] * prifact

        # Translation note : end jiter

        # lambda3 = 0 in AROME
        if LAMBDA3:
            sigrc[i, j, k] *= min(3, max(1, 1 - q1))


if __name__ == "__main__":
    import numpy as np

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
            "cldfr",
            "cph",
            "lv",
            "ls",
        ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "rv_out",
            "rc_out",
            "ri_out",
            "sigrc"
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
        FRAC_ICE_ADJUST=True,
        RD=1.0,
        RV=1.0,
        TMAXMIX=1.0,
        TMINMIX=1.0,
        LSIGMAS=True,
        LSTATNW=True,
        ALPW=1.0,
        BETAW=1.0,
        GAMW=1.0,
        ALPI=1.0,
        BETAI=1.0,
        GAMI=1.0,
        LAMBDA3=True,
        I=I,
        J=J,
        K=K
    )

    print(outputs["rv_out"].mean())



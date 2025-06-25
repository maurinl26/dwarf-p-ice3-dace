import dace

from ice3.utils.dims import I, J, K
from ice3.utils.typingx import dtype_float, dtype_int

SUBG_MF_PDF = dace.symbol("SUBG_MF_PDF")


@dace.program
def cloud_fraction_1(
    lv: dtype_float[I, J, K],
    ls: dtype_float[I, J, K],
    cph: dtype_float[I, J, K],
    exnref: dtype_float[I, J, K],
    rc: dtype_float[I, J, K],
    ri: dtype_float[I, J, K],
    rc_tmp: dtype_float[I, J, K],
    ri_tmp: dtype_float[I, J, K],
    ths0: dtype_float[I, J, K],
    rvs0: dtype_float[I, J, K],
    rcs0: dtype_float[I, J, K],
    ris0: dtype_float[I, J, K],
    ths1: dtype_float[I, J, K],
    rvs1: dtype_float[I, J, K],
    rcs1: dtype_float[I, J, K],
    ris1: dtype_float[I, J, K],
    dt: dtype_float,
):
    """Cloud fraction computation (after condensation loop)"""

    ##### 5.     COMPUTE THE SOURCES AND STORES THE CLOUD FRACTION #####
    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        # 5.0 compute the variation of mixing ratio
        w1 = (rc_tmp[i, j, k] - rc[i, j, k]) / dt
        w2 = (ri_tmp[i, j, k] - ri[i, j, k]) / dt

        # 5.1 compute the sources
        if w1 < 0.0:
            w1 = max(w1, -rcs0[i, j, k])
        else:
            w1 = min(w1, rvs0[i, j, k])
        rvs1[i, j, k] -= w1
        rcs1[i, j, k] += w1
        ths1[i, j, k] += w1 * lv[i, j, k] / (cph[i, j, k] * exnref[i, j, k])

        if w2 < 0.0:
            w2 = max(w2, -ris0[i, j, k])
        else:
            w2 = min(w2, rvs0[i, j, k])
        rvs1[i, j, k] = rvs0[i, j, k] + w2
        ris1[i, j, k] = ris0[i, j, k] + w2
        ths1[i, j, k] = ths0[i, j, k] + w2 * ls[i, j, k] / (cph[i, j, k] * exnref[i, j, k])

        #### split


@dace.program
def cloud_fraction_2(
    rhodref: dtype_float[I, J, K],
    exnref: dtype_float[I, J, K],
    t: dtype_float[I, J, K],
    cph: dtype_float[I, J, K],
    lv: dtype_float[I, J, K],
    ls: dtype_float[I, J, K],
    ths1: dtype_float[I, J, K],
    rvs1: dtype_float[I, J, K],
    rcs1: dtype_float[I, J, K],
    ris1: dtype_float[I, J, K],
    rc_mf: dtype_float[I, J, K],
    ri_mf: dtype_float[I, J, K],
    cf_mf: dtype_float[I, J, K],
    cldfr: dtype_float[I, J, K],
    hlc_hrc: dtype_float[I, J, K],
    hlc_hcf: dtype_float[I, J, K],
    hli_hri: dtype_float[I, J, K],
    hli_hcf: dtype_float[I, J, K],
    dt: dtype_float,
    LSUBG_COND: dace.bool,
    CRIAUTC: dtype_float,
    CRIAUTI:  dtype_float,
    ACRIAUTI: dtype_float,
    BCRIAUTI: dtype_float,
    TT: dtype_float
):

    # 5.2  compute the cloud fraction cldfr
    for i, j, k in dace.map[0:I, 0:J, 0:K]:

        if not LSUBG_COND:
            if (rcs1[i, j, k] + ris1[i, j, k])*dt > 1e-12:
                cldfr[i, j, k] = 1.0
            else:
                cldfr[i, j, k] = 0.0

        else:
            w1 = rc_mf[i, j, k] / dt
            w2 = ri_mf[i, j, k] / dt

            if w1 + w2 > rvs1[i, j, k]:
                w1 *= rvs1[i, j, k] / (w1 + w2)
                w2 = rvs1[i, j, k] - w1

            cldfr[i, j, k] = min(1, cldfr[i, j, k] + cf_mf[i, j, k])
            rcs1[i, j, k] += w1
            ris1[i, j, k] += w2
            rvs1[i, j, k] -= (w1 + w2)
            ths1[i, j, k] += (w1 * lv[i, j, k] + w2 * ls[i, j, k]) / (cph[i, j, k] * exnref[i, j, k])

            criaut = CRIAUTC / rhodref[i, j, k]

            if SUBG_MF_PDF == 0:
                if w1 * dt > cf_mf[i, j, k] * criaut:
                    hlc_hrc[i, j, k] += w1 * dt
                    hlc_hcf[i, j, k] = min(1.0, hlc_hcf[i, j, k] + cf_mf[i, j, k])

            if SUBG_MF_PDF == 1:
                if w1 * dt > cf_mf[i, j, k] * criaut:
                    hcf = 1.0 - 0.5 * (criaut * cf_mf[i, j, k] / max(1e-20, w1 * dt)) ** 2
                    hr = w1 * dt - (criaut * cf_mf[i, j, k]) ** 3 / (
                        3 * max(1e-20, w1 * dt) ** 2
                    )

                elif 2.0 * w1 * dt <= cf_mf[i, j, k] * criaut:
                    hcf = 0.0
                    hr = 0.0

                else:
                    hcf = (2.0 * w1 * dt - criaut * cf_mf[i, j, k]) ** 2 / (
                        2.0 * max(1.0e-20, w1 * dt) ** 2
                    )
                    hr = (
                        4.0 * (w1 * dt) ** 3
                        - 3.0 * w1 * dt * (criaut * cf_mf[i, j, k]) ** 2
                        + (criaut * cf_mf[i, j, k] ** 3)
                    ) / (3 * max(1.0e-20, w1 * dt) ** 2)

                hcf *= cf_mf[i, j, k]
                hlc_hcf[i, j, k] = min(1.0, hlc_hcf[i, j, k] + hcf)
                hlc_hrc[i, j, k] += hr

            # Ice subgrid autoconversion
            criaut = min(
                CRIAUTI,
                10 ** (ACRIAUTI * (t[i, j, k] - TT) + BCRIAUTI),
            )

            # LLNONE in ice_adjust.F90
            if SUBG_MF_PDF == 0:
                if w2 * dt > cf_mf[i, j, k] * criaut:
                    hli_hri[i, j, k] += w2 * dt
                    hli_hcf[i, j, k] = min(1.0, hli_hcf[i, j, k] + cf_mf[i, j, k])

            # LLTRIANGLE in ice_adjust.F90
            if SUBG_MF_PDF == 1:
                if w2 * dt > cf_mf[i, j, k] * criaut:
                    hcf = 1.0 - 0.5 * ((criaut * cf_mf[i, j, k]) / (w2 * dt)) ** 2
                    hri = w2 * dt - (criaut * cf_mf[i, j, k]) ** 3 / (3 * (w2 * dt) ** 2)

                elif 2 * w2 * dt <= cf_mf[i, j, k] * criaut:
                    hcf = 0.0
                    hri = 0.0

                else:
                    hcf = (2.0 * w2 * dt - criaut * cf_mf[i, j, k]) ** 2 / (
                        2.0 * (w2 * dt) ** 2
                    )
                    hri = (
                        4.0 * (w2 * dt) ** 3
                        - 3.0 * w2 * dt * (criaut * cf_mf[i, j, k]) ** 2
                        + (criaut * cf_mf[i, j, k]) ** 3
                    ) / (3.0 * (w2 * dt) ** 2)

                hcf *= cf_mf[i, j, k]
                hli_hcf[i, j, k] = min(1.0, hli_hcf[i, j, k] + hcf)
                hli_hri[i, j, k] += hri

if __name__ == "__main__":
    import numpy as np

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]

    ############## Cloud Fraction 1 ###############

    sdfg1 = cloud_fraction_1.to_sdfg()
    sdfg1.save("cloud_fraction_1.sdfg")
    csdfg1 = sdfg1.compile()

    state = {
        name: dace.ndarray(shape=[I, J, K], dtype=dtype_float)
        for name in [
            "lv",
    "ls",
    "cph",
    "exnref",
    "rc",
    "ri",
    "rc_tmp",
    "ri_tmp",
    "ths0",
    "rvs0",
    "rcs0",
    "ris0",
           ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dtype_float)
        for name in [
             "ths1",
    "rvs1",
    "rcs1",
    "ris1",
        ]
    }

    print("Allocation \n")
    for key, storage in state.items():
        storage[:, :, :] = np.ones(domain, dtype=np.float64)
    for key, storage in outputs.items():
        storage[:, :, :] = np.zeros(domain, dtype=np.float64)

    print("Call ")
    csdfg1(
        **state,
        **outputs,
        dt=50.0,
        I=I,
        J=J,
        K=K
    )

    print(outputs["rvs1"].mean())

    #### Cloud Fraction 2 ########
    print("\n Cloud fraction 2 \n")

    sdfg2 = cloud_fraction_2.to_sdfg()
    sdfg2.save("cloud_fraction_2.sdfg")
    csdfg2 = sdfg2.compile()

    state = {
        name: dace.ndarray(shape=[I, J, K], dtype=dtype_float)
        for name in [
            "rhodref",
    "exnref",
    "t",
    "cph",
    "lv",
    "ls",
    "rc_mf",
    "ri_mf",
    "cf_mf",
    "cldfr",
            "ths1",
            "rvs1",
            "rcs1",
            "ris1",
        ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dtype_float)
        for name in [

            "hlc_hrc",
            "hlc_hcf",
            "hli_hri",
            "hli_hcf",
        ]
    }

    print("Allocation \n")
    for key, storage in state.items():
        storage[:, :, :] = np.ones(domain, dtype=np.float64)
    for key, storage in outputs.items():
        storage[:, :, :] = np.zeros(domain, dtype=np.float64)

    print("Call ")
    csdfg2(
        **state,
        **outputs,
        dt=50.0,
        LSUBG_COND=True,
    CRIAUTC=1.0,
    SUBG_MF_PDF=0,
    CRIAUTI=1.0,
    ACRIAUTI=1.0,
    BCRIAUTI=1.0,
    TT=1.0,
        I=I,
        J=J,
        K=K
    )

    print(outputs["hlc_hrc"].mean())
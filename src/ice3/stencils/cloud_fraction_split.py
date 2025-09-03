import dace

from ice3.utils.dims import IJ, K
from ice3.utils.typingx import dtype_float, dtype_int

SUBG_MF_PDF = dace.symbol("SUBG_MF_PDF")


@dace.program
def cloud_fraction_1(
    lv: dtype_float[IJ, K],
    ls: dtype_float[IJ, K],
    cph: dtype_float[IJ, K],
    exnref: dtype_float[IJ, K],
    rc: dtype_float[IJ, K],
    ri: dtype_float[IJ, K],
    rc_tmp: dtype_float[IJ, K],
    ri_tmp: dtype_float[IJ, K],
    ths0: dtype_float[IJ, K],
    rvs0: dtype_float[IJ, K],
    rcs0: dtype_float[IJ, K],
    ris0: dtype_float[IJ, K],
    ths1: dtype_float[IJ, K],
    rvs1: dtype_float[IJ, K],
    rcs1: dtype_float[IJ, K],
    ris1: dtype_float[IJ, K],
    dt: dtype_float,
):
    """Cloud fraction computation (after condensation loop)"""

    ##### 5.     COMPUTE THE SOURCES AND STORES THE CLOUD FRACTION #####
    for ij, k in dace.map[0:IJ, 0:K]:
        # 5.0 compute the variation of mixing ratio
        w1 = (rc_tmp[ij, k] - rc[ij, k]) / dt
        w2 = (ri_tmp[ij, k] - ri[ij, k]) / dt

        # 5.1 compute the sources
        if w1 < 0.0:
            w1 = max(w1, -rcs0[ij, k])
        else:
            w1 = min(w1, rvs0[ij, k])
        rvs1[ij, k] -= w1
        rcs1[ij, k] += w1
        ths1[ij, k] += w1 * lv[ij, k] / (cph[ij, k] * exnref[ij, k])

        if w2 < 0.0:
            w2 = max(w2, -ris0[ij, k])
        else:
            w2 = min(w2, rvs0[ij, k])
        rvs1[ij, k] = rvs0[ij, k] + w2
        ris1[ij, k] = ris0[ij, k] + w2
        ths1[ij, k] = ths0[ij, k] + w2 * ls[ij, k] / (cph[ij, k] * exnref[ij, k])

        #### split

if __name__ == "__main__":
    import numpy as np

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]
    IJ = I * J

    ############## Cloud Fraction 1 ###############

    sdfg1 = cloud_fraction_1.to_sdfg()
    sdfg1.save("sdfg/cloud_fraction_1.sdfg")
    csdfg1 = sdfg1.compile()

    state = {
        name: dace.ndarray(shape=[IJ, K], dtype=dtype_float)
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
        name: dace.ndarray(shape=[IJ, K], dtype=dtype_float)
        for name in [
            "ths1",
            "rvs1",
            "rcs1",
            "ris1",
        ]
    }

    print("Allocation \n")
    for key, storage in state.items():
        storage[:, :] = np.ones((IJ, K), dtype=np.float64)
    for key, storage in outputs.items():
        storage[:, :] = np.zeros((IJ, K), dtype=np.float64)

    print("Call ")
    csdfg1(
        **state,
        **outputs,
        dt=50.0,
        IJ=IJ,
        K=K
    )

    print(outputs["rvs1"].mean())


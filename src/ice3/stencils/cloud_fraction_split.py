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


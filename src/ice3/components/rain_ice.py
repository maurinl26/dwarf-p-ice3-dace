# -*- coding: utf-8 -*-
import dace
import numpy as np

from dace.dtypes import float64, compiletime
from ice3.stencils.rain_ice_init import rain_ice_thermo

from ice3.utils.typingx import dtype_float, dtype_int
from ice3.utils.dims import I, J, K

@dace.program
def rain_ice(
    exn: dtype_float[I, J, K],
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
    lv_fact = np.ndarray([I, J, K], dtype=dtype_float)
    ls_fact = np.ndarray([I, J, K], dtype=dtype_float)

    ldmicro = np.ndarray([I, J, K], dtype=dace.bool)
    lw3d = np.ndarray([I, J, K], dtype=dtype_float)
    rvheni = np.ndarray([I, J, K], dtype=dtype_float)
    sigma_rc = np.ndarray([I, J, K], dtype=dtype_float)
    hlc_lcf = np.ndarray([I, J, K], dtype=dtype_float)
    hlc_lrc = np.ndarray([I, J, K], dtype=dtype_float)
    hli_lcf = np.ndarray([I, J, K], dtype=dtype_float)
    hli_lri = np.ndarray([I, J, K], dtype=dtype_float)
    wr_th = np.ndarray([I, J, K], dtype=dtype_float)
    wr_v = np.ndarray([I, J, K], dtype=dtype_float)
    wr_c = np.ndarray([I, J, K], dtype=dtype_float)
    wr_r = np.ndarray([I, J, K], dtype=dtype_float)
    wr_i = np.ndarray([I, J, K], dtype=dtype_float)
    wr_s = np.ndarray([I, J, K], dtype=dtype_float)
    wr_g = np.ndarray([I, J, K], dtype=dtype_float)
    w3d = np.ndarray([I, J, K], dtype=dtype_float)
    inpri = np.ndarray([I, J, K], dtype=dtype_float)
    remaining_time = np.ndarray([I, J, K], dtype=dtype_float)

    # l421 to l434 removed
    rain_ice_thermo(
        exn,
        ls_fact,
        lv_fact,
        th_t,
        rv_t,
        rc_t,
        rr_t,
        ri_t,
        rs_t,
        rg_t,
        C_RTMIN,
        R_RTMIN,
        I_RTMIN,
        S_RTMIN,
        G_RTMIN,
        CPD,
        CPV,
        CI,
        CL,
        TT,
        LSTT,
        LVTT,
    )


if __name__ == "__main__":
    import numpy as np

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]

    sdfg = rain_ice.to_sdfg()
    sdfg.save("rain_ice.sdfg")
    csdfg = sdfg.compile()

    state = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "exn",
        ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "th_t",
            "rv_t",
            "rc_t",
            "rr_t",
            "ri_t",
            "rs_t",
            "rg_t",
        ]
    }

    print("Allocation \n")
    for key, storage in state.items():
        storage[:, :, :] = np.ones(domain, dtype=np.float64)
    for key, storage in outputs.items():
        storage[:, :, :] = np.zeros(domain, dtype=np.float64)

    print("Call ")
    csdfg(
        exn,
        ls_fact,
        lv_fact,
        th_t,
        rv_t,
        rc_t,
        rr_t,
        ri_t,
        rs_t,
        rg_t,
        C_RTMIN,
        R_RTMIN,
        I_RTMIN,
        S_RTMIN,
        G_RTMIN,
        CPD,
        CPV,
        CI,
        CL,
        TT,
        LSTT,
        LVTT,
        I=I,
        J=J,
        K=K
    )

    print(outputs["hlc_hrc"].mean())






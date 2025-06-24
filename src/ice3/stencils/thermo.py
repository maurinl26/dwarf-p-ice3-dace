import dace

from ice3.functions.ice_adjust import vaporisation_latent_heat, sublimation_latent_heat
from ice3.utils.dims import I, J, K
from ice3.utils.typingx import dtype_float, dtype_int

@dace.program
def thermodynamic_fields(
    th: dtype_float[I, J, K],
    exn: dtype_float[I, J, K],
    rv: dtype_float[I, J, K],
    rc: dtype_float[I, J, K],
    rr: dtype_float[I, J, K],
    ri: dtype_float[I, J, K],
    rs: dtype_float[I, J, K],
    rg: dtype_float[I, J, K],
    lv: dtype_float[I, J, K],
    ls: dtype_float[I, J, K],
    cph: dtype_float[I, J, K],
    t: dtype_float[I, J, K],
    NRR: dtype_float,
    CPD: dtype_float,
    CPV: dtype_float,
    CL: dtype_float,
    CI: dtype_float,
    LVTT: dtype_float,
    LSTT: dtype_float,
    TT: dtype_float
):

    # 2.3 Compute the variation of mixing ratio
    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        t[i, j, k] = exn[i, j, k] * th[i, j, k]
        vaporisation_latent_heat(lv[i, j, k], t[i, j, k], LVTT=LVTT, CPV=CPV, CL=CL, TT=TT)
        sublimation_latent_heat(ls[i, j, k], t[i, j, k],  LSTT=LVTT, CPV=CPV, CI=CI, TT=TT)

    # 2.4 specific heat for moist air at t+1
    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        if NRR == 6:
            cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k]) + CI * (ri[i, j, k] + rs[i, j, k] + rg[i, j, k])
        if NRR == 5:
            cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k]) + CI * (ri[i, j, k] + rs[i, j, k])
        if NRR == 4:
            cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * (rc[i, j, k] + rr[i, j, k])
        if NRR == 2:
            cph[i, j, k] = CPD + CPV * rv[i, j, k] + CL * rc[i, j, k] + CI * ri[i, j, k]

if __name__ == "__main__":
    import numpy as np

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]

    sdfg = thermodynamic_fields.to_sdfg()
    sdfg.save("thermo.sdfg")
    csdfg = sdfg.compile()

    state = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "th",
            "exn",
            "rv",
            "rc",
            "rr",
            "ri",
            "rs",
            "rg",
        ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dace.float64)
        for name in [
            "cph",
            "lv",
            "ls",
            "t",
        ]
    }

    print("Allocation \n")
    for key, storage in state.items():
        storage[:,:,:] = np.ones(domain, dtype=np.float64)
    for key, storage in outputs.items():
        storage[:,:,:] = np.zeros(domain, dtype=np.float64)

    print("Call ")
    csdfg(
        **state,
        **outputs,
        NRR=6,
        CPD=1.0,
        CPV=1.0,
        CL=1.0,
        CI=1.0,
        LSTT=1.0,
        LVTT=1.0,
        TT=1.0,
        I=I,
        J=J,
        K=K
    )

    print(outputs["cph"].mean())

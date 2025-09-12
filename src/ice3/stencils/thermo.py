import dace

from ice3.utils.dims import IJ, K
from ice3.utils.typingx import dtype_float, dtype_int

NRR = dace.symbol("NRR", dtype=dace.int32)

@dace.program
def thermodynamic_fields(
    th: dtype_float[IJ, K],
    exn: dtype_float[IJ, K],
    rv: dtype_float[IJ, K],
    rc: dtype_float[IJ, K],
    rr: dtype_float[IJ, K],
    ri: dtype_float[IJ, K],
    rs: dtype_float[IJ, K],
    rg: dtype_float[IJ, K],
    lv: dtype_float[IJ, K],
    ls: dtype_float[IJ, K],
    cph: dtype_float[IJ, K],
    t: dtype_float[IJ, K],
    CPD: dtype_float,
    CPV: dtype_float,
    CL: dtype_float,
    CI: dtype_float,
    LVTT: dtype_float,
    LSTT: dtype_float,
    TT: dtype_float
):

    # 2.3 Compute the variation of mixing ratio
    for ij, k in dace.map[0:IJ, 0:K]:
        t[ij, k] = exn[ij, k] * th[ij, k]
        lv[ij, k] = LVTT + (CPV - CL) * (t[ij, k] - TT)
        ls[ij, k] = LSTT + (CPV - CI) * (t[ij, k] - TT)

    # 2.4 specific heat for moist air at t+1
    for ij, k in dace.map[0:IJ, 0:K]:
        if NRR == 6:
            cph[ij, k] = CPD + CPV * rv[ij, k] + CL * (rc[ij, k] + rr[ij, k]) + CI * (ri[ij, k] + rs[ij, k] + rg[ij, k])
        if NRR == 5:
            cph[ij, k] = CPD + CPV * rv[ij, k] + CL * (rc[ij, k] + rr[ij, k]) + CI * (ri[ij, k] + rs[ij, k])
        if NRR == 4:
            cph[ij, k] = CPD + CPV * rv[ij, k] + CL * (rc[ij, k] + rr[ij, k])
        if NRR == 2:
            cph[ij, k] = CPD + CPV * rv[ij, k] + CL * rc[ij, k] + CI * ri[ij, k]

if __name__ == "__main__":
    import numpy as np

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]
    IJ = I * J

    sdfg = thermodynamic_fields.to_sdfg()
    sdfg.save("sdfg/thermo.sdfg")
    csdfg = sdfg.compile()

    state = {
        name: dace.ndarray(shape=[IJ, K], dtype=dtype_float)
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
        name: dace.ndarray(shape=[IJ, K], dtype=dtype_float)
        for name in [
            "cph",
            "lv",
            "ls",
            "t",
        ]
    }

    print("Allocation \n")
    for key, storage in state.items():
        storage[:,:] = np.ones((IJ, K), dtype=np.float64)
    for key, storage in outputs.items():
        storage[:,:] = np.zeros((IJ, K), dtype=np.float64)

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
        IJ=IJ,
        K=K
    )

    print(outputs["cph"].mean())

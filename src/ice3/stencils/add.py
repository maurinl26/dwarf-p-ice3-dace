import dace

from ice3.utils.dims import I, J, K
from ice3.utils.typingx import dtype_float, dtype_int


@dace.program
def add(
        a: dtype_float[I, J, K],
        b: dtype_float[I, J, K],
        c: dtype_float[I, J, K]
):

    for i, j, k in dace.map[0:I, 0:J, 0:K]:
        c[i, j, k] = a[i, j, k] + b[i, j, k]


if __name__ == "__main__":
    import numpy as np

    domain = 50, 50, 15
    I = domain[0]
    J = domain[1]
    K = domain[2]

    sdfg = add.to_sdfg()
    sdfg.save("add.sdfg")
    csdfg = sdfg.compile()

    state = {
        name: dace.ndarray(shape=[I, J, K], dtype=dtype_float)
        for name in [
            "a",
            "b"
        ]
    }

    outputs = {
        name: dace.ndarray(shape=[I, J, K], dtype=dtype_float)
        for name in [
            "c"
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
        I=I,
        J=J,
        K=K
    )

    print(outputs["c"].mean())

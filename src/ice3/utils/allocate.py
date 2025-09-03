from typing import Dict, Tuple
import dace
import numpy as np

def allocate(
    domain: Tuple[int],
    state: Dict[str, dace.ndarray],
    outputs: Dict[str, dace.ndarray],
):
    
    for key, storage in state.items():
        storage[:, :] = np.ones((domain[0] * domain[1], domain[2]), dtype=np.float64)
    for key, storage in outputs.items():
        storage[:, :] = np.zeros((domain[0] * domain[1], domain[2]), dtype=np.float64)
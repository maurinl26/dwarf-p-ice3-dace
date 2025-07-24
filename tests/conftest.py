import pytest
import numpy as np
from dataclasses import dataclass
from typing import Dict, Any, Tuple, List
import logging

# Mock classes for testing when dependencies are not available
@dataclass
class MockGT4PyConfig:
    """Mock GT4Py configuration for testing"""
    backend: str = "numpy"
    dtypes: Any = None
    
    def __post_init__(self):
        if self.dtypes is None:
            self.dtypes = MockDTypes()

@dataclass 
class MockDTypes:
    """Mock data types configuration"""
    float: type = np.float64
    int: type = np.int32
    
    def with_precision(self, precision: str):
        """Return new dtypes with specified precision"""
        new_dtypes = MockDTypes()
        if precision == "single":
            new_dtypes.float = np.float32
        elif precision == "double":
            new_dtypes.float = np.float64
        return new_dtypes

class MockPhyex:
    """Mock PHYEX configuration for testing"""
    
    def __init__(self):
        # Default constants and parameters
        self.constants = {
            "RV": 461.5,
            "RD": 287.0,
            "ALPI": 0.0,
            "BETAI": 0.0,
            "GAMI": 0.0,
            "ALPW": 0.0,
            "BETAW": 0.0,
            "GAMW": 0.0,
            "TMAXMIX": 273.16,
            "TMINMIX": 233.16,
            "LVTT": 2.5e6,
            "LSTT": 2.834e6,
            "CPV": 1846.0,
            "CI": 2106.0,
            "CL": 4218.0,
            "TT": 273.16,
            "CPD": 1004.0,
            "LAMBDA3": 0.0,
        }
        
        self.logicals = {
            "LSIGMAS": True,
            "OCND2": False,
            "OUSERI": True,
            "FRAC_ICE_ADJUST": "S",
            "CONDENS": "CB02",
            "LSTATNW": False,
            "LSUBG_COND": True,
            "SUBG_MF_PDF": 0,
        }
    
    def to_externals(self) -> Dict[str, Any]:
        """Convert to externals dictionary"""
        return {**self.constants, **self.logicals}

def get_backends() -> List[str]:
    """Get available backends for testing"""
    # Return basic backends that should work without additional dependencies
    return ["numpy"]

def compile_fortran_stencil(filename: str, module: str, subroutine: str):
    """Mock Fortran stencil compilation for testing"""
    def mock_fortran_function(*args, **kwargs):
        # Return mock results based on the subroutine name
        if subroutine == "condensation":
            # Return mock condensation results
            return [np.zeros((10, 10)) for _ in range(16)]  # 16 output fields
        elif subroutine == "sigrc_computation":
            # Return mock sigrc computation results
            return [np.zeros((10, 10)), np.ones((10, 10))]  # psigrc, inq1
        elif subroutine == "global_table":
            # Return mock global table
            return np.ones(34, dtype=np.float32)
        elif subroutine == "latent_heat":
            # Return mock thermodynamic fields
            return [np.zeros((10, 10)) for _ in range(4)]  # t, lv, ls, cph
        elif subroutine in ["cloud_fraction_1", "cloud_fraction_2"]:
            # Return mock cloud fraction results
            return [np.zeros((10, 10)) for _ in range(4)]
        else:
            # Generic mock return
            return [np.zeros((10, 10))]
    
    return mock_fortran_function

# Basic fixtures
@pytest.fixture(name="domain", scope="module")
def domain_fixture():
    return (50, 50, 15)

@pytest.fixture(name="origin", scope="module")
def origin_fixture():
    return (0, 0, 0)

@pytest.fixture(name="grid", scope="module")
def grid_fixture(domain):
    """Create a grid with the specified domain shape"""
    return np.zeros(domain)

@pytest.fixture(name="phyex", scope="module")
def phyex_fixture():
    """Create mock PHYEX configuration"""
    try:
        # Try to use real Phyex if available
        from ice3.phyex_common.phyex import Phyex
        return Phyex(program="AROME")
    except Exception:
        # Fall back to mock if real one fails
        return MockPhyex()

@pytest.fixture(name="externals", scope="module")
def externals_fixture(phyex):
    return phyex.to_externals()

@pytest.fixture(name="gt4py_config", scope="module")
def gt4py_config_fixture():
    """Create mock GT4Py configuration"""
    return MockGT4PyConfig()

@pytest.fixture(name="fortran_dims", scope="module")
def fortran_dims_fixture(grid):
    return {
        "nkt": grid.shape[2],
        "nijt": grid.shape[0] * grid.shape[1],
        "nktb": 1,
        "nkte": grid.shape[2],
        "nijb": 1,
        "nije": grid.shape[0] * grid.shape[1],
    }
    
@pytest.fixture(name="packed_dims", scope="module")
def packed_dims_fixture(grid):
    return {
        "kproma": grid.shape[0] * grid.shape[1] * grid.shape[2],
        "ksize": grid.shape[0] * grid.shape[1] * grid.shape[2]
    }

# Test utilities
def create_random_field(shape: Tuple[int, ...], dtype=np.float64, seed: int = 42) -> np.ndarray:
    """Create a random field for testing"""
    np.random.seed(seed)
    return np.random.rand(*shape).astype(dtype)

def create_test_state(domain: Tuple[int, int, int], dtype=np.float64) -> Dict[str, np.ndarray]:
    """Create a test state with common fields"""
    return {
        "temperature": create_random_field(domain, dtype) + 273.15,  # Realistic temperature
        "pressure": create_random_field(domain, dtype) * 50000 + 50000,  # 50-100 kPa
        "rv": create_random_field(domain, dtype) * 0.02,  # Water vapor mixing ratio
        "rc": create_random_field(domain, dtype) * 0.001,  # Cloud water mixing ratio
        "ri": create_random_field(domain, dtype) * 0.001,  # Ice mixing ratio
    }
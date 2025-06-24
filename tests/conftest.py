import pytest


# fixtures
@pytest.fixture(name="computational_grid", scope="module")
def computational_grid_fixture():
    return (50, 50, 15)

@pytest.fixture(name="origin", scope="module")
def origin_fixture():
    return (0, 0, 0)

@pytest.fixture(name="externals", scope="module")
def externals_fixture(phyex):
    return phyex.to_externals()

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
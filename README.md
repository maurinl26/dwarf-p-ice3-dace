# ICE3 microphysics on DaCe

dwarf-ice3-dace is a port of PHYEX microphysics with DaCe Frontend. Original source code can be retrieved from the [PHYEX](https://github.com/UMR-CNRM/PHYEX) repository or updated as a submodule in this project via an install script.

Fortran reference is cy48t3 of AROME packages.

## Installation and build

### LUMI

Data must be set up on the scratch filesystem.

### Running on GPU

- Module load + environment variables
```bash
    source ./config/lumi/lumi_env
```

See the [LUMI configuration](config/lumi/lumi_env) for environment setup.

- Interactive session
```bash
    srun --nodes=1  \
    --ntasks-per-node=1 \
    --cpus-per-task=56 \
    --gpus-per-node=1 \
    --account=project_465000527 \
    --partition=dev-g \
    --time=03:00:00  \
    --mem=0 \
    --pty bash
```

- Launch
```bash
    uv run standalone-model ice-adjust-split \
    gt:gpu \
    $SCRATCH_PATH/data/ice_adjust/reference.nc \
    $SCRATCH_PATH/data/ice_adjust/run.nc \
    track_ice_adjust.json
```

#### Warning

It works well with cupy 14.0 and the latest versions of gt4py.cartesian (see config [pyproject.toml](pyproject.toml)) 

### Atos ECMWF

### Leonardo

## Data generation for reproducibility

The data generation script transforms _.dat_ files from PHYEX to NetCDF format with named fields. The _.dat_ files are retrieved from PHYEX reproducibility test sets (testprogs_data).

Load PHYEX testprogs dataset:

- ice_adjust
```bash
  cd ./data/
  wget --no-check-certificate https://github.com/UMR-CNRM/PHYEX/files/12783926/ice_adjust.tar.gz \
   -O ice_adjust.tar.gz
  tar xf ice_adjust.tar.gz
  rm -f ice_adjust.tar.gz
  cd ..
```


Decode files to NetCDF:

```bash
   uv run testprogs-data extract-data-ice-adjust \
   data/ice_adjust/ \
   reference.nc \
   ./src/testprogs_data/ice_adjust.yaml 
```

This uses the configuration file [ice_adjust.yaml](src/testprogs_data/ice_adjust.yaml).

## Microphysical Adjustments (Ice Adjust)

There are components available for microphysical adjustments, under the [src/ice3/components](src/ice3/components) directory:

- IceAdjust ([ice_adjust.py](src/ice3/functions/ice_adjust.py)) : performs condensation and adjustments following supersaturation, and is the mirror of PHYEX's ice_adjust.F90,
- IceAdjustSplit ([ice_adjust_split.py](src/ice3/components/ice_adjust_split.py)) : split version of the ice adjustment component.
- To launch ice_adjust (with cli):

```bash
  uv run standalone-model ice-adjust-split \
  ./data/ice_adjust/reference.nc
```

## (WIP) Integration with PHYEX
  
- Option 1:
  - Integration via Serialbox in IAL_de330 under ecbuild
  - Link editing to Serialbox to be done

- Option 2:
  - Integration of DaCe functions (C++)

## (WIP) Integration with PMAP-L

- Option 1:
  - Python integration (may require rewriting of components)


## Unit tests

Unit tests for reproducibility are using pytest. 

They test the components for every backend.

Fortran and GT4Py stencils can be tested side-by-side with test components ([stencils_fortran](src/ice3/stencils_fortran) directory).

Fortran routines are issued from CY49T0 version of the code and reworked to eliminate
derivative types from routines. Then both stencils are run with random numpy arrays
as input.

- [conftest.py](tests/conftest.py) : 
  - All test utilities: grid, domain, test origin and gt4py config
  - compile_fortran_stencil(file, module, subroutine)


## Project Structure

- [src](src/) 
  - [drivers](src/drivers/) : Command Line Interface
  - [ice3](src/ice3/) :
    - [stencils](src/ice3/stencils/) : GT4Py and DaCe stencils
    - [functions](src/ice3/functions/) : GT4Py functions
    - [initialisation](src/ice3/initialisation/) : Field initialization (arrays)
    - [phyex_common](src/ice3/phyex_common/) : Python equivalents of MODD modules (recoded as dataclasses)
    - [stencils_fortran](src/ice3/stencils_fortran/) : Fortran equivalents of GT4Py stencils (modules + 1 subroutine = 1 GT4Py stencil)
    - [utils](src/ice3/utils/) : Utilities for configuration and field allocation
  - [testprogs_data](src/testprogs_data/) :
    - [main](src/testprogs_data/main.py) : Command Line Interface for decoding PHYEX testprogs
    - .yaml files : Configuration for file decoding


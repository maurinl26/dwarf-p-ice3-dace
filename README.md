# ICE3 microphysics on gt4py.

dwarf-ice3-gt4py is a porting of PHYEX microphysics on gt4py dsl. Original source code can be retrieved on [PHYEX](https://github.com/UMR-CNRM/PHYEX)
repository or updated as a submodule in this project -via _install.sh_ script.

## Installation and build

### LUMI

Data must be setup on the scratch.

Run debug :

Run GPU :

- Module load + environment variables
```bash
    source ./config/lumi/lumi_env
```

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

It works well with cupy 14.0 and the last versions of gt4py.cartesian (see config _pyproject.toml_) 

### Atos ECMWF

### Leonardo

## Data generation for reproductibility

Data generation script is made to transform _.dat_ files from PHYEX to netcdf with named fields. _.dat_ files are retrieved from PHYEX reproductibility sets (testprogs_data).

Load PHYEX testprogs dataset :

- ice_adjust
```bash
  cd ./data/
  wget --no-check-certificate https://github.com/UMR-CNRM/PHYEX/files/12783926/ice_adjust.tar.gz \
   -O ice_adjust.tar.gz
  tar xf ice_adjust.tar.gz
  rm -f ice_adjust.tar.gz
  cd ..
```


Decode files to netcdf :

```bash
   uv run testprogs-data extract-data-ice-adjust \
   data/ice_adjust/ \
   reference.nc \
   ./src/testprogs_data/ice_adjust.yaml 
```

## Microphysical Adjustments (Ice Adjust)

There are three components available for microphysical adjustments, under _/src/ice3_gt4py/components_ directory:

- IceAdjust (ice_adjust.py) : performs condensation and adjustements following supersaturation, and is the mirror of PHYEX's ice_adjust.F90,
- AroAdjust (aro_adjust.py) : combines both stencil collections to reproduce aro_adjust.F90.
- To launch ice_adjust (with cli):

```bash
  uv run standalone-model ice-adjust-split \
  gt:cpu_kfirst \
  ./data/ice_adjust/reference.nc \
  ./data/ice_adjust/run.nc \
  track_ice_adjust.json --no-rebuild 
```

## (WIP) Integration with PHYEX
  
- Option 1:
  - intégration par Serialbox dans IAL_de330 sous ecbuild
  - édition de lien vers Serialbox à faire

- Option 2:
  - intégration des fonctions DaCe (C++)

## (WIP) Integration with PMAP-L

- Option 1:
  - Intégration Python (nécessite peut-être de la réécriture de composants).


## Unit tests

Unit tests for reproductibility are using pytest. 

They test the components for every backend.

Fortran and GT4Py stencils can be tested side-by-side with test components (_stencil_fortran_ directory).

Fortran routines are issued from CY49T0 version of the code and reworked to eliminate
derivate types from routines. Then both stencils are ran with random numpy arrays
as an input.

- conftest.py : 
  - tous les utilitaires pour les tests : grille, domain, origine de test et config gt4py
  - compile_fortran_stencil(fichier, module, subroutine)


## Structure du projet 

- src 
  - drivers : Command Line Interface
  - ice3_gt4py :
    - stencils : stencils gt4py et dace
    - functions : fonctions gt4py
    - initialisation : initialisation des champs (arrays)
    - phyex_common : équivalents des modd en python : les modd ont été recodés en dataclasses
    - stencils_fortran : équivalent fortran des stencisl gt4py (modules + 1 subroutine = 1 stencil gt4py)
    - utils : utilitaires pour la config et l'allocation des champs
  - testprogs_data :
    - main : Command Line Interface pour le décodage des testprogs phyex
    - .yaml : config de décodage des fichiers


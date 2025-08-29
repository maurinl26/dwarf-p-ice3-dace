
cmake_minimum_required( VERSION 3.12 FATAL_ERROR)
find_package( ecbuild 3.4 REQUIRED HINTS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../ecbuild )

project( dwarf-p-ice3-dace LANGUAGES Fortran C CXX)

ecbuild_enable_fortran( REQUIRED NO_MODULE_DIRECTORY )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

### Sources
add_subdirectory(.dacecache)

ecbuild_install_project( NAME dwarf-p-ice3-dace )

ecbuild_print_summary()
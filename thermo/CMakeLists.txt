
##### Link ice_adjust
add_library(thermodynamic_fields SHARED IMPORTED)
set_target_properties(thermodynamic_fields
    PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/.dacecache/thermodynamic_fields/build/libthermodynamic_fields.so)

if(EXISTS ${CMAKE_BINARY_DIR}/lib)
    add_custom_target(link_target ALL
                  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/.dacecache/thermodynamic_fields/build/libthermodynamic_fields.so  ${CMAKE_BINARY_DIR}/lib/libthermodynamic_fields.so)
endif()


##### Add DaCe library
ecbuild_add_library(TARGET thermo-dace-module
    DEFINITIONS ${IFS_DEFINITIONS}
    SOURCES 
        ${CMAKE_CURRENT_SOURCE_DIR}/modi_thermo.f90
        ${CMAKE_CURRENT_SOURCE_DIR}/fortran_c_array_interface.f90
    PUBLIC_LIBS
        thermodynamic_fields
    PRIVATE_INCLUDES
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/.dacecache/thermodynamic_fields/include>
)

##### Add executable for tests
ecbuild_add_executable(
    TARGET  test_thermo
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_thermo.f90
    LIBS    thermo-dace-module            
)

###############################

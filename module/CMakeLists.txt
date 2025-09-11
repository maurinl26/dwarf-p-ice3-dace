
##### Link ice_adjust
add_library(ice3_components_ice_adjust_split_ice_adjust SHARED IMPORTED)
set_target_properties(ice3_components_ice_adjust_split_ice_adjust
    PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/.dacecache/ice3_components_ice_adjust_split_ice_adjust/build/libice3_components_ice_adjust_split_ice_adjust.so)

if(EXISTS ${CMAKE_BINARY_DIR}/lib)
    add_custom_target(link_target ALL
                  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/.dacecache/ice3_components_ice_adjust_split_ice_adjust/build/libice3_components_ice_adjust_split_ice_adjust.so  ${CMAKE_BINARY_DIR}/lib/libice3_components_ice_adjust_split_ice_adjust.so)
endif()


##### Add DaCe library
ecbuild_add_library(TARGET ice-adjust-dace-module
    DEFINITIONS ${IFS_DEFINITIONS}
    SOURCES 
        ${CMAKE_CURRENT_SOURCE_DIR}/modi_ice_adjust_dace.f90
        ${CMAKE_CURRENT_SOURCE_DIR}/fortran_c_array_interface.f90
    PUBLIC_LIBS
        ice3_components_ice_adjust_split_ice_adjust
    PRIVATE_INCLUDES
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/.dacecache/ice3_components_ice_adjust_split_ice_adjust/include>
)

##### Add executable for tests
ecbuild_add_executable(
    TARGET  test_ice_adjust
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_ice_adjust.f90
    LIBS    ice-adjust-dace-module             
)


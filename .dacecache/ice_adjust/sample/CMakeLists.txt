
add_library(ice_adjust SHARED IMPORTED)
add_library(dacestub_ice_adjust SHARED IMPORTED)

set_target_properties(ice_adjust
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libice_adjust.so)
target_include_directories(ice_adjust
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set_target_properties(dacestub_ice_adjust
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libdacestub_ice_adjust.so)
target_include_directories(dacestub_ice_adjust
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_library(ice_adjust_module STATIC)

target_sources(ice_adjust_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/modi_ice_adjust.f90
)

target_link_libraries(ice_adjust_module ice_adjust)
target_link_libraries(ice_adjust_module dacestub_ice_adjust)

add_executable(test_ice_adjust test_ice_adjust.f90)

target_link_libraries(test_ice_adjust
    PUBLIC
    ice_adjust_module
)

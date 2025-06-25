
add_library(condensation SHARED IMPORTED)
add_library(dacestub_condensation SHARED IMPORTED)

set_target_properties(condensation
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libcondensation.so)
target_include_directories(condensation
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set_target_properties(dacestub_condensation
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libdacestub_condensation.so)
target_include_directories(dacestub_condensation
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_library(condensation_module STATIC)

target_sources(condensation_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/modi_ice_adjust.f90
)

target_link_libraries(condensation_module condensation)
target_link_libraries(condensation_module dacestub_condensation)

add_executable(test_condensation test_condensation.f90)

target_link_libraries(test_condensation
    PUBLIC
    condensation_module
)

add_library(thermodynamic_fields SHARED IMPORTED)
add_library(dacestub_thermodynamic_fields SHARED IMPORTED)

set_target_properties(thermodynamic_fields
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libthermodynamic_fields.so)
target_include_directories(thermodynamic_fields
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set_target_properties(dacestub_thermodynamic_fields
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libdacestub_thermodynamic_fields.so)
target_include_directories(dacestub_thermodynamic_fields
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_library(thermo_module STATIC)

target_sources(thermo_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/modi_thermo.f90
)

target_link_libraries(thermo_module thermodynamic_fields)
target_link_libraries(thermo_module dacestub_thermodynamic_fields)

add_executable(test_thermo test_thermo.f90)

target_link_libraries(test_thermo
    PUBLIC
    thermo_module
)


add_library(cloud_fraction_2 SHARED IMPORTED)
add_library(dacestub_cloud_fraction_2 SHARED IMPORTED)

set_target_properties(cloud_fraction_2
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libcloud_fraction_2.so)
target_include_directories(cloud_fraction_2
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set_target_properties(dacestub_cloud_fraction_2
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libdacestub_cloud_fraction_2.so)
target_include_directories(dacestub_cloud_fraction_2
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_library(cloud_fraction_2_module STATIC)

target_sources(cloud_fraction_2_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/modi_cloud_fraction_2.f90
)

target_link_libraries(cloud_fraction_2_module cloud_fraction_2)
target_link_libraries(cloud_fraction_2_module dacestub_cloud_fraction_2)

add_executable(test_cloud_fraction_2 test_cloud_fraction_2.f90)

target_link_libraries(test_cloud_fraction_2
    PUBLIC
    cloud_fraction_2_module
)

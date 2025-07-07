
add_library(cloud_fraction_1 SHARED IMPORTED)
add_library(dacestub_cloud_fraction_1 SHARED IMPORTED)

set_target_properties(cloud_fraction_1
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libcloud_fraction_1.so)
target_include_directories(cloud_fraction_1
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set_target_properties(dacestub_cloud_fraction_1
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libdacestub_cloud_fraction_1.so)
target_include_directories(dacestub_cloud_fraction_1
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_library(cloud_fraction_1_module STATIC)

target_sources(cloud_fraction_1_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/modi_cloud_fraction_1.f90
)

target_link_libraries(cloud_fraction_1_module cloud_fraction_1)
target_link_libraries(cloud_fraction_1_module dacestub_cloud_fraction_1)

add_executable(test_cloud_fraction_1 test_cloud_fraction_1.f90)

target_link_libraries(test_cloud_fraction_1
    PUBLIC
    cloud_fraction_1_module
)

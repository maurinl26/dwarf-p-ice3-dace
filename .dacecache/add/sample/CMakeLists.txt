
add_library(add SHARED IMPORTED)
add_library(dacestub_add SHARED IMPORTED)

set_target_properties(add
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libadd.so)
target_include_directories(add
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set_target_properties(dacestub_add
    PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/libdacestub_add.so)
target_include_directories(dacestub_add
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


add_library(add_module STATIC)

target_sources(add_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/modi_add.f90
)

target_link_libraries(add_module add)
target_link_libraries(add_module dacestub_add)

add_executable(test_add test_add.f90)

target_link_libraries(test_add
    PUBLIC
    add_module
)

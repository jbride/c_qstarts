cmake_minimum_required( VERSION 3.24 )
project( CPP_QSTARTS VERSION 1.1 )

find_package(restinio CONFIG REQUIRED)

set(SOURCES restinio_test.cpp)
add_executable(main ${SOURCES})
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_link_libraries(main PRIVATE restinio::restinio)

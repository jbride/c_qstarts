cmake_minimum_required( VERSION 3.24 )
project( CPP_QSTARTS VERSION 1.1 )

find_package(restinio CONFIG REQUIRED)
find_package(Boost REQUIRED)
include_directories		(${Boost_INCLUDE_DIR})

# I'm aware that explicit listing of source and header files is recommended for collaborative projects involving many developers
# https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak/1060061#1060061
# file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "*.h" "*.cpp")

#set(SRC_FILES restinio_test.cpp)
#set(SRC_FILES CommonHeaders.h ThreadManager.h ThreadManager.cpp threads.cpp)
#set(SRC_FILES time.cpp)
set(SRC_FILES hello_boost.cpp)

message( SRC_FILES = ${SRC_FILES} )

add_executable(main ${SRC_FILES} )
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_link_libraries(main PRIVATE restinio::restinio)

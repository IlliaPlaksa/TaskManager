cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

# _________Protobuf_________
find_package(Protobuf REQUIRED)
find_program(PROTOBUF_EXECUTABLE protoc)

set(PROTOBUF_DIR ${CMAKE_SOURCE_DIR}/protobuf)
set(PROTOBUF_CPP_OUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/protobuf)

file(MAKE_DIRECTORY ${PROTOBUF_CPP_OUT_DIR})

function(compile_proto_file filename)
    get_filename_component(dirname ${filename} DIRECTORY)
    get_filename_component(basename ${filename} NAME_WE)

    add_custom_command(
            OUTPUT ${PROTOBUF_CPP_OUT_DIR}/${basename}.pb.cc ${PROTOBUF_CPP_OUT_DIR}/${basename}.pb.h
            DEPENDS ${PROTOBUF_DIR}/${basename}.proto
            COMMAND ${PROTOBUF_EXECUTABLE} ${PROTOBUF_DIR}/${basename}.proto
            --cpp_out=${PROTOBUF_CPP_OUT_DIR}
            --proto_path=${PROTOBUF_DIR}
            VERBATIM
    )
endfunction(compile_proto_file)

file(GLOB_RECURSE Proto_SRCS CONFIGURE_DEPENDS
        "protobuf/*.proto"
        )

set_source_files_properties(${Proto_SRCS} PROPERTIES COMPILE_FLAGS -Wall -Wextra -Wpedantic -Werror -Wno-unused-variable)

foreach (proto_file ${Proto_SRCS})
    compile_proto_file(${proto_file})
    get_filename_component(basename ${proto_file} NAME_WE)
    set(PROTOBUF_GENERATED_SRCS ${PROTOBUF_GENERATED_SRCS}
            ${PROTOBUF_CPP_OUT_DIR}/${basename}.pb.h
            ${PROTOBUF_CPP_OUT_DIR}/${basename}.pb.cc
            )
endforeach (proto_file)

# _________MAIN_________

file(GLOB_RECURSE TaskManager_SRC CONFIGURE_DEPENDS
        "src/*.h"
        "src/*.cpp")

add_library(TaskManager
        STATIC ${TaskManager_SRC} ${PROTOBUF_GENERATED_SRCS}
        )
add_executable(main
        ${TaskManager_SRC}
        )

target_link_libraries(main TaskManager protobuf::libprotobuf)

target_include_directories(TaskManager
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PROTOBUF_CPP_OUT_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        )

#_________GTEST_________
include(GoogleTest)

find_package(GTest REQUIRED)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# _________GLOBAL TEST_________

file(GLOB_RECURSE Tests_SRC
        "src/cli/*.cpp"
        "src/cli/*.h"

        "src/common/*.cpp"
        "src/common/*.h"

        "src/controller/*.cpp"
        "src/controller/*.h"

        "src/model/*.cpp"
        "src/model/*.h"

        "src/persistence/*.cpp"
        "src/persistence/*.h"

        "src/util/*.cpp"
        "src/util/*.h"

        "tests/*.cpp"
        "tests/*.h")

add_library(Tests
        STATIC ${Tests_SRC} ${PROTOBUF_GENERATED_SRCS}
        )

target_include_directories(Tests
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests
        ${PROTOBUF_CPP_OUT_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        )

add_executable(TaskManger_TEST
        ${Tests_SRC}
        )

target_link_libraries(TaskManger_TEST Tests protobuf::libprotobuf)
target_link_libraries(TaskManger_TEST GTest::GTest GTest::Main)
target_link_libraries(TaskManger_TEST GTest::gtest GTest::gmock GTest::gmock_main)

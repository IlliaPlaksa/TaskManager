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

foreach(proto_file ${Proto_SRCS})
    compile_proto_file(${proto_file})
    get_filename_component(basename ${proto_file} NAME_WE)
    set(PROTOBUF_GENERATED_SRCS ${PROTOBUF_GENERATED_SRCS}
            ${PROTOBUF_CPP_OUT_DIR}/${basename}.pb.h
            ${PROTOBUF_CPP_OUT_DIR}/${basename}.pb.cc
            )
endforeach(proto_file)

# _________SRCS_________

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

# _________TEST_SRCS_________
file(GLOB_RECURSE MODEL_SRC CONFIGURE_DEPENDS
        "src/model/*.h"
        "src/model/*.cpp")

file(GLOB_RECURSE CLI_SRC CONFIGURE_DEPENDS
        "src/cli/*.h"
        "src/cli/*.cpp")

file(GLOB_RECURSE CONTROLLER_SRC CONFIGURE_DEPENDS
        "src/controller/*.h"
        "src/controller/*.cpp")

file(GLOB MODEL_TEST_SRC tests/model/*)

file(GLOB_RECURSE CONTROLLER_TEST_SRC CONFIGURE_DEPENDS
        "tests/controller/*.cpp"
        "tests/controller/*.h")

file(GLOB CLI_TEST_SRC tests/cli/*)

add_executable(Model_TEST
        ${MODEL_SRC}
        ${MODEL_TEST_SRC})
target_link_libraries(Model_TEST GTest::GTest GTest::Main)
target_link_libraries(Model_TEST GTest::gtest GTest::gmock GTest::gmock_main)


add_executable(Controller_TEST
        ${CONTROLLER_SRC}
        ${MODEL_SRC}
        ${CONTROLLER_TEST_SRC})
target_link_libraries(Controller_TEST GTest::GTest GTest::Main)
target_link_libraries(Controller_TEST GTest::gtest GTest::gmock GTest::gmock_main)

add_executable(Cli_TEST
        ${CLI_SRC}
        ${CLI_TEST_SRC})
target_link_libraries(Cli_TEST GTest::GTest GTest::Main)
target_link_libraries(Cli_TEST GTest::gtest GTest::gmock GTest::gmock_main)


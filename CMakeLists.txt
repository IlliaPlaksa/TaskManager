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

# _________UTILS_________
file(GLOB_RECURSE Utils_SRC CONFIGURE_DEPENDS
        "utils/*.h"
        "utils/*.cpp")

add_library(Utils
        STATIC ${Utils_SRC} ${PROTOBUF_GENERATED_SRCS}
        )
target_include_directories(Utils
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PROTOBUF_CPP_OUT_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        )

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

target_link_libraries(main TaskManager Utils protobuf::libprotobuf)

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

file(GLOB_RECURSE PERSISTENCE_SRC CONFIGURE_DEPENDS
        "src/persistence/*.h"
        "src/persistence/*.cpp")

file(GLOB_RECURSE MODEL_TEST_SRC CONFIGURE_DEPENDS
        "tests/model/*.cpp"
        "tests/model/*.h")

file(GLOB_RECURSE CONTROLLER_TEST_SRC CONFIGURE_DEPENDS
        "tests/controller/*.cpp"
        "tests/controller/*.h")

file(GLOB_RECURSE PERSISTENCE_TEST_SRC
        "tests/persistence/*.cpp"
        "tests/persistence/*.h")

# _________TEST'S_EXEC_________

# Model TEST
add_library(Model
        STATIC ${MODEL_SRC} ${PROTOBUF_GENERATED_SRCS}
        )

add_executable(Model_TEST
        ${MODEL_SRC}
        ${MODEL_TEST_SRC})

target_include_directories(Model_TEST
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PROTOBUF_CPP_OUT_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        )

target_link_libraries(Model_TEST Model Utils protobuf::libprotobuf)
target_link_libraries(Model_TEST GTest::GTest GTest::Main)
target_link_libraries(Model_TEST GTest::gtest GTest::gmock GTest::gmock_main)

# Controller TEST
add_library(Controller
        STATIC ${CONTROLLER_SRC} ${PROTOBUF_GENERATED_SRCS}
        )

add_executable(Controller_TEST
        ${CONTROLLER_SRC}
        ${MODEL_SRC}
        ${CONTROLLER_TEST_SRC})


target_link_libraries(Controller_TEST Controller Utils protobuf::libprotobuf)
target_link_libraries(Controller_TEST GTest::GTest GTest::Main)
target_link_libraries(Controller_TEST GTest::gtest GTest::gmock GTest::gmock_main)

# CLI TEST
add_library(Cli
        STATIC ${CLI_SRC} ${PROTOBUF_GENERATED_SRCS}
        )
add_executable(Cli_TEST
        ${CLI_SRC}
        ${CLI_TEST_SRC})

target_link_libraries(Cli_TEST Cli Utils protobuf::libprotobuf)
target_link_libraries(Cli_TEST GTest::GTest GTest::Main)
target_link_libraries(Cli_TEST GTest::gtest GTest::gmock GTest::gmock_main)

# Persistence TEST
add_library(Persistence
        STATIC ${Persistence_SRC} ${PROTOBUF_GENERATED_SRCS}
        )

add_executable(Persistence_TEST
        ${PERSISTENCE_SRC}
        ${PERSISTENCE_TEST_SRC}
        )

target_link_libraries(Persistence_TEST Persistence Utils protobuf::libprotobuf)
target_link_libraries(Persistence_TEST GTest::GTest GTest::Main)
target_link_libraries(Persistence_TEST GTest::gtest GTest::gmock GTest::gmock_main)

target_include_directories(Persistence
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${PROTOBUF_CPP_OUT_DIR}
        ${PROTOBUF_INCLUDE_DIR}
        )



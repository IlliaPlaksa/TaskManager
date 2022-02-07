cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/)

# _________Boost_________
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS
        log
        log_setup
        program_options
        REQUIRED)

find_package(Boost COMPONENTS log log_setup REQUIRED)

file(GLOB_RECURSE Logging_SRC CONFIGURE_DEPENDS
        "logging/*.h"
        "logging/*.cpp"
        )

configure_file(help.txt help.txt COPYONLY) # Adding help.txt to build output

# _________Protobuf_________
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")
find_program(_PROTOBUF_PROTOC protoc PATHS ENV PATH)
#

find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")
find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
#

include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE PROTO_SOURCES CONFIGURE_DEPENDS ${TaskManager_SOURCE_DIR}/protobuf/*.proto)
message("PROTO_SOURCES ${PROTO_SOURCES}")

set(PROTO_DIR ${TaskManager_SOURCE_DIR}/protobuf)
set(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR})

macro(compile_proto_file filename)
    get_filename_component(dirname ${filename} PATH)
    get_filename_component(basename ${filename} NAME_WE)

    message("macros ${filename}")
    add_custom_command(
            OUTPUT ${GENERATED_DIR}/${basename}.pb.cc ${GENERATED_DIR}/${basename}.grpc.pb.cc
            DEPENDS ${_PROTOBUF_PROTOC} ${PROTO_DIR}/${basename}.proto
            COMMAND ${_PROTOBUF_PROTOC} ${PROTO_DIR}/${basename}.proto
            --proto_path=${GENERATED_DIR}
            --cpp_out=${GENERATED_DIR}
            --grpc_out=generate_mock_code=true:${GENERATED_DIR}
            --plugin=protoc-gen-grpc=${_GRPC_CPP_PLUGIN_EXECUTABLE}
            -I ${PROTO_DIR}
            VERBATIM
    )
endmacro(compile_proto_file)

foreach (proto_file ${PROTO_SOURCES})
    message("compiling ${proto_file}")
    compile_proto_file(${proto_file})
    get_filename_component(basename ${proto_file} NAME_WE)
    set(PROTOBUF_GENERATED_SRCS ${PROTOBUF_GENERATED_SRCS} ${GENERATED_DIR}/${basename}.pb.cc ${GENERATED_DIR}/${basename}.grpc.pb.cc)
endforeach (proto_file)

include_directories(${GENERATED_DIR})

SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)

# _________gRPC-SERVER_________

file(GLOB_RECURSE Server_SRC CONFIGURE_DEPENDS
        "src/server.cpp"

        "src/server/*.h"
        "src/server/*.cpp"

        "src/common/*.h"
        "src/common/*.cpp"

        "src/model/*.h"
        "src/model/*.cpp"

        "src/util/*.h"
        "src/util/*.cpp"
        )

add_executable(server
        ${Server_SRC}
        ${PROTO_SRCS}
        ${PROTO_HDRS}
        ${PROTOBUF_GENERATED_SRCS}
        ${Logging_SRC}
        )

target_link_libraries(server
        protobuf::libprotobuf
        gRPC::grpc++ gRPC::grpc++_reflection
        Boost::log Boost::log_setup Boost::program_options)

target_include_directories(server
        PUBLIC ${Boost_INCLUDE_DIRS}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logging
        )


# _________gRPC-CLIENT_________

file(GLOB_RECURSE Client_SRC CONFIGURE_DEPENDS
        "src/client.cpp"

        "src/common/*.h"
        "src/common/*.cpp"

        "src/cli/*.h"
        "src/cli/*.cpp"

        "src/persistence/*.h"
        "src/persistence/*.cpp"

        "src/controller/*.h"
        "src/controller/*.cpp"

        "src/util/*.h"
        "src/util/*.cpp"
        )

add_executable(client
        ${Client_SRC}
        ${PROTO_SRCS}
        ${PROTO_HDRS}
        ${PROTOBUF_GENERATED_SRCS}
        ${Logging_SRC}
        )

target_link_libraries(client
        protobuf::libprotobuf
        gRPC::grpc++ gRPC::grpc++_reflection
        Boost::log Boost::log_setup Boost::program_options
        )
target_include_directories(client
        PUBLIC ${Boost_INCLUDE_DIRS}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logging
        )

#_________GTEST_________
include(GoogleTest)

find_package(GTest REQUIRED)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# _________GLOBAL TEST_________

file(GLOB_RECURSE Tests_SRC
        "tests/*.cpp"
        "tests/*.h"

        "src/cli/*.cpp"
        "src/cli/*.h"

        "src/server/*.cpp"
        "src/server/*.h"

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
        )

add_executable(TaskManger_TEST
        ${Tests_SRC}
        ${PROTO_SRCS}
        ${PROTO_HDRS}
        ${PROTOBUF_GENERATED_SRCS}
        ${Logging_SRC}
        )

target_include_directories(TaskManger_TEST
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logging
        PUBLIC ${Boost_INCLUDE_DIRS}
        )


target_link_libraries(TaskManger_TEST protobuf::libprotobuf gRPC::grpc++ gRPC::grpc++_reflection)
target_link_libraries(TaskManger_TEST Boost::log Boost::log_setup)
target_link_libraries(TaskManger_TEST GTest::GTest)
target_link_libraries(TaskManger_TEST GTest::gtest GTest::gmock)

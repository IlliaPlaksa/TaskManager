cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)

find_package(GTest REQUIRED)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE MODEL_SRC CONFIGURE_DEPENDS
        "src/model/*.h"
        "src/model/*.cpp"
        )
file(GLOB_RECURSE CLI_SRC CONFIGURE_DEPENDS
        "src/cli/*.h"
        "src/cli/*.cpp"
        )

file(GLOB_RECURSE CONTROLLER_SRC CONFIGURE_DEPENDS
        "src/controller/*.h"
        "src/controller/*.cpp"
        )

file(GLOB_RECURSE TaskManager_SRC CONFIGURE_DEPENDS
        "src/*.h"
        "src/*.cpp"
        )

file(GLOB MODEL_TEST_SRC tests/model/*)
file(GLOB CONTROLLER_TEST_SRC tests/controller/*)
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

add_executable(TaskManager_Controller
        ${TaskManager_SRC}
        )


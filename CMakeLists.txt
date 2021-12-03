cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)

find_package(GTest REQUIRED)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB MODEL_INCLUDE src/model/include/*)
file(GLOB CLI_INCLUDE src/ui/include/*)
file(GLOB CONTROLLER_INCLUDE src/controller/include/*)

file(GLOB MODEL_IMP src/model/imp/*)
file(GLOB CLI_IMP src/cli/imp/* src/cli/imp/steps/*)
file(GLOB CONTROLLER_IMP src/controller/imp/*)

file(GLOB MODEL_TEST tests/model/*)
add_executable(Model_TEST
        ${Model_INCLUDE}
        ${Model_IMP}
        ${MODEL_TEST})

add_executable(TaskManager_Controller
        src/controller/main.cpp
        ${CONTROLLER_INCLUDE}
        ${CONTROLLER_IMP}

        ${MODEL_INCLUDE}
        ${MODEL_IMP}

        ${CLI_INCLUDE}
        ${CLI_IMP}
        )


target_link_libraries(Model_TEST GTest::GTest GTest::Main)
target_link_libraries(Model_TEST GTest::gtest GTest::gmock GTest::gmock_main)
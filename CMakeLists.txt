cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)

find_package(GTest REQUIRED)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TaskManager
        src/model/main.cpp
        src/model/Task.cpp src/model/Task.h
        src/model/TaskManager.cpp src/model/TaskManager.h
        src/model/TaskId.cpp src/model/TaskId.h
        src/model/IdGenerator.cpp src/model/IdGenerator.h)

add_executable(TaskManager_TEST
        src/model/Task.cpp src/model/Task.h
        src/model/TaskId.cpp src/model/TaskId.h
        src/model/IdGenerator.cpp src/model/IdGenerator.h
        src/model/TaskManager.cpp src/model/TaskManager.h

        tests/model/TaskTest.cpp tests/model/TaskIdTest.cpp
        tests/model/IdGeneratorTest.cpp tests/model/TaskManagerTest.cpp)

target_link_libraries(TaskManager_TEST GTest::GTest GTest::Main)
target_link_libraries(TaskManager_TEST GTest::gtest GTest::gmock GTest::gmock_main)
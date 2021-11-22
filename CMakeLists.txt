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
        src/model/IdGenerator.cpp src/model/IdGenerator.h
        src/model/FamilyTask.h src/model/FamilyTask.cpp)

add_executable(TaskManager_TEST
        src/model/Task.cpp src/model/Task.h
        src/model/TaskId.cpp src/model/TaskId.h
        src/model/IdGenerator.cpp src/model/IdGenerator.h
        src/model/TaskManager.cpp src/model/TaskManager.h
        src/model/FamilyTask.h src/model/FamilyTask.cpp

        tests/model/TaskTest.cpp tests/model/TaskIdTest.cpp
        tests/model/IdGeneratorTest.cpp tests/model/TaskManagerTest.cpp
        tests/model/FamilyTaskTest.cpp)

add_executable(TaskManager_CLI
        src/cli/main.cpp
        src/cli/StateMachine.h src/cli/StateMachine.cpp
        src/cli/Context.h src/cli/Context.cpp
        src/cli/State.h src/cli/State.cpp)

target_link_libraries(TaskManager_TEST GTest::GTest GTest::Main)
target_link_libraries(TaskManager_TEST GTest::gtest GTest::gmock GTest::gmock_main)
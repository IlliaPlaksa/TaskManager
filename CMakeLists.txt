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
        src/cli/headers/StepMachine.h src/cli/imp/StepMachine.cpp
        src/cli/headers/Context.h src/cli/imp/Context.cpp
        src/cli/headers/Step.h src/cli/imp/Step.cpp
        src/cli/headers/MachineSteps.h
        src/cli/imp/states/RootStep.cpp
        src/cli/imp/states/ExitStep.cpp
        src/cli/imp/states/HelpStep.cpp
        src/cli/imp/states/AddStep.cpp
        src/cli/imp/states/EditStep.cpp
        src/cli/imp/states/CompleteStep.cpp
        src/cli/imp/states/DeleteStep.cpp
        src/cli/imp/states/ShowStep.cpp
        src/cli/headers/StepFactory.h src/cli/imp/StepFactory.cpp
        src/cli/headers/ConsoleManipulator.h src/cli/imp/ConsoleManipulator.cpp)

target_link_libraries(TaskManager_TEST GTest::GTest GTest::Main)
target_link_libraries(TaskManager_TEST GTest::gtest GTest::gmock GTest::gmock_main)
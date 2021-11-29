cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)

find_package(GTest REQUIRED)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TaskManager
        src/model/main.cpp
        src/model/imp/Task.cpp src/model/headers/Task.h
        src/model/imp/TaskManager.cpp src/model/headers/TaskManager.h
        src/model/imp/TaskId.cpp src/model/headers/TaskId.h
        src/model/imp/IdGenerator.cpp src/model/headers/IdGenerator.h
        src/model/headers/FamilyTask.h src/model/imp/FamilyTask.cpp)

add_executable(TaskManager_TEST
        src/model/imp/Task.cpp src/model/headers/Task.h
        src/model/imp/TaskId.cpp src/model/headers/TaskId.h
        src/model/imp/IdGenerator.cpp src/model/headers/IdGenerator.h
        src/model/imp/TaskManager.cpp src/model/headers/TaskManager.h
        src/model/headers/FamilyTask.h src/model/imp/FamilyTask.cpp

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
        src/cli/headers/ConsoleManipulator.h src/cli/imp/ConsoleManipulator.cpp
        src/cli/headers/TaskStruct.h src/cli/imp/TaskStruct.cpp
        src/model/headers/Task.h src/model/imp/Task.cpp
        src/cli/headers/contexts/TaskContext.h src/cli/imp/contexts/TaskContext.cpp
        src/cli/headers/contexts/MainContext.h src/cli/imp/contexts/MainContext.cpp
        )

target_link_libraries(TaskManager_TEST GTest::GTest GTest::Main)
target_link_libraries(TaskManager_TEST GTest::gtest GTest::gmock GTest::gmock_main)
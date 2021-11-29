cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)

find_package(GTest REQUIRED)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TaskManager
        src/model/main.cpp
        src/model/imp/Task.cpp src/model/include/Task.h
        src/model/imp/TaskManager.cpp src/model/include/TaskManager.h
        src/model/imp/TaskId.cpp src/model/include/TaskId.h
        src/model/imp/IdGenerator.cpp src/model/include/IdGenerator.h
        src/model/include/FamilyTask.h src/model/imp/FamilyTask.cpp)

add_executable(TaskManager_TEST
        src/model/imp/Task.cpp src/model/include/Task.h
        src/model/imp/TaskId.cpp src/model/include/TaskId.h
        src/model/imp/IdGenerator.cpp src/model/include/IdGenerator.h
        src/model/imp/TaskManager.cpp src/model/include/TaskManager.h
        src/model/include/FamilyTask.h src/model/imp/FamilyTask.cpp

        tests/model/TaskTest.cpp tests/model/TaskIdTest.cpp
        tests/model/IdGeneratorTest.cpp tests/model/TaskManagerTest.cpp
        tests/model/FamilyTaskTest.cpp)

add_executable(TaskManager_CLI
        src/cli/main.cpp
        src/cli/include/StepMachine.h src/cli/imp/StepMachine.cpp
        src/cli/include/Context.h src/cli/imp/Context.cpp
        src/cli/include/Step.h src/cli/imp/Step.cpp
        src/cli/include/MachineSteps.h
        src/cli/imp/steps/RootStep.cpp
        src/cli/imp/steps/ExitStep.cpp
        src/cli/imp/steps/HelpStep.cpp
        src/cli/imp/steps/AddStep.cpp
        src/cli/imp/steps/EditStep.cpp
        src/cli/imp/steps/CompleteStep.cpp
        src/cli/imp/steps/DeleteStep.cpp
        src/cli/imp/steps/ShowStep.cpp
        src/cli/include/StepFactory.h src/cli/imp/StepFactory.cpp
        src/cli/include/ConsoleManipulator.h src/cli/imp/ConsoleManipulator.cpp
        src/cli/include/TaskStruct.h src/cli/imp/TaskStruct.cpp
        src/model/include/Task.h src/model/imp/Task.cpp
        )

target_link_libraries(TaskManager_TEST GTest::GTest GTest::Main)
target_link_libraries(TaskManager_TEST GTest::gtest GTest::gmock GTest::gmock_main)
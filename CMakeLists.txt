cmake_minimum_required(VERSION 3.20)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskManager
        src/model/main.cpp
        src/model/Task.cpp src/model/Task.h
        src/model/TaskManager.cpp src/model/TaskManager.h
        src/model/TaskId.cpp src/model/TaskId.h
        src/model/IdGenerator.cpp src/model/IdGenerator.h)

add_subdirectory(tests)
project(tests)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(all_tests
        model/TaskTest.cpp model/TaskManagerTest.cpp
        model/TaskIdTest.cpp model/IdGeneratorTest.cpp
        ../src/model/Task.h ../src/model/Task.cpp
        ../src/model/TaskManager.h ../src/model/TaskManager.cpp
        ../src/model/IdGenerator.h ../src/model/IdGenerator.cpp
        ../src/model/TaskId.h ../src/model/TaskId.cpp)
target_link_libraries(all_tests gtest_main)
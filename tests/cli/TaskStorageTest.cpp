//
// Created by Illia Plaksa on 17.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/TaskStorage.h"

#include "util/TaskId/TaskIdCreators.h"
#include "util/Task/TaskCreators.h"
#include "util/TaskDTO/TaskDTOCreators.h"
#include "util/TaskDTO/TaskDTOComparators.h"

class TaskStorageTest : ::testing::Test
{
};

TEST(TaskStorageTest, shouldLoadTasks)
{
    auto storage = TaskStorage{};

    auto task = *CreateTaskDTO(*CreateTaskId(0),
                               *CreateTask("title",
                                           time(nullptr),
                                           Task_Priority_kHigh));

    auto tasks = std::vector<TaskDTO>{task};
    storage.LoadTasks(tasks);

    EXPECT_EQ(storage.GetTasks(), tasks);
}

TEST(TaskStorageTest, shouldReturnAllTasks)
{
    auto storage = TaskStorage{};
    auto tasks = std::vector<TaskDTO>{};
    auto sub_tasks = std::vector<TaskDTO>{};

    auto parent_id = *CreateTaskId(0);

    auto task = *CreateTask("title",
                            time(nullptr),
                            Task_Priority_kHigh);

    for (int i = 1 ; i < 5 ; ++i)
    {
        sub_tasks.emplace_back(*CreateSubTaskDTO(*CreateTaskId(i),
                                                 task,
                                                 parent_id));
    }
    tasks.emplace_back(*CreateTaskDTO(parent_id, task));

    for (const auto& elem : sub_tasks)
        tasks.emplace_back(elem);

    storage.LoadTasks(tasks);

    auto result = storage.GetTasks();

    ASSERT_EQ(result.size(), tasks.size());
}

TEST(TaskStorageTest, shouldReturnRootTasks)
{
    auto storage = TaskStorage{};
    auto tasks = std::vector<TaskDTO>{};

    auto task = *CreateTaskDTO(*CreateTaskId(0),
                               *CreateTask("title",
                                           time(nullptr),
                                           Task_Priority_kHigh));
    for (int i = 0 ; i < 5 ; ++i)
    {
        tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(i),
                                          *CreateTask("title",
                                                      time(nullptr),
                                                      Task_Priority_kHigh)));
    }

    storage.LoadTasks(tasks);

    auto root_tasks = storage.GetRootTasks();

    for (auto elem : tasks)
    {
        auto iter = std::find(root_tasks.begin(), root_tasks.end(), elem);
        EXPECT_TRUE(iter != root_tasks.end());
    }
}

TEST(TaskStorageTest, shouldReturnSubTasksTasks)
{
    auto storage = TaskStorage{};
    auto tasks = std::vector<TaskDTO>{};
    auto sub_tasks = std::vector<TaskDTO>{};

    auto parent_id = *CreateTaskId(0);

    auto task = *CreateTask("title",
                            time(nullptr),
                            Task_Priority_kHigh);

    for (int i = 1 ; i < 5 ; ++i)
    {
        sub_tasks.emplace_back(*CreateSubTaskDTO(*CreateTaskId(i),
                                                 task,
                                                 parent_id));
    }
    tasks.emplace_back(*CreateTaskDTO(parent_id, task));

    for (const auto& elem : sub_tasks)
        tasks.emplace_back(elem);

    storage.LoadTasks(tasks);

    auto result = storage.GetSubTasks(parent_id);

    for (const auto& elem : sub_tasks)
    {
        auto iter = std::find(result.begin(), result.end(), elem);
        EXPECT_TRUE(iter != result.end());
    }
}

TEST(TaskStorageTest, shouldClearStorage)
{
    auto storage = TaskStorage{};
    auto tasks = std::vector<TaskDTO>{};

    auto parent_id = *CreateTaskId(0);

    auto task = *CreateTask("title",
                            time(nullptr),
                            Task_Priority_kHigh);

    for (int i = 1 ; i < 10 ; ++i)
    {
        tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(i), task));
    }

    storage.LoadTasks(tasks);

    auto result = storage.GetTasks();

    EXPECT_TRUE(!result.empty());

    storage.Clear();

    result = storage.GetTasks();

    EXPECT_TRUE(result.empty());

}



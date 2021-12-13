//
// Created by Illia Plaksa on 13.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/model/include/Task.h"
#include "../../src/controller/include/TaskStorage.h"

class TaskStorageTest : ::testing::Test
{
};

TEST(TaskStorageTest, shouldAddTasks)
{
    auto task_storage = TaskStorage{};

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::kLow;
    auto parent_id = TaskId::CreateDefault();

    auto task = Task::Create(task_title,
                             task_date,
                             task_priority);

    auto vect = std::vector<std::pair<TaskId, Task>>{};

    vect.emplace_back(std::make_pair(parent_id, task));

    task_storage.Add(parent_id, vect);

    EXPECT_EQ(task_storage.GetTasksByParentId(parent_id), vect);
}

TEST(TaskStorageTest, shouldReturnParentIds)
{
    auto task_storage = TaskStorage{};

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::kLow;
    auto parent_id = TaskId::CreateDefault();

    auto task = Task::Create(task_title,
                             task_date,
                             task_priority);

    size_t size = 5;
    auto expect_parents = std::vector<TaskId>{};
    for (int i = 0; i < size; ++i)
        expect_parents.emplace_back(TaskId::Create(i));

    for (const auto &id: expect_parents)
        task_storage.Add(id, {});

    auto actual_parents = task_storage.GetParentIds();
    ASSERT_EQ(actual_parents.size(), size);

    for (const auto &id: expect_parents)
        EXPECT_TRUE(std::find(actual_parents.begin(), actual_parents.end(), id)->value());
}

TEST(TaskStorageTest, shouldReturnTasksByParentId)
{
    auto task_storage = TaskStorage{};

    auto id = TaskId::Create(123);

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::kLow;

    auto vect = std::vector<std::pair<TaskId, Task>>{
        {TaskId::CreateDefault(), Task::Create(task_title,
                                               task_date,
                                               task_priority)}
    };
    task_storage.Add(id, vect);

    EXPECT_EQ(task_storage.GetTasksByParentId(id), vect);
}
//
// Created by Illia Plaksa on 14.11.2021.
//

#include "gtest/gtest.h"
#include "../../src/model/TaskManager.h"

class TaskManagerTest : public ::testing::Test {};

TEST(TaskManagerTest, shouldAddTask)
{
    auto manager = TaskManager{};

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Low;

    auto task = Task::Create(task_title,
                             task_date,
                             task_priority);
    auto task_id = manager.Add(task);

    ASSERT_EQ(manager.Show().size(), 1);

    auto added_task = manager.Show().begin()->second;

    EXPECT_EQ(task_id, manager.Show().begin()->first);

    EXPECT_EQ(task_title, added_task.GetTitle());
    EXPECT_EQ(task_date, added_task.GetDate());
    EXPECT_EQ(task_priority, added_task.GetPriority());
}

TEST(TaskManagerTest, shouldThrowWrongIdException)
{
    auto manager = TaskManager{};
    auto task = Task::Create("Task name",
                             time(nullptr),
                             Task::Priority::High);

    ASSERT_THROW(
        manager.Edit(TaskId::Create(123), task),
        std::runtime_error
    );
}

TEST(TaskManagerTest, shouldEditTask)
{
    auto manager = TaskManager{};
    auto task = Task::Create("Task name",
                             time(nullptr),
                             Task::Priority::High);
    manager.Add(task);

    auto new_title = "New task name";
    auto new_date = time(nullptr);
    auto new_priority = Task::Priority::Low;
    auto new_task = Task::Create(new_title,
                                 new_date,
                                 new_priority);

    manager.Edit(TaskId::Create(0), new_task);

    auto edited_task = manager.Show().begin()->second;

    EXPECT_EQ(new_title, edited_task.GetTitle());
    EXPECT_EQ(new_date, edited_task.GetDate());
    EXPECT_EQ(new_priority, edited_task.GetPriority());
}

TEST(TaskManagerTest, shouldDeleteTask)
{
    auto manager = TaskManager{};
    auto task = Task::Create("Task name",
                             time(nullptr),
                             Task::Priority::High);

    auto task_id = manager.Add(task);

    manager.Delete(task_id);

    EXPECT_TRUE(manager.Show().empty());

    EXPECT_THROW(manager.Edit(task_id, task),
                 std::runtime_error);
}

TEST(TaskManagerTest, shouldCompleteTask)
{
    auto manager = TaskManager{};
    auto task = Task::Create("Task name",
                             time(nullptr),
                             Task::Priority::High);

    auto task_id = manager.Add(task);

    manager.Complete(task_id);

    EXPECT_TRUE(manager.Show().empty());

    EXPECT_THROW(manager.Edit(task_id, task),
                 std::runtime_error);
}
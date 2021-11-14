//
// Created by Illia Plaksa on 14.11.2021.
//

#include "gtest/gtest.h"
#include "../../src/model/TaskManager.h"

class TaskManagerTest : public ::testing::Test
{
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST(TaskManagerTest, shouldAddTask)
{
  auto manager = TaskManager{};
  auto task = Task::Create("Task name",
                           time(nullptr),
                           Task::Priority::High);
  manager.Add(task);

  ASSERT_TRUE(manager.Show().size());
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

  auto edited_task = manager.Show()[0].second;
  EXPECT_EQ(new_title, edited_task.GetTitle());
  EXPECT_EQ(new_date, edited_task.GetDate());
  EXPECT_EQ(new_priority, edited_task.GetPriority());
}


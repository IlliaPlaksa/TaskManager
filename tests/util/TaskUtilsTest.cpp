//
// Created by Illia Plaksa on 23.02.2022.
//

#include "gtest/gtest.h"

#include "util/Task/TaskComparators.h"
#include "util/Task/TaskCreators.h"

class TaskUtilsTest : public ::testing::Test
{
};

TEST_F(TaskUtilsTest, shouldCreateTask)
{
    auto title = "Title";
    auto due_date = time(nullptr);
    auto priority = Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"label1", "label2"};

    auto task = CreateTask(title, due_date, priority, labels);

    ASSERT_TRUE(task.has_value());

    EXPECT_EQ(task->title(), title);
    EXPECT_EQ(task->due_date().seconds(), due_date);
    EXPECT_EQ(task->priority(), priority);

    for (const auto& label : labels)
    {
        auto actual_labels = task->labels();
        EXPECT_NE(std::find(actual_labels.cbegin(), actual_labels.cend(), label), actual_labels.cend());
    }
}

TEST_F(TaskUtilsTest, shouldNotCreateTaskWithEmptyTitle)
{
    auto wrong_title = "";
    auto due_date = time(nullptr);
    auto priority = Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"label1", "label2"};

    auto task = CreateTask(wrong_title, due_date, priority, labels);

    ASSERT_FALSE(task.has_value());
}

TEST_F(TaskUtilsTest, shouldNotCreateTaskWithWrongDate)
{
    auto wrong_title = "";
    auto due_date = -12345;
    auto priority = Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"label1", "label2"};

    auto task = CreateTask(wrong_title, due_date, priority, labels);

    ASSERT_FALSE(task.has_value());
}

TEST_F(TaskUtilsTest, shouldCompareEqualTasks)
{
    auto title = "Title";
    auto due_date = time(nullptr);
    auto priority = Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"label1", "label2"};

    auto task1 = CreateTask(title, due_date, priority, labels);
    auto task2 = CreateTask(title, due_date, priority, labels);

    ASSERT_EQ(task1, task2);
}

TEST_F(TaskUtilsTest, shouldCompareNonEqualTasks)
{
    auto title = "Title";
    auto due_date = time(nullptr);
    auto labels = std::vector<std::string>{"label1", "label2"};

    auto task1 = CreateTask(title, due_date, Task_Priority_kMedium, labels);
    auto task2 = CreateTask(title, due_date, Task_Priority_kLow, labels);

    ASSERT_FALSE(task1 == task2);
}


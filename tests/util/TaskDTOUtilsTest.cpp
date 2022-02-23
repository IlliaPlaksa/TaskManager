//
// Created by Illia Plaksa on 23.02.2022.
//

#include "gtest/gtest.h"

#include "util/Task/TaskCreators.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskDTO/TaskDTOComparators.h"
#include "util/TaskDTO/TaskDTOCreators.h"

class TaskUtilsTest : public ::testing::Test
{
};

TEST_F(TaskUtilsTest, shouldCreateTaskDTO)
{
    auto title = "Title";
    auto due_date = time(nullptr);
    auto priority = Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"label1", "label2"};
    auto id_value = 123456;

    auto task = *CreateTask(title, due_date, priority, labels);
    auto task_id = *CreateTaskId(id_value);

    auto task_dto = CreateTaskDTO(task_id, task);

    ASSERT_TRUE(task_dto.has_value());

    auto actual_task_id = task_dto->id();
    auto actual_task = task_dto->task();

    EXPECT_EQ(actual_task_id.value(), id_value);
    EXPECT_EQ(actual_task.title(), title);
    EXPECT_EQ(actual_task.due_date().seconds(), due_date);
    EXPECT_EQ(actual_task.priority(), priority);

    for (const auto& label : labels)
    {
        auto actual_labels = actual_task.labels();
        EXPECT_NE(std::find(actual_labels.cbegin(), actual_labels.cend(), label), actual_labels.cend());
    }
}

TEST_F(TaskUtilsTest, shouldCreateSubTaskDTO)
{
    auto title = "Title";
    auto due_date = time(nullptr);
    auto priority = Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"label1", "label2"};
    auto id_value = 123456;
    auto parent_id_value = 1234;

    auto task = *CreateTask(title, due_date, priority, labels);
    auto task_id = *CreateTaskId(id_value);
    auto parent_id = *CreateTaskId(parent_id_value);

    auto sub_task_dto = CreateSubTaskDTO(task_id, task, parent_id);

    ASSERT_TRUE(sub_task_dto.has_value());

    auto actual_task_id = sub_task_dto->id();
    auto actual_parent_id = sub_task_dto->parent_id();
    auto actual_task = sub_task_dto->task();

    EXPECT_EQ(actual_task_id.value(), id_value);
    EXPECT_EQ(actual_parent_id.value(), parent_id_value);
    EXPECT_EQ(actual_task.title(), title);
    EXPECT_EQ(actual_task.due_date().seconds(), due_date);
    EXPECT_EQ(actual_task.priority(), priority);

    for (const auto& label : labels)
    {
        auto actual_labels = actual_task.labels();
        EXPECT_NE(std::find(actual_labels.cbegin(), actual_labels.cend(), label), actual_labels.cend());
    }
}

TEST_F(TaskUtilsTest, shouldCompareEqualTaskDTO)
{
    auto title = "title";
    auto due_date = 1234;
    auto priority = Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"label1", "label2"};
    auto id_value = 123456;

    auto task = *CreateTask(title, due_date, priority, labels);
    auto task_id = *CreateTaskId(id_value);

    auto task_dto1 = CreateTaskDTO(task_id, task);
    auto task_dto2 = CreateTaskDTO(task_id, task);

    ASSERT_TRUE(task_dto1 == task_dto2);
}

TEST_F(TaskUtilsTest, shouldCompareNonEqualTaskDTO)
{
    auto title = "title";
    auto due_date = 1234;
    auto labels = std::vector<std::string>{"label1", "label2"};
    auto id_value = 123456;

    auto task1 = *CreateTask(title, due_date, Task_Priority_kMedium, labels);
    auto task2 = *CreateTask(title, due_date, Task_Priority_kHigh, labels);
    auto task_id = *CreateTaskId(id_value);

    auto task_dto1 = CreateTaskDTO(task_id, task1);
    auto task_dto2 = CreateTaskDTO(task_id, task2);

    ASSERT_FALSE(task_dto1 == task_dto2);
}


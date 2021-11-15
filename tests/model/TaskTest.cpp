//
// Created by Illia Plaksa on 14.11.2021.
//

#include "gtest/gtest.h"
#include "../../src/model/Task.h"

class TaskTest : public ::testing::Test {};

TEST(TaskTest, Create)
{
    auto title = "Simple task name";
    auto due_date = time(nullptr);
    auto priority = Task::Priority::Medium;

    auto task = Task::Create(title,
                             due_date,
                             priority);
    EXPECT_EQ(task.GetTitle(), title);
    EXPECT_EQ(task.GetDate(), due_date);
    EXPECT_EQ(task.GetPriority(), priority);
}

TEST(TaskTest, EmptyNameException)
{
    EXPECT_THROW(
        Task::Create("", time(nullptr), Task::Priority::Medium),
        std::runtime_error
    );
}



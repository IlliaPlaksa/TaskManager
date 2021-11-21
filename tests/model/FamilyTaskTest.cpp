//
// Created by Illia Plaksa on 20.11.2021.
//

#include "gtest/gtest.h"
#include "../../src/model/FamilyTask.h"

#include "gtest/gtest.h"

class FamilyTaskTest : public ::testing::Test {};

TEST(FamilyTaskTest, shouldCreate)
{
    auto title = "Simple task name";
    auto due_date = time(nullptr);
    auto priority = Task::Priority::Medium;
    auto label = "Simple task label";
    auto parent_id = TaskId::Create(1234);

    auto simple_task = Task::Create(title, due_date, priority, label);
    auto task = FamilyTask::Create(simple_task, parent_id);

    EXPECT_EQ(task.GetTitle(), title);
    EXPECT_EQ(task.GetDate(), due_date);
    EXPECT_EQ(task.GetPriority(), priority);
    EXPECT_EQ(task.GetLabel(), label);
    EXPECT_EQ(task.GetParentId(), parent_id);
}



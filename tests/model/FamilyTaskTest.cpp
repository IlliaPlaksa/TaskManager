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
    auto priority = FamilyTask::Priority::Medium;
    auto label = "Simple task label";
    auto task_id = TaskId::Create(1234);

    auto task = FamilyTask::Create(title,
                             due_date,
                             priority,
                             label,
                             task_id);

    EXPECT_EQ(task.GetTitle(), title);
    EXPECT_EQ(task.GetDate(), due_date);
    EXPECT_EQ(task.GetPriority(), priority);
    EXPECT_EQ(task.GetLabel(), label);
    EXPECT_EQ(task.GetParentId(), task_id);
}



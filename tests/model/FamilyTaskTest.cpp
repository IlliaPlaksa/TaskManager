//
// Created by Illia Plaksa on 20.11.2021.
//

#include "gtest/gtest.h"
#include "../../src/model/include/FamilyTask.h"
#include "../../src/util/TaskCreators.h"
#include "../../src/util/TaskIdCreators.h"
#include "../../src/util/TaskIdComparers.h"

#include "gtest/gtest.h"

class FamilyTaskTest : public ::testing::Test {};

TEST(FamilyTaskTest, shouldCreate)
{
    auto title = "Simple task name";
    auto due_date = time(nullptr);
    auto priority = Task::Priority::Task_Priority_kMedium;
    auto label = "Simple task label";
    auto parent_id = *CreateTaskId(1234);

    auto simple_task = *CreateTask(title, due_date, priority, label);
    auto task = FamilyTask::Create(simple_task, parent_id);

    EXPECT_EQ(task.GetTask().title(), title);
    EXPECT_EQ(task.GetTask().due_date().seconds(), due_date);
    EXPECT_EQ(task.GetTask().priority(), priority);
    EXPECT_EQ(task.GetTask().label(), label);
    EXPECT_EQ(*task.GetParentId(), parent_id);
}



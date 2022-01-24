//
// Created by Illia Plaksa on 20.11.2021.
//

#include "gtest/gtest.h"
#include "model/include/TaskNode.h"
#include "util/Task/TaskCreators.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskId/TaskIdComparators.h"

#include "gtest/gtest.h"

class TaskNodeTest : public ::testing::Test {};

TEST(TaskNodeTest, shouldCreate)
{
    auto title = "Simple task name";
    auto due_date = time(nullptr);
    auto priority = Task::Priority::Task_Priority_kMedium;
    auto labels = std::vector<std::string>{"Label", "SecondLabel"};
    auto parent_id = *CreateTaskId(1234);

    auto simple_task = *CreateTask(title, due_date, priority, labels);
    auto task = TaskNode::Create(simple_task, parent_id);

    EXPECT_EQ(task.GetTask().title(), title);
    EXPECT_EQ(task.GetTask().due_date().seconds(), due_date);
    EXPECT_EQ(task.GetTask().priority(), priority);
    EXPECT_EQ(*task.GetParentId(), parent_id);

    auto actual_labels = task.GetTask().labels();

    for (const auto& label: actual_labels)
    {
        EXPECT_TRUE(std::find(labels.begin(), labels.end(), label) != labels.end());
    }
}



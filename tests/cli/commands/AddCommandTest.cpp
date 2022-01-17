//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/include/ConcreteCommands.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/Task/TaskCreators.h"
#include "util/Task/TaskComparators.h"
#include "util/TaskId/TaskIdComparators.h"

#include "mocks/ModelMock.h"

class AddCommandTest : ::testing::Test {};

TEST(AddCommandTest, shouldExecuteAdd)
{
    auto model = std::make_shared<ModelMock>();

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = *CreateTask(task_title,
                           task_date,
                           task_priority);

    auto command = AddCommand{task, std::nullopt};

    EXPECT_CALL(*model, Add(task))
        .Times(1)
        .WillOnce(testing::Return(ModelResponse::Success()));

    auto response = command.Execute(model);

    EXPECT_FALSE(response.IsError());
}

TEST(AddCommandTest, shouldExecuteAddSubTask)
{
    auto model = std::make_shared<ModelMock>();

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = *CreateTask(task_title,
                            task_date,
                            task_priority);

    auto parent_id = *CreateTaskId(0);

    auto command = AddCommand{task, parent_id};

    EXPECT_CALL(*model, AddSubTask(task, parent_id))
        .Times(1)
        .WillOnce(testing::Return(ModelResponse::Success()));

    auto response = command.Execute(model);

    EXPECT_FALSE(response.IsError());
}
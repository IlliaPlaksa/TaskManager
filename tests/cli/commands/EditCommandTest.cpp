//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/include/ConcreteCommands.h"
#include "util/Task/TaskCreators.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/Task/TaskComparators.h"
#include "util/TaskId/TaskIdComparators.h"

#include "mocks/ModelControllerMock.h"

class EditCommandTest : ::testing::Test {};

TEST(EditCommandTest, shouldExecuteEdit)
{
    auto model = std::make_shared<ModelControllerMock>();

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = *CreateTask(task_title,
                            task_date,
                            task_priority);

    auto id = *CreateTaskId(0);

    auto command = EditCommand{id, task, std::nullopt};

    EXPECT_CALL(*model, Edit(id, task))
        .Times(1)
        .WillRepeatedly(testing::Return(ModelResponse::Success()));

    auto response = command.Execute(model);

    EXPECT_FALSE(response.IsError());
}

TEST(EditCommandTest, shouldExecuteEditSubTask)
{
    auto model = std::make_shared<ModelControllerMock>();

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = *CreateTask(task_title,
                            task_date,
                            task_priority);

    auto id = *CreateTaskId(20349857);
    auto parent_id = CreateTaskId(1234);

    auto command = EditCommand{id, task, parent_id};

    EXPECT_CALL(*model, EditSubTask(id, task, *parent_id))
        .Times(1)
        .WillRepeatedly(testing::Return(ModelResponse::Success()));

    auto response = command.Execute(model);

    EXPECT_FALSE(response.IsError());
}
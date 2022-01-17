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

#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"

class EditCommandTest : ::testing::Test {};

TEST(EditCommandTest, shouldExecuteEdit)
{
    auto model = std::make_shared<ModelMock>();
    auto context_dto = std::make_shared<ContextDTOMock>();

    auto variable_set = VariableSet{};
    variable_set.title = "Title";
    variable_set.date = time(nullptr);
    variable_set.priority = Task::Priority::Task_Priority_kHigh;
    variable_set.id = *CreateTaskId(0);

    auto command = EditCommand{context_dto};

    EXPECT_CALL(*context_dto, variable_set())
        .Times(1)
        .WillRepeatedly(testing::Return(variable_set));

    EXPECT_CALL(*model, Edit(variable_set.id, *variable_set.MakeTask()))
        .Times(1)
        .WillRepeatedly(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);

    variable_set.parent_id = *CreateTaskId(1);
}

TEST(EditCommandTest, shouldExecuteEditSubTask)
{
    auto model = std::make_shared<ModelMock>();
    auto context_dto = std::make_shared<ContextDTOMock>();

    auto variable_set = VariableSet{};
    variable_set.title = "Title";
    variable_set.date = time(nullptr);
    variable_set.priority = Task::Priority::Task_Priority_kHigh;
    variable_set.id = *CreateTaskId(0);
    variable_set.parent_id = *CreateTaskId(1);

    auto command = EditCommand{context_dto};

    EXPECT_CALL(*context_dto, variable_set())
        .Times(1)
        .WillRepeatedly(testing::Return(variable_set));

    EXPECT_CALL(*model, EditSubTask(variable_set.id, *variable_set.MakeTask(), *variable_set.parent_id))
        .Times(1)
        .WillRepeatedly(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);
}
//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../../src/controller/include/ConcreteCommands.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/Task/TaskComparators.h"
#include "util/TaskId/TaskIdComparators.h"

#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"



class AddCommandTest : ::testing::Test {};

TEST(AddCommandTest, shouldExecuteAdd)
{
    auto model = std::make_shared<ModelMock>();

    auto variable_set = VariableSet{};
    variable_set.title = "Title";
    variable_set.date = time(nullptr);
    variable_set.priority = Task::Priority::Task_Priority_kHigh;

    auto context_dto = std::make_shared<ContextDTOMock>();

    auto command = AddCommand{context_dto};

    EXPECT_CALL(*context_dto, variable_set())
    .Times(1)
    .WillOnce(testing::Return(variable_set));

    EXPECT_CALL(*model, Add(*variable_set.MakeTask()))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);
}

TEST(AddCommandTest, shouldExecuteAddSubTask)
{
    auto model = std::make_shared<ModelMock>();

    auto variable_set = VariableSet{};
    variable_set.title = "Title";
    variable_set.date = time(nullptr);
    variable_set.priority = Task::Priority::Task_Priority_kHigh;
    variable_set.parent_id = CreateTaskId(0);

    auto context_dto = std::make_shared<ContextDTOMock>();

    auto command = AddCommand{context_dto};

    EXPECT_CALL(*context_dto, variable_set())
        .Times(1)
        .WillOnce(testing::Return(variable_set));

    EXPECT_CALL(*model, AddSubTask(*variable_set.MakeTask(), *variable_set.parent_id))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);
}
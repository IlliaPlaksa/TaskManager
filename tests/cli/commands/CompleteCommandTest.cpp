//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/ConcreteCommands.h"
#include "mocks/ModelMock.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskId/TaskIdComparators.h"

class CompleteCommandTest : ::testing::Test {};

TEST(CompleteCommandTest, shouldExecute)
{
    auto model = std::shared_ptr<ModelMock>{new ModelMock};
    auto context_dto = std::make_shared<ContextDTOMock>();

    auto command = CompleteCommand{context_dto};

    auto id = *CreateTaskId(0);

    auto variable_set = VariableSet{};
    variable_set.title = "Title";
    variable_set.date = time(nullptr);
    variable_set.priority = Task::Priority::Task_Priority_kHigh;


    EXPECT_CALL(*context_dto, variable_set())
        .Times(1)
        .WillOnce(testing::Return(variable_set));


    EXPECT_CALL(*model, Complete(id))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);
}
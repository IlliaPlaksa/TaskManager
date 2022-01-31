//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/ConcreteCommands.h"
#include "mocks/ModelControllerMock.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskId/TaskIdComparators.h"

class CompleteCommandTest : ::testing::Test {};

TEST(CompleteCommandTest, shouldExecute)
{
    auto model = std::shared_ptr<ModelControllerMock>{new ModelControllerMock};

    auto id = *CreateTaskId(0);
    auto command = CompleteCommand{id};

    EXPECT_CALL(*model, Complete(id))
        .Times(1)
        .WillOnce(testing::Return(ModelResponse::Success()));

    auto response = command.Execute(model);

    EXPECT_FALSE(response.IsError());
}
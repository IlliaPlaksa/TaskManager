//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/ConcreteCommands.h"
#include "mocks/ModelMock.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskId/TaskIdComparators.h"

class DeleteCommandTest : ::testing::Test {};

TEST(DeleteCommandTest, shouldExecute)
{
    auto model = std::shared_ptr<ModelMock>{new ModelMock};

    auto id = *CreateTaskId(0);
    auto command = DeleteCommand{id};

    EXPECT_CALL(*model, Delete(id))
        .Times(1)
        .WillOnce(testing::Return(ModelResponse::Success()));

    auto response = command.Execute(model);

    EXPECT_FALSE(response.IsError());
}
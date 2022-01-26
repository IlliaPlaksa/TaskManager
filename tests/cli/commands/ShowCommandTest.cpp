//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/include/ConcreteCommands.h"

#include "mocks/ModelControllerMock.h"

class ShowCommandTest : ::testing::Test {};

TEST(ShowCommandTest, shouldExecuteCommonLogic)
{
    auto model = std::make_shared<ModelControllerMock>();

    auto command = ShowCommand{};

    EXPECT_CALL(*model, Show())
    .Times(1)
    .WillOnce(testing::Return(std::vector<TaskDTO>{}));

    command.Execute(model);
}
//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/ConcreteCommands.h"

#include "mocks/ModelControllerMock.h"

class ShowCommandTest : ::testing::Test {};

TEST(ShowCommandTest, shouldExecuteWithEmptyLabel)
{
    auto model = std::make_shared<ModelControllerMock>();

    auto command = ShowCommand{std::nullopt};

    EXPECT_CALL(*model, Show())
        .Times(1)
        .WillOnce(testing::Return(std::vector<TaskDTO>{}));

    command.Execute(model);
}

TEST(ShowCommandTest, shouldExecuteWithNonEmptyLabel)
{
    auto model = std::make_shared<ModelControllerMock>();

    auto label = "Label";

    auto command = ShowCommand{label};

    EXPECT_CALL(*model, ShowTasksWithLabel(label))
        .Times(1)
        .WillOnce(testing::Return(std::vector<TaskDTO>{}));

    command.Execute(model);
}
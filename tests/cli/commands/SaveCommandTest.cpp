//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/include/ConcreteCommands.h"
#include "util/TaskDTO/TaskDTOComparators.h"

#include "mocks/ModelControllerMock.h"

class SaveCommandTest : ::testing::Test {};

TEST(SaveCommandTest, shouldExecuteSave)
{
    auto model = std::make_shared<ModelControllerMock>();

    auto file_name = "file.txt";

    auto command = SaveCommand{file_name};

    auto tasks = std::vector<TaskDTO>{};

    EXPECT_CALL(*model, SaveToFile(file_name))
        .Times(1)
        .WillOnce(testing::Return(ModelResponse::Success()));

    command.Execute(model);
}


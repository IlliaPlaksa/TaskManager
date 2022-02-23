//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/ConcreteCommands.h"
#include "util/TaskDTO/TaskDTOComparators.h"

#include "mocks/ModelControllerMock.h"
#include "mocks/PersisterMock.h"

class LoadCommandTest : ::testing::Test {};

TEST(LoadCommandTest, shouldExecuteLoad)
{
    auto model = std::make_shared<ModelControllerMock>();
    auto persister = std::make_shared<TaskPersisterMock>();

    auto file_name = "file.txt";

    auto command = LoadCommand{file_name};

    EXPECT_CALL(*model, LoadFromFile(file_name))
        .Times(1)
        .WillOnce(testing::Return(ModelResponse::Success()));

    command.Execute(model);
}
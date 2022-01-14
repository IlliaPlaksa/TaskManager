//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../../src/controller/include/ConcreteCommands.h"

#include "util/TaskDTO/TaskDTOComparators.h"

#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"

class LoadCommandTest : ::testing::Test {};

// TODO add persister testing
TEST(LoadCommandTest, shouldExecuteLoad)
{
    auto model = std::make_shared<ModelMock>();
    auto context_dto = std::make_shared<ContextDTOMock>();

    auto variable_set = VariableSet{};
    variable_set.file_name = "file.txt";

    auto command = LoadCommand{context_dto};

    auto tasks = std::vector<TaskDTO>{};

    EXPECT_CALL(*context_dto, variable_set())
        .Times(1)
        .WillOnce(testing::Return(variable_set));

    EXPECT_CALL(*model, Load(tasks))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);
}
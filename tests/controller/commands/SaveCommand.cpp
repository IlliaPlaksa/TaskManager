//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/include/ConcreteCommands.h"

#include "util/TaskDTO/TaskDTOComparators.h"

#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"

class SaveCommandTest : ::testing::Test {};

// TODO add persister testing
TEST(SaveCommandTest, shouldExecuteSave)
{
    auto model = std::make_shared<ModelMock>();
    auto context_dto = std::make_shared<ContextDTOMock>();

    auto variable_set = VariableSet{};
    variable_set.file_name = "file.txt";

    auto command = SaveCommand{context_dto};

    auto tasks = std::vector<TaskDTO>{};

    EXPECT_CALL(*context_dto, variable_set())
        .Times(1)
        .WillOnce(testing::Return(variable_set));

    EXPECT_CALL(*model, Show())
        .Times(1)
        .WillOnce(testing::Return(tasks));

    command.Execute(model);
}

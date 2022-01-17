//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/include/ConcreteCommands.h"
#include "util/TaskDTO/TaskDTOComparators.h"

#include "mocks/ModelMock.h"
#include "mocks/PersisterMock.h"

class LoadCommandTest : ::testing::Test {};

// TODO add persister testing
//TEST(LoadCommandTest, shouldExecuteLoad)
//{
//    auto model = std::make_shared<ModelMock>();
//    auto persister = std::make_shared<TaskPersisterMock>();
//
//    auto file_name = "file.txt";
//
//    auto command = LoadCommand{file_name};
//
//    auto tasks = std::vector<TaskDTO>{};
//
//    EXPECT_CALL(*model, Load(tasks))
//        .Times(1)
//        .WillOnce(testing::Return(ModelResponse::Success()));
//
//    command.Execute(model);
//}
//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "cli/include/ConcreteCommands.h"
#include "util/TaskDTO/TaskDTOComparators.h"

#include "mocks/ModelMock.h"

class SaveCommandTest : ::testing::Test {};

// TODO add persister testing
//TEST(SaveCommandTest, shouldExecuteSave)
//{
//    auto model = std::make_shared<ModelMock>();
//
//    auto file_name = "file.txt";
//
//    auto command = SaveCommand{file_name};
//
//    auto tasks = std::vector<TaskDTO>{};
//
//    EXPECT_CALL(*model, Show())
//        .Times(1)
//        .WillOnce(testing::Return(tasks));
//
//    command.Execute(model);
//}

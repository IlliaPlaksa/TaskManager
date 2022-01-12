//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../../src/controller/include/ConcreteCommands.h"
#include "../../../src/util/TaskCreators.h"
#include "../../../src/util/TaskComparers.h"

#include "../mocks/ModelMock.h"



class AddCommandTest : ::testing::Test {};

TEST(AddCommandTest, shouldExecuteCommonLogic)
{
    auto model = std::make_shared<ModelMock>();
    auto context_dto = std::make_shared<ContextDTO>();

    auto command = AddCommand{context_dto};

    auto task = *CreateTask("Title",
                           time(nullptr),
                           Task::Priority::Task_Priority_kHigh);

    EXPECT_CALL(*model, Add(task))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);
}
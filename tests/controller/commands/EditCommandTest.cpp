//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../../src/controller/include/ConcreteCommands.h"
#include "../../../src/util/TaskCreators.h"
#include "../../../src/util/TaskIdCreators.h"
#include "../../../src/util/TaskComparers.h"
#include "../../../src/util/TaskIdComparers.h"

#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"

class EditCommandTest : ::testing::Test {};

TEST(EditCommandTest, shouldExecuteCommonLogic)
{
    auto model = std::make_shared<ModelMock>();
    auto context_dto = std::make_shared<ContextDTOMock>();

    auto command = EditCommand{context_dto};

    auto task = *CreateTask("Title",
                             time(nullptr),
                             Task::Priority::Task_Priority_kHigh);

    auto id = *CreateTaskId(123);

    EXPECT_CALL(*context_dto, variable_set())
    .Times(1)
    .WillOnce(testing::Return(VariableSet()));

    EXPECT_CALL(*model, Edit(id, task))
    .Times(1);

    command.Execute(model);
}
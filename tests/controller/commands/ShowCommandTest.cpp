//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "controller/include/ConcreteCommands.h"

#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"

class ShowCommandTest : ::testing::Test {};

TEST(ShowCommandTest, shouldExecuteCommonLogic)
{
    auto model = std::make_shared<ModelMock>();
    auto context_dto = std::make_shared<ContextDTOMock>();

    auto command = ShowCommand{context_dto};

    EXPECT_CALL(*model, Show())
    .Times(1)
    .WillOnce(testing::Return(std::vector<TaskDTO>{}));

    command.Execute(model);
}
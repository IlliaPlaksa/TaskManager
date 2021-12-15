//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../../src/controller/include/ConcreteCommands.h"
#include "../mocks/ModelMock.h"
#include "../mocks/ViewMock.h"

class CompleteCommandTest : ::testing::Test {};

TEST(CompleteCommandTest, shouldExecute)
{
    auto model = std::shared_ptr<ModelMock>{new ModelMock};
    auto view = std::shared_ptr<ViewMock>{new ViewMock};

    auto command = CompleteCommand{model};

    auto id = TaskId::CreateDefault();

    EXPECT_CALL(*view, GetTaskStruct())
        .Times(1);
    EXPECT_CALL(*model, Complete(id))
        .Times(1);

    command.Execute(view);
}
//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../../src/controller/include/ConcreteCommands.h"
#include "../mocks/ModelMock.h"
#include "../mocks/ViewMock.h"

class ShowCommandTest : ::testing::Test {};

TEST(ShowCommandTest, shouldExecuteCommonLogic)
{
    auto model = std::shared_ptr<ModelMock>{new ModelMock};
    auto view = std::shared_ptr<ViewMock>{new ViewMock};

    auto command = ShowCommand{model};

    EXPECT_CALL(*model, ShowParents())
        .Times(1);

    command.Execute(view);
}
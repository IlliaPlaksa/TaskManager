//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../../src/controller/include/ConcreteCommands.h"
#include "../mocks/ModelMock.h"
#include "../mocks/ViewMock.h"

class ShowCommandTest : ::testing::Test {};

TEST(ShowCommandTest, shouldCreate)
{
//    auto model = std::shared_ptr<IModel>{new ModelMock};
//    auto view = std::shared_ptr<IView>{new ViewMock};
//
//    auto command = CompleteCommand{model};
//
//    EXPECT_CALL(*model, ())
//    .Times(1)
//    .WillOnce(testing::Return());
//
//    command.Execute(view);
}
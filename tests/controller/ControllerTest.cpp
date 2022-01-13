//
// Created by Illia Plaksa on 13.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/controller/include/Controller.h"
#include "mocks/ModelMock.h"
#include "mocks/CommandFactoryMock.h"
#include "mocks/CommandMock.h"

class ControllerTest : public ::testing::Test {};

TEST(ControllerTest, shouldCreate)
{
    auto factory = std::make_shared<CommandFactoryMock>();

    ASSERT_NO_THROW(Controller{std::shared_ptr<Model>{new ModelMock}});
}

TEST(ControllerTest, shouldCreateAndExecuteCommand)
{
    auto model = std::shared_ptr<Model>{new ModelMock};
    auto factory = std::make_shared<CommandFactoryMock>();
    auto obj = Controller{model};

    auto command = std::make_shared<CommandMock>();

    EXPECT_CALL(*command, IsReady())
    .Times(1)
    .WillOnce(testing::Return(true));

    EXPECT_CALL(*command, Execute(model))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateSuccess()));

    obj.Action(command);
}
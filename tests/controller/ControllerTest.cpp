//
// Created by Illia Plaksa on 13.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/controller/include/Controller.h"
#include "mocks/ModelMock.h"
#include "mocks/ViewMock.h"
#include "mocks/CommandFactoryMock.h"
#include "mocks/CommandMock.h"

class ControllerTest : public ::testing::Test {};

TEST(ControllerTest, shouldCreate)
{
    auto model = std::make_shared<ModelMock>();
    auto factory = std::make_shared<CommandFactoryMock>();

    ASSERT_NO_THROW(Controller(model, factory));
}

TEST(ControllerTest, shouldCreateAndExecuteCommand)
{
    auto model = std::shared_ptr<Model>{new ModelMock};
    auto view = std::shared_ptr<View>{new ViewMock};
    auto factory = std::make_shared<CommandFactoryMock>();
    auto obj = Controller{model, factory};
    auto command = std::make_shared<CommandMock>(model);
    auto command_type = CommandType::kNone;

    EXPECT_CALL(*factory, CreateCommand(command_type, model))
        .Times(1)
        .WillOnce(testing::Return(command));

    EXPECT_CALL(*command, Execute(view))
        .Times(1)
        .WillOnce(testing::Return(Response{}));

    obj.Action(view, command_type);
}
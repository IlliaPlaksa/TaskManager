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

TEST(ControllerTest, shouldHandleCommandReturnedError)
{
    auto model = std::shared_ptr<Model>{new ModelMock};
    auto factory = std::make_shared<CommandFactoryMock>();
    auto obj = Controller{model};

    auto command = std::make_shared<CommandMock>();

    EXPECT_CALL(*command, IsReady())
        .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*command, Execute(model))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateError(Model::Response::ErrorType::FAIL)));

    auto response = obj.Action(command);

    EXPECT_TRUE(response.IsError());
}

TEST(ControllerTest, shouldHandleCommandWithWrongContext)
{
    auto model = std::shared_ptr<Model>{new ModelMock};
    auto factory = std::make_shared<CommandFactoryMock>();
    auto obj = Controller{model};

    auto command = std::make_shared<CommandMock>();

    EXPECT_CALL(*command, IsReady())
        .WillRepeatedly(testing::Return(false));

    auto response = obj.Action(command);

    EXPECT_TRUE(response.IsError());
}

TEST(ControllerTest, shouldHandleNullptrCommand)
{
    auto model = std::shared_ptr<Model>{new ModelMock};
    auto factory = std::make_shared<CommandFactoryMock>();
    auto obj = Controller{model};

    auto command = std::shared_ptr<CommandMock>(nullptr);

    auto response = obj.Action(command);

    EXPECT_TRUE(response.IsError());
}

TEST(ControllerTest, shouldCreateErrorMessage)
{
    auto model = std::shared_ptr<Model>{new ModelMock};
    auto factory = std::make_shared<CommandFactoryMock>();
    auto obj = Controller{model};

    using ErrorType = Model::Response::ErrorType;
    auto test = std::vector<std::pair<ErrorType, std::string>>
    {
        std::make_pair(ErrorType::INVALID_ID, "Invalid ID passed"),
        std::make_pair(ErrorType::EMPTY_TITLE, "Empty title of Task passed"),
        std::make_pair(ErrorType::NON_EXISTING_PARENT_ID, "Non-existing parent ID passed"),
        std::make_pair(ErrorType::FAIL, "Something went wrong"),
    };

    auto command = std::make_shared<CommandMock>();

    EXPECT_CALL(*command, IsReady())
    .WillRepeatedly(testing::Return(true));

    for (const auto& elem : test)
    {
        EXPECT_CALL(*command, Execute(model))
        .WillOnce(testing::Return(Model::Response::CreateError(elem.first)));
        auto response = obj.Action(command);
        EXPECT_EQ(response.error(), elem.second);
    }
}

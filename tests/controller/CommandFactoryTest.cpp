//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/controller/include/CommandFactory.h"

class CommandFactoryTest : public ::testing::Test {};

TEST(CommandFactoryTest, shouldCreateCommands)
{
    auto factory = CommandFactory{};
    std::vector<CommandType> types = {
        CommandType::kAdd,
        CommandType::kEdit,
        CommandType::kComplete,
        CommandType::kDelete,
        CommandType::kShow
    };

    auto model = std::shared_ptr<IModel>(nullptr);

    for (auto type: types)
    {
        EXPECT_NE(nullptr,
                  factory.CreateCommand(type, model));
    }
}

TEST(CommandFactoryTest, shouldReturnNullptrToNoneCommandType)
{
    auto factory = CommandFactory{};
    auto model = std::shared_ptr<IModel>(nullptr);

    EXPECT_EQ(nullptr,
              factory.CreateCommand(CommandType::kNone, model));
}
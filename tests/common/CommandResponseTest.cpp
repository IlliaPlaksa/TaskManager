//
// Created by Illia Plaksa on 17.01.2022.
//

#include "common/CommandResponse.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class CommandResponseTest : testing::Test
{
};

TEST(CommandResponseTest, shouldWorkIsErrorMethod)
{
    auto response = CommandResponse{};
    response.model_response = ModelResponse::Error(ModelResponse::ErrorType::FAIL);

    EXPECT_TRUE(response.IsError());

    response = CommandResponse{};

    EXPECT_TRUE(response.IsError());

    response = CommandResponse{};
    response.tasks = TaskStorage{};

    EXPECT_FALSE(response.IsError());

    response = CommandResponse{};
    response.model_response = ModelResponse::Success();
    EXPECT_FALSE(response.IsError());
}
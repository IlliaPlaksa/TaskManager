//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "common/include/Model.h"

class ModelResponseTest : public ::testing::Test {};

TEST(ModelResponseTest, shouldIsErrorMethodWorks)
{
    auto response = ModelResponse::Success();

    EXPECT_EQ(response.IsError(), response.status() == ModelResponse::Status::kError);
}


TEST(ModelResponseTest, shouldCreateSuccessResponse)
{
    auto response = ModelResponse::Success();

    EXPECT_EQ(response.status(), ModelResponse::Status::kSuccess);
    EXPECT_TRUE(!response.IsError());
}

TEST(ModelResponseTest, shouldCreateErrorResponse)
{
    auto response = ModelResponse::Error(ModelResponse::ErrorType::FAIL);

    EXPECT_EQ(response.status(), ModelResponse::Status::kError);
    EXPECT_TRUE(response.IsError());
}

//
// Created by Illia Plaksa on 13.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "common/include/Model.h"

class ModelResponseTest : public ::testing::Test {};

TEST(ModelResponseTest, shouldIsErrorMethodWorks)
{
    auto response = Model::Response::CreateSuccess();

    EXPECT_EQ(response.IsError(), response.status() == Model::Response::Status::kError);
}


TEST(ModelResponseTest, shouldCreateSuccessResponse)
{
    auto response = Model::Response::CreateSuccess();

    EXPECT_EQ(response.status(), Model::Response::Status::kSuccess);
    EXPECT_TRUE(!response.IsError());
}

TEST(ModelResponseTest, shouldCreateErrorResponse)
{
    auto response = Model::Response::CreateError(Model::Response::ErrorType::FAIL);

    EXPECT_EQ(response.status(), Model::Response::Status::kError);
    EXPECT_TRUE(response.IsError());
}

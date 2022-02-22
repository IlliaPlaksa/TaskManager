//
// Created by Illia Plaksa on 22.02.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "util/Response/ModelResponseUtils.h"

class ModelResponseUtilTest : public ::testing::Test
{
};

TEST_F(ModelResponseUtilTest, shouldCreateStringFromStatus)
{
    auto input =std::vector<ModelResponse::Status>{
        ModelResponse::Status::kSuccess,
        ModelResponse::Status::kError,
    };

    auto expect = std::vector<std::string> {
        "SUCCESS",
        "ERROR"
    };

    for(size_t i = 0; i < input.size(); ++i)
    {
        auto output = to_string(input[i]);
        EXPECT_EQ(output, expect[i]);
    }
}

TEST_F(ModelResponseUtilTest, shouldCreateStringFromErrorType)
{
    auto input = std::vector<ModelResponse::ErrorType>{
        ModelResponse::ErrorType::FAIL,
        ModelResponse::ErrorType::EMPTY_TITLE,
        ModelResponse::ErrorType::INVALID_ID,
        ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS,
        ModelResponse::ErrorType::NON_EXISTING_PARENT_ID,
    };

    auto expect = std::vector<std::string> {
        "FAIL",
        "EMPTY TITLE",
        "INVALID ID",
        "NOT COMPLETED SUBTASKS",
        "NON EXISTING PARENT ID"
    };

    for(size_t i = 0; i < input.size(); ++i)
    {
        auto output = to_string(input[i]);
        EXPECT_EQ(output, expect[i]);
    }
}

TEST_F(ModelResponseUtilTest, shouldCreateStingFromModelResponse)
{
    auto input = std::vector<ModelResponse>{
        ModelResponse::Success(),
        ModelResponse::Error(ModelResponse::ErrorType::FAIL)
    };

    auto expect = std::vector<std::string> {
        "Status: SUCCESS",
        "Status: ERROR Error: FAIL",
    };

    for(size_t i = 0; i < input.size(); ++i)
    {
        auto output = to_string(input[i]);
        EXPECT_EQ(output, expect[i]);
    }
}
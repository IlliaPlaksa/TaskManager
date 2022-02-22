//
// Created by Illia Plaksa on 22.02.2022.
//

#include "gtest/gtest.h"

#include "util/Response/ResponseConverters.h"

bool operator==(const ModelResponse& first, const ModelResponse& second)
{
    return first.status() == second.status()
        and first.error() == second.error();
}

class ResponseConvertersTest : public ::testing::Test
{
};

TEST_F(ResponseConvertersTest, shouldConvertSuccessModelResponseToServiceResponse)
{
    auto input = ModelResponse::Success();

    auto expect = service::Response{};
    expect.set_status(service::Response_Status_kSuccess);

    auto result = ModelResponseToServiceResponse(input);

    EXPECT_EQ(result.status(), expect.status());
    EXPECT_EQ(result.error_type(), expect.error_type());
}

TEST_F(ResponseConvertersTest, shouldConvertErrorModelResponseToServiceResponse)
{
    auto input = std::vector<ModelResponse>{
        ModelResponse::Error(ModelResponse::ErrorType::FAIL),
        ModelResponse::Error(ModelResponse::ErrorType::EMPTY_TITLE),
        ModelResponse::Error(ModelResponse::ErrorType::INVALID_ID),
        ModelResponse::Error(ModelResponse::ErrorType::NON_EXISTING_PARENT_ID),
        ModelResponse::Error(ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS)
    };

    auto expect_error_types = std::vector<service::Response::ErrorType>{
        service::Response_ErrorType_FAIL,
        service::Response_ErrorType_EMPTY_TITLE,
        service::Response_ErrorType_INVALID_ID,
        service::Response_ErrorType_NON_EXISTING_PARENT_ID,
        service::Response_ErrorType_NOT_COMPLETED_SUBTASKS
    };

    for (size_t i = 0 ; i < input.size() ; ++i)
    {
        auto result = ModelResponseToServiceResponse(input[i]);

        EXPECT_EQ(result.status(), service::Response_Status_kError);
        EXPECT_EQ(result.error_type(), expect_error_types[i]);
    }
}

TEST_F(ResponseConvertersTest, shouldConvertSuccessServiceResponseToModelResponse)
{
    auto input = service::Response{};
    input.set_status(service::Response_Status_kSuccess);

    auto expect = ModelResponse::Success();

    auto result = ServiceResponseToModelResponse(input);

    EXPECT_EQ(result, expect);
}

TEST_F(ResponseConvertersTest, shouldConvertErrorServiceResponseToModelResponse)
{
    auto input_error_types = std::vector<service::Response::ErrorType>{
        service::Response_ErrorType_FAIL,
        service::Response_ErrorType_EMPTY_TITLE,
        service::Response_ErrorType_INVALID_ID,
        service::Response_ErrorType_NON_EXISTING_PARENT_ID,
        service::Response_ErrorType_NOT_COMPLETED_SUBTASKS
    };

    auto expect_responses = std::vector<ModelResponse>{
        ModelResponse::Error(ModelResponse::ErrorType::FAIL),
        ModelResponse::Error(ModelResponse::ErrorType::EMPTY_TITLE),
        ModelResponse::Error(ModelResponse::ErrorType::INVALID_ID),
        ModelResponse::Error(ModelResponse::ErrorType::NON_EXISTING_PARENT_ID),
        ModelResponse::Error(ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS)
    };

    for (size_t i = 0 ; i < input_error_types.size() ; ++i)
    {
        auto input_service_response = service::Response{};
        input_service_response.set_status(service::Response_Status_kError);
        input_service_response.set_error_type(input_error_types[i]);

        auto result = ServiceResponseToModelResponse(input_service_response);

        EXPECT_EQ(result, expect_responses[i]);
    }
}
//
// Created by Illia Plaksa on 26.01.2022.
//

#include "ResponseConverters.h"

// Declaration of helpers functions
service::Response::ErrorType ModelErrorToServiceError(const ModelResponse::ErrorType& error_type);
ModelResponse::ErrorType ServiceErrorToModelError(service::Response::ErrorType);

service::Response ModelResponseToServiceResponse(const ModelResponse& response)
{
    auto result = service::Response{};
    if (response.IsError())
    {
        result.set_status(service::Response_Status_kError);
        result.set_error_type(ModelErrorToServiceError(*response.error()));
    }
    else
    {
        result.set_status(service::Response_Status_kSuccess);
    }

    return result;
}
ModelResponse ServiceResponseToModelResponse(const service::Response& response)
{
    if (response.status() == service::Response_Status_kSuccess)
        return ModelResponse::Success();
    else
        return ModelResponse::Error(ServiceErrorToModelError(response.error_type()));
}

// Definition of helpers functions
service::Response::ErrorType ModelErrorToServiceError(const ModelResponse::ErrorType& error_type)
{
    switch (error_type)
    {
        case ModelResponse::ErrorType::FAIL: { return service::Response_ErrorType_FAIL; }
        case ModelResponse::ErrorType::EMPTY_TITLE: { return (service::Response_ErrorType_EMPTY_TITLE); }
        case ModelResponse::ErrorType::INVALID_ID: { return (service::Response_ErrorType_INVALID_ID); }
        case ModelResponse::ErrorType::NON_EXISTING_PARENT_ID: { return (service::Response_ErrorType_NON_EXISTING_PARENT_ID); }
        case ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS: { return (service::Response_ErrorType_NOT_COMPLETED_SUBTASKS); }
    }
}
ModelResponse::ErrorType ServiceErrorToModelError(service::Response::ErrorType error_type)
{
    switch (error_type)
    {
        case service::Response_ErrorType_FAIL: { return ModelResponse::ErrorType::FAIL; }
        case service::Response_ErrorType_EMPTY_TITLE: { return ModelResponse::ErrorType::EMPTY_TITLE; }
        case service::Response_ErrorType_INVALID_ID: { return ModelResponse::ErrorType::INVALID_ID; }
        case service::Response_ErrorType_NON_EXISTING_PARENT_ID: { return ModelResponse::ErrorType::NON_EXISTING_PARENT_ID; }
        case service::Response_ErrorType_NOT_COMPLETED_SUBTASKS: { return ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS; }
        default:return ModelResponse::ErrorType::FAIL;
    }
}

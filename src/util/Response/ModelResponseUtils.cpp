//
// Created by Illia Plaksa on 04.02.2022.
//

#include <string>
#include "ModelResponseUtils.h"

std::string to_string(const ModelResponse::Status& status)
{
    switch (status)
    {
        case ModelResponse::Status::kSuccess: { return std::string{"SUCCESS"}; }
        case ModelResponse::Status::kError: { return std::string{"ERROR"}; }
        default: { return std::string{}; }
    }

}
std::string to_string(const ModelResponse::ErrorType& error_type)
{
    switch (error_type)
    {
        case ModelResponse::ErrorType::FAIL : { return std::string{"FAIL"}; }
        case ModelResponse::ErrorType::EMPTY_TITLE : { return std::string{"EMPTY TITLE"}; }
        case ModelResponse::ErrorType::INVALID_ID : { return std::string{"INVALID ID"}; }
        case ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS : { return std::string{"NOT COMPLETED SUBTASKS"}; }
        case ModelResponse::ErrorType::NON_EXISTING_PARENT_ID : { return std::string{"NON EXISTING PARENT ID"}; }
        default: { return std::string{}; }
    }
}
std::string to_string(const ModelResponse& model_response)
{
    std::string result{};

    result += "Status: " + to_string(model_response.status());

    auto error_message = model_response.error();
    if (error_message.has_value())
        result += " Error:" + to_string(error_message.value());

    return result;
}

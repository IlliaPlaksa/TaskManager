//
// Created by Illia Plaksa on 16.01.2022.
//

#include "ModelResponse.h"

ModelResponse ModelResponse::Success()
{
    ModelResponse result;
    result.status_ = Status::kSuccess;
    result.error_type_ = std::nullopt;
    return result;
}
ModelResponse ModelResponse::Error(const ModelResponse::ErrorType& error_type)
{
    ModelResponse result;
    result.status_ = Status::kError;
    result.error_type_ = error_type;
    return result;
}
bool ModelResponse::IsError() const
{
    return status_ == Status::kError;
}
std::optional<ModelResponse::ErrorType> ModelResponse::error() const
{
    return this->error_type_;
}
ModelResponse::Status ModelResponse::status() const
{
    return this->status_;
}



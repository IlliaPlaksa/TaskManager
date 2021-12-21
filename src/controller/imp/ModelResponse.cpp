//
// Created by Illia Plaksa on 21.12.2021.
//

#include "../include/Model.h"

Model::Response Model::Response::CreateSuccess()
{
    Response result;
    result.status_ = Status::kSuccess;
    result.error_type_ = std::nullopt;
    return result;
}
Model::Response Model::Response::CreateError(const Model::Response::ErrorType &error_type)
{
    Response result;
    result.status_ = Status::kError;
    result.error_type_ = error_type;
    return result;
}
bool Model::Response::IsError()
{
    return status_ == Status::kError;
}
std::optional<Model::Response::ErrorType> Model::Response::error()
{
    return this->error_type_;
}
Model::Response::Status Model::Response::status()
{
    return this->status_;
}

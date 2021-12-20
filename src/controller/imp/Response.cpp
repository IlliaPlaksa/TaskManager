//
// Created by Illia Plaksa on 17.12.2021.
//

#include "../include/Response.h"

Response::Response()
    :
    status_(Status::kNone),
    error_message_(std::string())
{
}

bool Response::IsError() { return status_ == Status::kError; }

std::optional<std::string> Response::error()
{
    return error_message_;
}
Response::Status Response::status()
{
    return status_;
}
Response Response::CreateSuccess()
{
    auto response = Response{};
    response.status_ = Status::kSuccess;

    return response;
}
Response Response::CreateError(const std::string &message)
{
    auto response = Response{};
    response.status_ = Status::kError;
    response.error_message_ = message;

    return response;
}

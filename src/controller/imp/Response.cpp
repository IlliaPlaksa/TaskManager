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

void Response::SetStatus(Response::Status status)
{
    status_ = status;
}
void Response::SetErrorMessage(const std::string &message)
{
    error_message_ = message;
}
std::optional<std::string> Response::error()
{
    return error_message_;
}
Response::Status Response::status()
{
    return status_;
}

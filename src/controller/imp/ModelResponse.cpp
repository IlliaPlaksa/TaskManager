//
// Created by Illia Plaksa on 17.12.2021.
//

#include "../include/IModel.h"

IModel::Response::Response()
    :
    status_(Status::kNone),
    error_message_(std::string())
{
}

bool IModel::Response::IsError() { return status_ == Status::kError; }

void IModel::Response::SetStatus(IModel::Response::Status status)
{
    status_ = status;
}
void IModel::Response::SetErrorMessage(const std::string &message)
{
    error_message_ = message;
}
std::optional<std::string> IModel::Response::error()
{
    return error_message_;
}
IModel::Response::Status IModel::Response::status()
{
    return status_;
}

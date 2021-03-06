//
// Created by Illia Plaksa on 22.11.2021.
//

#include "cli/Context.h"

Context::Context()
    :
    task_storage_(std::make_shared<TaskStorage>()),
    error_message_(std::nullopt)
{
}
std::shared_ptr<TaskStorage> Context::GetStorage() const
{
    return this->task_storage_;
}
std::optional<std::string> Context::GetError() const
{
    return this->error_message_;
}
void Context::SetError(const std::string& message)
{
    this->error_message_ = message;
}

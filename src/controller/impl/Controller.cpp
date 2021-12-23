//
// Created by Illia Plaksa on 03.12.2021.
//

#include "../include/Controller.h"

Controller::Controller(const std::shared_ptr<Model>& model,
                       const std::shared_ptr<CommandFactory>& command_factory)
    :
    model_(model),
    command_factory_(command_factory)
{
}

Controller::Response Controller::Action(const std::shared_ptr<View>& view,
                                        const CommandType& command_type)
{
    auto command = command_factory_->CreateCommand(command_type, model_);
    if (command)
    {
        auto command_result = command->Execute(view);

        if (command_result.IsError())
            return Response::CreateError(
                CreateErrorMessage(*command_result.error())
            );
        else
            return Response::CreateSuccess();

    }
    return Response::CreateSuccess();
}
std::string Controller::CreateErrorMessage(const Model::Response::ErrorType& error_type)
{
    switch (error_type)
    {
        case Model::Response::ErrorType::INVALID_ID:return "Invalid ID passed";
        case Model::Response::ErrorType::EMPTY_TITLE:return "Empty title of Task passed";
        case Model::Response::ErrorType::NON_EXISTING_PARENT_ID:return "Non-existing parent Task ID passed";
        default:return "Something went wrong";
    }
}
Controller::Response Controller::Response::CreateSuccess()
{
    Response result;
    result.status_ = Status::kSuccess;
    result.error_message_ = std::nullopt;
    return result;
}
Controller::Response Controller::Response::CreateError(const std::string& message)
{
    Response result;
    result.status_ = Status::kError;
    result.error_message_ = message;
    return result;
}

bool Controller::Response::IsError()
{
    return status_ == Status::kError;
}
std::optional<std::string> Controller::Response::error()
{
    return this->error_message_;
}
Controller::Response::Status Controller::Response::status()
{
    return this->status_;
}

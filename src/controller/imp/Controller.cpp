//
// Created by Illia Plaksa on 03.12.2021.
//

#include "../include/Controller.h"

Controller::Controller(const std::shared_ptr<IModel> &model,
                       const std::shared_ptr<CommandFactory> &command_factory)
    :
    model_(model),
    command_factory_(command_factory)
{
}

Response Controller::Action(const std::shared_ptr<IView> &view,
                            const CommandType &command_type)
{
    auto result = Response{};
    auto command = command_factory_->CreateCommand(command_type, model_);
    if (command)
    {
        result = command->Execute(view);
    }
    return result;
}
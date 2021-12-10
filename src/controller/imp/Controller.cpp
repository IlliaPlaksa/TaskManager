//
// Created by Illia Plaksa on 03.12.2021.
//

#include "../include/Controller.h"
Controller::Controller(const std::shared_ptr<IModel> &model)
    :
    model_(model) {}

Command::Response Controller::Action(const std::shared_ptr<Command> &command)
{
    return command->Execute(model_);
}
//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/ConcreteCommands.h"

CommandResponse CompleteCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};
    result.model_response = model->Complete(id_);

    return result;
}
CompleteCommand::CompleteCommand(const TaskId& id)
    :
    id_(id)
{
}

//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/include/ConcreteCommands.h"

CommandResponse DeleteCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};
    result.model_response = model->Delete(id_);

    return result;
}
DeleteCommand::DeleteCommand(const TaskId& id)
    :
    id_(id)
{
}


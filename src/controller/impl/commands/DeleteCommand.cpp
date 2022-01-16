//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

CommandResponse DeleteCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto result = CommandResponse{};
    result.model_response =  model->Delete(id_);

    return result;
}
DeleteCommand::DeleteCommand(const TaskId& id)
{
    this->id_ = id;
}


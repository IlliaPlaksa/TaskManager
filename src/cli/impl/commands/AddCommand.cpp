//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/include/ConcreteCommands.h"
#include "util/Task/TaskCreators.h"

CommandResponse AddCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto result = CommandResponse{};

    if (this->parent_id_.has_value())
        result.model_response = model->AddSubTask(task_, *parent_id_);
    else
        result.model_response = model->Add(task_);

    return result;
}
AddCommand::AddCommand(const Task& task, const std::optional<TaskId>& parent_id)
{
    this->task_ = task;
    this->parent_id_ = parent_id;
}

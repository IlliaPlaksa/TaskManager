//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"
#include "util/Task/TaskCreators.h"

CommandResponse EditCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto result = CommandResponse{};

    if (parent_id_.has_value())
        result.model_response = model->EditSubTask(id_, task_, *parent_id_);
    else
        result.model_response = model->Edit(id_, task_);

    return result;
}
EditCommand::EditCommand(const TaskId& id, const Task& task, const std::optional<TaskId>& parent_id)
    :
    id_(id),
    task_(task),
    parent_id_(parent_id)
{
}


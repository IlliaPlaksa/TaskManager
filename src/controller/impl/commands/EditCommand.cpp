//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"
#include "util/Task/TaskCreators.h"

Model::Response EditCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto context = this->GetContext();
    auto var_set = context->variable_set();

    auto id = var_set.id;
    auto task = var_set.MakeTask();

    if (var_set.parent_id.has_value())
        return model->EditSubTask(id, *task, *var_set.parent_id);
    else
        return model->Edit(id, *task);
}
bool EditCommand::IsReady() const
{
    auto task_dto = GetContext()->variable_set().MakeTaskDTO();
    auto task = task_dto->task();

    return task_dto.has_value()
        and task.IsInitialized()
        and task_dto->id().IsInitialized();
}

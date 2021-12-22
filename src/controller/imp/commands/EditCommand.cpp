//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Model::Response EditCommand::Execute(const std::shared_ptr<View> &view)
{
    auto task_struct = view->GetTaskStruct();

    auto id = task_struct->id();
    auto task = task_struct->task();

    if(task_struct->has_parent_id())
        return GetModel()->EditSubTask(id, task, task_struct->parent_id());
    else
        return GetModel()->Edit(id, task);
}
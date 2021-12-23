//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Model::Response AddCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto task_struct = view->GetTaskStruct();
    auto task = task_struct->task();

    if (task_struct->has_parent_id())
        return model->AddSubTask(task, task_struct->parent_id());
    else
        return model->Add(task);
}
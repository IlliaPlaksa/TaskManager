//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response AddCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto task_struct = view->GetTaskStruct();

    auto task = task_struct->task();
    auto parent_id = TaskId{};

    auto model_response = Response{};

    if (task_struct->has_parent_id())
        model_response = GetModel()->AddSubTask(task, parent_id);
    else
        model_response =  GetModel()->Add(task);

    return model_response;
}
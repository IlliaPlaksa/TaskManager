//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response EditCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto result = Response{};

    auto task_struct = view->GetTaskStruct();
    auto id = task_struct->GetId();
    auto parent_id = task_struct->GetParent();
    auto task = task_struct->ConstructTask();

    try
    {
        GetModel()->Edit(id, task, parent_id);
        result.status = Response::Status::kSuccess;
    }
    catch (const std::exception &e)
    {
        result.status = Response::Status::kError;
        result.error_message = e.what();
    }
    return result;
}
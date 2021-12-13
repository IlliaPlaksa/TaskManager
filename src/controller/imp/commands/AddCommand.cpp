//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response AddCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto result = Response{};

    auto task_struct = view->GetTaskStruct();

    auto task = task_struct->ConstructTask();
    auto parent_id = task_struct->GetParent();

    try
    {
        if (GetModel()->AddSubTask(task, parent_id).value())
            result.status = Response::Status::kSuccess;
        else
            result.status = Response::Status::kError;
    }
    catch (const std::exception &e)
    {
        result.status = Response::Status::kError;
        result.error_message = e.what();
    }

    return result;
}
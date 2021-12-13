//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response DeleteCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto result = Response{};

    auto task_struct = view->GetTaskStruct();

    try
    {
        GetModel()->Delete(task_struct->GetId());
        result.status =  Response::Status::kSuccess;
    }
    catch (const std::exception &e)
    {
        result.status = Response::Status::kError;
        result.error_message = e.what();
    }
    return result;
}
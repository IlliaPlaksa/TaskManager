//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response AddCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto result = Response{};

    // Command code here
    auto task_struct = view->GetTaskStruct();

    GetModel()->Add(task_struct->ConstructTask());

    result.status = Response::Status::kSuccess;
    return result;
}
//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response CompleteCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto task_struct = view->GetTaskStruct();
    return GetModel()->Complete(task_struct->id());;
}
//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Model::Response DeleteCommand::Execute(const std::shared_ptr<View> &view)
{
    auto task_struct = view->GetTaskStruct();
    return GetModel()->Delete(task_struct->id());;
}
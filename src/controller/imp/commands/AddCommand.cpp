//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Command::Response AddCommand::Execute(const std::shared_ptr<IModel> &model)
{
    auto result = Command::Response{};

    // Command code here
    auto view = this->GetView();
    auto task_struct = view->GetTaskStruct();

    model->Add(task_struct->ConstructTask());

    result.status = Command::Response::Status::kSuccess;
    return result;
}
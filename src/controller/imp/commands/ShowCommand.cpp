//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Command::Response ShowCommand::Execute(const std::shared_ptr<IModel> &model)
{
    auto result = Command::Response{};

    // Command code here

    result.status = Command::Response::Status::kSuccess;
    return result;
}
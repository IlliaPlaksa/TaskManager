//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response ShowCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto result = Response{};

    // Command code here

    result.status = Response::Status::kSuccess;
    return result;
}
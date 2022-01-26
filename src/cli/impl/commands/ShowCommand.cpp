//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/include/ConcreteCommands.h"

CommandResponse ShowCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};
    result.tasks = model->Show();

    return result;
}

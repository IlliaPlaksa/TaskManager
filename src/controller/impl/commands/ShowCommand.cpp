//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

CommandResponse ShowCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto result = CommandResponse{};
    result.tasks = model->Show();

    return result;
}

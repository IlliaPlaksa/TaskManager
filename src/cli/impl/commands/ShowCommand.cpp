//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/include/ConcreteCommands.h"

ShowCommand::ShowCommand(const std::optional<std::string>& label)
    :
    label_(label)
{
}

CommandResponse ShowCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};

    if (label_.has_value())
    {
        result.tasks->LoadRootTasks(model->ShowTasksWithLabel(label_.value()));
    } else
        result.tasks->LoadTasks(model->Show());

    return result;
}

//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/include/ConcreteCommands.h"
#include "util/TaskId/TaskIdComparators.h"

ShowCommand::ShowCommand(const std::optional<std::string>& label)
    :
    label_(label)
{
}

CommandResponse ShowCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};
    auto storage = TaskStorage{};

    if (label_.has_value())
    {
        storage.LoadRootTasks(model->ShowTasksWithLabel(label_.value()));
    } else
        storage.LoadTasks(model->Show());

    result.tasks = storage;

    return result;
}

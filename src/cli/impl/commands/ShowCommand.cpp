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
        BOOST_LOG_TRIVIAL(info) << "Called Show by label command with label: " << label_.value() <<".";

        auto tasks = model->ShowTasksWithLabel(label_.value());

        BOOST_LOG_TRIVIAL(info) << "Show by label command received " << tasks.size() << " tasks.";

        storage.LoadRootTasks(tasks);
    }
    else
    {
        BOOST_LOG_TRIVIAL(info) << "Called Show command.";

        auto tasks = model->Show();

        BOOST_LOG_TRIVIAL(info) << "Show command received " << tasks.size() << " tasks.";

        storage.LoadTasks(tasks);
    }

    result.tasks = storage;

    return result;
}

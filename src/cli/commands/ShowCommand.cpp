//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/ConcreteCommands.h"
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
        BOOST_LOG_TRIVIAL(debug) << "Called Show by label command with label: " << label_.value() << ".";

        auto tasks = model->ShowTasksWithLabel(label_.value());

        BOOST_LOG_TRIVIAL(debug) << "Show by label command received " << tasks.size() << " tasks.";

        storage.LoadRootTasks(tasks);
    }
    else
    {
        BOOST_LOG_TRIVIAL(debug) << "Called Show command with no parameters.";

        auto tasks = model->Show();

        BOOST_LOG_TRIVIAL(debug) << "Show command received " << tasks.size() << " tasks.";

        storage.LoadTasks(tasks);
    }

    result.tasks = storage;

    return result;
}

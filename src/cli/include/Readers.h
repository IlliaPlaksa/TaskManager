//
// Created by Illia Plaksa on 29.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_

#include <string>
#include <ctime>
#include <optional>
#include "TaskId.pb.h"
#include "Validators.h"
#include "ConsoleManipulator.h"

enum class StepId;

namespace Read
{
    StepId Command(const std::shared_ptr<ConsoleManipulator>& console);
    std::string Title(const std::shared_ptr<ConsoleManipulator>& console);
    TaskId Id(const std::shared_ptr<ConsoleManipulator>& console);
    std::optional<TaskId> ParentId(const std::shared_ptr<ConsoleManipulator>& console);
    Task::Priority Priority(const std::shared_ptr<ConsoleManipulator>& console);
    time_t Date(const std::shared_ptr<ConsoleManipulator>& console);
    std::optional<std::string> Label(const std::shared_ptr<ConsoleManipulator>& console);
    bool Confirm(const std::shared_ptr<ConsoleManipulator>& console);
}

#endif //TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_

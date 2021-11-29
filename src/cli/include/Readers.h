//
// Created by Illia Plaksa on 29.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_

#include <string>
#include <ctime>
#include <optional>
#include "../../model/include/TaskId.h"
#include "Validators.h"
#include "ConsoleManipulator.h"

namespace Read
{
    std::optional<std::string> Title(const ConsoleManipulator &console);
    std::optional<TaskId> Id(const ConsoleManipulator &console);
    std::optional<Task::Priority> Priority(const ConsoleManipulator &console);
    std::optional<time_t> Date(const ConsoleManipulator &console);
    std::optional<std::string> Label(const ConsoleManipulator &console);
    std::optional<bool> Confirm(const ConsoleManipulator &console);
}

#endif //TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_

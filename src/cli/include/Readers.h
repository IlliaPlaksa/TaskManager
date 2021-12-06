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

enum class StepId;

namespace Read
{
    StepId Command(const ConsoleManipulator &console);
    std::string Title(const ConsoleManipulator &console);
    TaskId Id(const ConsoleManipulator &console);
    Task::Priority Priority(const ConsoleManipulator &console);
    time_t Date(const ConsoleManipulator &console);
    std::string Label(const ConsoleManipulator &console);
    bool Confirm(const ConsoleManipulator &console);
}

#endif //TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_

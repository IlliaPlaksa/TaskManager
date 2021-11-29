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
    std::optional<std::string> Title(const std::shared_ptr<ConsoleManipulator>& console_manipulator);
    std::optional<TaskId> Id(const std::shared_ptr<ConsoleManipulator>& console_manipulator);
    std::optional<time_t> Date(const std::shared_ptr<ConsoleManipulator>& console_manipulator);
}

#endif //TASKMANAGER_SRC_CLI_INCLUDE_READERS_H_

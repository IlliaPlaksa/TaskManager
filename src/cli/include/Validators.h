//
// Created by Illia Plaksa on 29.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_VALIDATORS_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_VALIDATORS_H_

#include <string>
#include <optional>
#include <ctime>
#include "../../model/include/TaskId.h"

namespace Validate
{
    std::optional<std::string> Title(const std::string& title);
    std::optional<TaskId> Id(const std::string& id);
    std::optional<time_t> Date(const std::string& date);
}

#endif //TASKMANAGER_SRC_CLI_INCLUDE_VALIDATORS_H_

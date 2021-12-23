//
// Created by Illia Plaksa on 29.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_VALIDATORS_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_VALIDATORS_H_

#include <string>
#include <optional>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "StepId.h"
#include "TaskId.pb.h"
#include "Task.pb.h"

namespace Validate
{
    std::optional<StepId> Command(const std::string& command);
    std::optional<std::string> Title(const std::string &title);
    std::optional<TaskId> Id(const std::string &id);
    std::optional<Task::Priority> Priority(const std::string &priority);
    std::optional<time_t> Date(const std::string &date);
    std::optional<std::string> Label(const std::string &label);
    std::optional<bool> Confirm(const std::string &symbol);
}

#endif //TASKMANAGER_SRC_CLI_INCLUDE_VALIDATORS_H_

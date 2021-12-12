//
// Created by Illia Plaksa on 12.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_RESPONSE_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_RESPONSE_H_

#include <optional>
#include <string>
#include "TaskStorage.h"

struct Response
{
    enum class Status
    {
        kSuccess,
        kError
    };
    // TODO add more information
    Status status;
    std::optional<std::string> error_message;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_RESPONSE_H_

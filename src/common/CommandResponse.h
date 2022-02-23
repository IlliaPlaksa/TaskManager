//
// Created by Illia Plaksa on 16.01.2022.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_COMMANDRESPONSE_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_COMMANDRESPONSE_H_

#include "TaskDTO.pb.h"
#include "ModelResponse.h"
#include "cli/TaskStorage.h"

class CommandResponse
{
public:
    CommandResponse();

public:
    std::optional<ModelResponse> model_response;
    std::optional<TaskStorage> tasks;

public:
    bool IsError() const;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_COMMANDRESPONSE_H_

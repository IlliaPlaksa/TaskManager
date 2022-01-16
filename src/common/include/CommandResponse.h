//
// Created by Illia Plaksa on 16.01.2022.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_COMMANDRESPONSE_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_COMMANDRESPONSE_H_

#include "ModelResponse.h"

class CommandResponse
{
public:
    CommandResponse();

public:
    std::optional<ModelResponse> model_response;
    std::optional<std::vector<TaskDTO>> tasks;

public:
    bool IsError() const;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_COMMANDRESPONSE_H_

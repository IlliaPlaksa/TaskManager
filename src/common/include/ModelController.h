//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_
#define TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "common/include/Model.h"

class ModelController : public Model
{
public:
    virtual ModelResponse LoadFromFile(const std::string& file_name) = 0;
    virtual ModelResponse SaveToFile(const std::string& file_name) = 0;
};
#endif //TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

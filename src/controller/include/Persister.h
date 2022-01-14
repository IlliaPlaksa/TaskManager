//
// Created by Illia Plaksa on 14.01.2022.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_PERSISTER_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_PERSISTER_H_

#include "TaskDTO.pb.h"

class TaskPersister
{
public:
    virtual bool Save(const std::vector<TaskDTO>& tasks) = 0;
    virtual std::optional<std::vector<TaskDTO>> Load() = 0;
public:
    virtual ~TaskPersister() = default;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_PERSISTER_H_

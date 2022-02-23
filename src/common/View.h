//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_

#include <optional>
#include "TaskDTO.pb.h"
#include "cli/TaskStorage.h"

class View
{
public:
    virtual void Run() = 0;
public:
    virtual ~View() = default;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_

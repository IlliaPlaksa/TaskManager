//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_IVIEW_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_IVIEW_H_

#include <optional>
#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"

class IView
{
public:
    virtual void Run() = 0;
public:
    virtual std::optional<Task> GetTask() const = 0;
    virtual std::optional<TaskId> GetTaskId() const = 0;
    virtual std::optional<TaskId> GetParentTaskId() const = 0;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_IVIEW_H_

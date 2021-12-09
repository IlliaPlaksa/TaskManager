//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_IMODEL_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_IMODEL_H_

#include <vector>
#include <optional>

#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"

class IModel
{
public:
    virtual TaskId Add(const Task &task) = 0;
    virtual TaskId AddSubTask(const Task &task, const TaskId &parent_id) = 0;
    virtual void Edit(const TaskId &task_id, const Task &task, const TaskId &parent_id) = 0;
    virtual void Complete(const TaskId &task_id) = 0;
    virtual void Delete(const TaskId &task_id) = 0;

public:
    virtual std::vector<std::pair<TaskId, Task>> Show() = 0;
    virtual std::vector<std::pair<TaskId, Task>> ShowParents() = 0;
    virtual std::vector<std::pair<TaskId, Task>> ShowChild(TaskId parent_id) = 0;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_IMODEL_H_

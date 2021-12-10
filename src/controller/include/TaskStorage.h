//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_
#define TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

#include <vector>
#include <map>
#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"

class TaskStorage
{
    using TaskVect = std::vector<std::pair<TaskId, Task>>;
public:
    std::vector<TaskId> GetParentIds();
    TaskVect GetTasksByParentId(const TaskId &parent_id);

public:
    void Add(const TaskId &parent_id, const TaskVect &vect);
private:
    std::map<TaskId, TaskVect> storage_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

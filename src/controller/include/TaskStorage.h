//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_
#define TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

#include <vector>
#include <map>
#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"
#include "../../model/include/TaskToSerialize.h"

class TaskStorage
{
public:
    std::vector<TaskId> GetParentIds();
    std::vector<TaskToSerialize> GetTasksByParentId(const TaskId &parent_id);

public:
    void Add(const TaskId &parent_id, const std::vector<TaskToSerialize> &vect);
private:
    std::map<TaskId, std::vector<TaskToSerialize>> storage_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

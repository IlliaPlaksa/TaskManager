//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_
#define TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

#include <vector>
#include <map>
#include "Response.h"
#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"
#include "../../model/include/TaskToSerialize.h"

class TaskStorage
{
public:
    std::vector<TaskToSerialize> GetRootTasks();
    std::vector<TaskToSerialize> GetSubTasks(const TaskId &parent_id);
public:
    Response LoadRootTasks(const std::vector<TaskToSerialize>& tasks);
    Response LoadSubTasks(const TaskId &parent_id, const std::vector<TaskToSerialize>& tasks);
private:
    std::vector<TaskToSerialize> root_storage_;
    std::map<TaskId, std::vector<TaskToSerialize>> subtask_storage_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_
#define TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

#include <vector>
#include <map>
#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskToSerialize.pb.h"

class TaskStorage
{
public:
    std::vector<TaskToSerialize> GetRootTasks() const;
    std::vector<TaskToSerialize> GetSubTasks(const TaskId &parent_id) const;
public:
    void LoadRootTasks(const std::vector<TaskToSerialize>& tasks);
    void LoadSubTasks(const TaskId &parent_id, const std::vector<TaskToSerialize>& tasks);
private:
    std::vector<TaskToSerialize> root_storage_;
    std::map<TaskId, std::vector<TaskToSerialize>> subtask_storage_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

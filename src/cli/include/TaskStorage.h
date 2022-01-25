//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_
#define TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

#include <vector>
#include <map>
#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskDTO.pb.h"

class TaskStorage
{
public:
    std::vector<TaskDTO> GetTasks() const;
    std::vector<TaskDTO> GetRootTasks() const;
    std::vector<TaskDTO> GetSubTasks(const TaskId& parent_id) const;
public:
    void LoadTasks(const std::vector<TaskDTO>& tasks);
    void LoadRootTasks(const std::vector<TaskDTO>& tasks);
    void Clear();
private:
    std::vector<TaskDTO> root_storage_;
    std::map<TaskId, std::vector<TaskDTO>> subtask_storage_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_TASKSTORAGE_H_

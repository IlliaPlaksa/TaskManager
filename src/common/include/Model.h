//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_

#include <vector>
#include <optional>

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskDTO.pb.h"

#include "ModelResponse.h"

class Model
{
public:
    virtual ModelResponse Add(const Task& task) = 0;
    virtual ModelResponse AddSubTask(const Task& task, const TaskId& parent_id) = 0;
    virtual ModelResponse Edit(const TaskId& task_id, const Task& task) = 0;
    virtual ModelResponse EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id) = 0;
    virtual ModelResponse Complete(const TaskId& task_id) = 0;
    virtual ModelResponse Delete(const TaskId& task_id) = 0;

public:
    virtual std::vector<TaskDTO> Show() = 0;
    virtual std::vector<TaskDTO> ShowParents() = 0;
    virtual std::vector<TaskDTO> ShowChild(const TaskId& parent_id) = 0;
    virtual std::vector<TaskDTO> ShowTasksWithLabel(const std::string& label) = 0;

public:
    virtual ModelResponse Load(const std::vector<TaskDTO>& tasks) = 0;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_

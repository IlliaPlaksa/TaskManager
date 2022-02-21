//
// Created by Illia Plaksa on 19.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_FAMILYTASK_H_
#define TASKMANAGER_SRC_MODEL_FAMILYTASK_H_

#include "Task.pb.h"
#include "TaskId.pb.h"

#include <optional>

class TaskNode
{
public:
    static TaskNode Create(const Task& task);
    static TaskNode Create(const Task& task, const TaskId& parent_id);

public:
    std::optional<TaskId> GetParentId() const;
    Task GetTask() const;
public:
    TaskNode(const TaskNode& task) = default;
private:
    explicit TaskNode(const Task& task);
    TaskNode(const Task& task, const TaskId& parent_id);

private:
    Task task_;
    std::optional<TaskId> parent_id_;
};

#endif //TASKMANAGER_SRC_MODEL_FAMILYTASK_H_

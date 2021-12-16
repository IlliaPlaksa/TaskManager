//
// Created by Illia Plaksa on 16.12.2021.
//

#ifndef TASKMANAGER_UTILS_INCLUDE_TASKSTRUCTURESCREATE_H_
#define TASKMANAGER_UTILS_INCLUDE_TASKSTRUCTURESCREATE_H_

#include <optional>
#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskToSerialize.pb.h"

std::optional<TaskToSerialize> CreateTaskToSerialize(const TaskId &id,
                                                     const Task &task);

std::optional<TaskToSerialize> CreateSubTaskToSerialize(const TaskId &id,
                                                        const Task &task,
                                                        const TaskId &parent_id);

std::optional<Task> CreateTask(const std::string &title,
                               const std::time_t &due_to_date,
                               const Task_Priority &priority,
                               const std::string &label = "",
                               const Task_Status &status = Task_Status_kInProgress);

std::optional<TaskId> CreateTaskId(const google::protobuf::uint64 &value);

#endif //TASKMANAGER_UTILS_INCLUDE_TASKSTRUCTURESCREATE_H_

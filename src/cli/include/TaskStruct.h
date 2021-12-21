//
// Created by Illia Plaksa on 20.12.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_TASKSTRUCT_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_TASKSTRUCT_H_

#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"
#include "../../model/include/TaskToSerialize.h"

class TaskStruct
{
public:
    TaskStruct() = default;

public: // Setters
    TaskStruct &SetTitle(const std::string &title);
    TaskStruct &SetDate(const time_t &date);
    TaskStruct &SetPriority(const Task::Priority &priority);
    TaskStruct &SetLabel(const std::string &label);
    TaskStruct &SetStatus(const Task::Status &status);
    TaskStruct &SetParent(const TaskId &parent_id);
    TaskStruct &SetId(const TaskId &id);

public:
    void Reset();
    bool IsReady();

public:
    std::optional<TaskId> id();
    std::optional<Task> task();
    std::optional<TaskId> parent_id();
    std::optional<TaskToSerialize> MakeTaskToSerialize();

private:
    TaskId id_;
    Task task_;
    std::optional<TaskId> parent_id_;
};

#endif //TASKMANAGER_SRC_CLI_INCLUDE_TASKSTRUCT_H_

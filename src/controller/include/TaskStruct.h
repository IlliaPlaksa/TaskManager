//
// Created by Illia Plaksa on 26.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_TASKSTRUCT_H_
#define TASKMANAGER_SRC_CLI_TASKSTRUCT_H_

#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"

class TaskStruct
{
public:
    void Reset();
    bool IsReadyToConstruct() const;

public:
    Task ConstructTask() const;
    TaskId GetParent() const;
    TaskId GetId() const;

public:
    TaskStruct &SetTitle(const std::string &title);
    TaskStruct &SetPriority(const Task::Priority &priority);
    TaskStruct &SetDate(const std::time_t &date);
    TaskStruct &SetLabel(const std::string &label);
    TaskStruct &SetStatus(const Task::Status &status);

    TaskStruct &SetParent(const TaskId& parent_id);
    TaskStruct &SetId(const TaskId& id);

    TaskStruct& SetFromTask(const Task &task);

public:
    TaskStruct();
private:
    std::string title_;
    Task::Priority priority_;
    std::time_t due_to_date_;
    std::string label_;
    Task::Status status_;

    TaskId parent_id_;
    TaskId id_;
};

#endif //TASKMANAGER_SRC_CLI_TASKSTRUCT_H_

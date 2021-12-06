//
// Created by Illia Plaksa on 26.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_TASKSTRUCT_H_
#define TASKMANAGER_SRC_CLI_TASKSTRUCT_H_

#include "../../model/include/Task.h"

class TaskStruct
{
public:
    Task ConstructTask() const;
    void Reset();
    bool IsReadyToConstruct() const;

public:
    TaskStruct &SetTitle(const std::string &title);
    TaskStruct &SetPriority(const Task::Priority &priority);
    TaskStruct &SetDate(const std::time_t &date);
    TaskStruct &SetLabel(const std::string &label);
    TaskStruct &SetStatus(const Task::Status &status);

    TaskStruct& SetFromTask(const Task &task);

private:
    std::string title_;
    Task::Priority priority_;
    std::time_t due_to_date_;
    std::string label_;
    Task::Status status_;
};

#endif //TASKMANAGER_SRC_CLI_TASKSTRUCT_H_

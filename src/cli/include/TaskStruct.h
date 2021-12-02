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
    void SetTitle(const std::string &title);
    void SetPriority(const Task::Priority &priority);
    void SetDate(const std::time_t &date);
    void SetLabel(const std::string &label);
    void SetStatus(const Task::Status &status);

    void SetFromTask(const Task &task);

private:
    std::string title_;
    Task::Priority priority_;
    std::time_t due_to_date_;
    std::string label_;
    Task::Status status_;
};

#endif //TASKMANAGER_SRC_CLI_TASKSTRUCT_H_

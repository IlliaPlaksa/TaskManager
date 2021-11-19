//
// Created by Illia Plaksa on 19.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_FAMILYTASK_H_
#define TASKMANAGER_SRC_MODEL_FAMILYTASK_H_

#include "Task.h"
#include "TaskId.h"

class FamilyTask : public Task
{
public:
    static FamilyTask Create(const Task &task, TaskId parent_id);
    static FamilyTask Create(const std::string &title,
                             const std::time_t &due_to_date,
                             const Priority &priority,
                             const std::string &label = "",
                             TaskId parent_id = TaskId::CreateDefault());
public:
    TaskId GetParentId() const;
public:
    FamilyTask(const FamilyTask &task) = default;
private:
    FamilyTask(const Task &task, TaskId parent_id);

private:
    TaskId parent_id_;
};

#endif //TASKMANAGER_SRC_MODEL_FAMILYTASK_H_

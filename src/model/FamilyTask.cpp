//
// Created by Illia Plaksa on 19.11.2021.
//

#include "FamilyTask.h"

FamilyTask FamilyTask::Create(const Task &task, TaskId parent_id)
{
    return FamilyTask{task, parent_id};
}

FamilyTask FamilyTask::Create(const std::string &title,
                              const std::time_t &due_to_date,
                              const Priority &priority,
                              const std::string &label,
                              TaskId parent_id)
{
    auto task = Task::Create(title, due_to_date, priority, label);
    return FamilyTask{task, parent_id};
}

TaskId FamilyTask::GetParentId() const
{
    return this->parent_id_;
}

FamilyTask::FamilyTask(const Task &task, TaskId parent_id)
    :
    Task(task),
    parent_id_(parent_id) {}

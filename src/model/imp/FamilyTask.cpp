//
// Created by Illia Plaksa on 19.11.2021.
//

#include "../headers/FamilyTask.h"

FamilyTask FamilyTask::Create(const Task &task, TaskId parent_id)
{
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

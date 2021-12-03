//
// Created by Illia Plaksa on 19.11.2021.
//

#include "../include/FamilyTask.h"

FamilyTask FamilyTask::Create(const Task &task, TaskId parent_id)
{
    return FamilyTask{task, parent_id};
}

TaskId FamilyTask::GetParentId() const
{
    return this->parent_id_;
}
Task FamilyTask::GetTask() const
{
    return this->task_;
}
FamilyTask::FamilyTask(const Task &task, const TaskId &parent_id)
    :
    task_(task),
    parent_id_(parent_id) {}


//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../include/TaskManager.h"

TaskManager::TaskManager(std::unique_ptr<IdGenerator> generator)
    : gen_{std::move(generator)} {}

TaskId TaskManager::Add(const Task &task, const TaskId &parent_id)
{
    TaskId new_id = this->gen_->GetNextId();
    if (this->tasks_.count(new_id))
        throw std::runtime_error("Generator returns non-identical ID");

    this->tasks_.insert(
        std::make_pair(new_id,
                       FamilyTask::Create(task, parent_id)));
    return new_id;
}

void TaskManager::Edit(const TaskId &id,
                       const Task &task,
                       const TaskId &parent_id)
{
    if (this->tasks_.find(id) != this->tasks_.end())
        this->tasks_.at(id) = FamilyTask::Create(task, parent_id);
    else
        throw std::runtime_error("Invalid id passed");
}

void TaskManager::Delete(const TaskId &id)
{
    this->tasks_.erase(id);
}

void TaskManager::Complete(const TaskId &id)
{
    if (this->tasks_.find(id) != this->tasks_.end())
    {
        auto &task = this->tasks_.at(id);
        task = FamilyTask::Create(Task::Complete(task.GetTask()), task.GetParentId());
    } else
        throw std::runtime_error("Invalid id passed");
}

std::vector<std::pair<TaskId, Task>> TaskManager::Show()
{
    auto result = std::vector<std::pair<TaskId, Task>>{};
    for (const auto &elem: this->tasks_)
        result.emplace_back(std::make_pair(elem.first,
                                           elem.second.GetTask()));

    return result;
}
std::vector<std::pair<TaskId, Task>> TaskManager::ShowParents()
{
    auto result = std::vector<std::pair<TaskId, Task>>{};
    for (const auto &elem: this->tasks_)
    {
        if (elem.second.GetParentId() == TaskId::CreateDefault())
            result.emplace_back(std::make_pair(elem.first,
                                               elem.second.GetTask()));
    }
    return result;
}
std::vector<std::pair<TaskId, Task>> TaskManager::ShowChild(TaskId parent_id)
{
    auto result = std::vector<std::pair<TaskId, Task>>{};
    for (const auto &elem: this->tasks_)
    {
        if (elem.second.GetParentId() == parent_id)
            result.emplace_back(std::make_pair(elem.first,
                                               elem.second.GetTask()));
    }
    return result;
}


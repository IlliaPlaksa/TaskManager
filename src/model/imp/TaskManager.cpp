//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../headers/TaskManager.h"

TaskManager::TaskManager(std::unique_ptr<IdGenerator> generator)
    : gen_{std::move(generator)} {}

TaskId TaskManager::Add(const FamilyTask &task)
{
    TaskId new_id = this->gen_->GetNextId();
    if (!this->tasks_.count(new_id))
        this->tasks_.insert(
            std::make_pair(new_id, task)
        );
    else
        throw std::runtime_error("Generator returns non-identical ID");

    return new_id;
}

void TaskManager::Edit(TaskId id, const FamilyTask &task)
{
    if (this->tasks_.find(id) != this->tasks_.end())
        this->tasks_.at(id) = task;
    else
        throw std::runtime_error("Invalid id passed");
}

void TaskManager::Delete(TaskId id)
{
    this->tasks_.erase(id);
}

void TaskManager::Complete(TaskId id)
{
    if (this->tasks_.find(id) != this->tasks_.end())
        this->tasks_.erase(id);
    else
        throw std::runtime_error("Invalid id passed");
}

std::vector<std::pair<TaskId, FamilyTask>> TaskManager::Show()
{
    auto result = std::vector<std::pair<TaskId, FamilyTask>>{};
    for (auto elem: this->tasks_)
        result.emplace_back(elem);

    return result;
}
std::vector<std::pair<TaskId, FamilyTask>> TaskManager::ShowParents()
{
    auto result = std::vector<std::pair<TaskId, FamilyTask>>{};
    for (auto elem: this->tasks_)
    {
        if(elem.second.GetParentId() == TaskId::CreateDefault())
            result.emplace_back(elem);
    }
    return result;
}
std::vector<std::pair<TaskId, FamilyTask>> TaskManager::ShowChild(TaskId parent_id)
{
    auto result = std::vector<std::pair<TaskId, FamilyTask>>{};
    for(auto elem : this->tasks_)
    {
        if(elem.second.GetParentId() == parent_id)
            result.emplace_back(elem);
    }
    return result;
}
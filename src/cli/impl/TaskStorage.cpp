//
// Created by Illia Plaksa on 10.12.2021.
//

#include "cli/include/TaskStorage.h"
#include "util/TaskId/TaskIdComparators.h"

std::vector<TaskDTO> TaskStorage::GetRootTasks() const
{
    return this->root_storage_;
}
std::vector<TaskDTO> TaskStorage::GetSubTasks(const TaskId& parent_id) const
{
    auto result = std::vector<TaskDTO>{};

    auto iter = subtask_storage_.find(parent_id);
    if (iter != subtask_storage_.end())
        result = iter->second;

    return result;
}
void TaskStorage::LoadTasks(const std::vector<TaskDTO>& tasks)
{
    for (const auto& task : tasks)
    {
        if (!task.has_parent_id())
            this->root_storage_.emplace_back(task);
        else
            this->subtask_storage_[task.parent_id()].emplace_back(task);
    }
}
std::vector<TaskDTO> TaskStorage::GetTasks() const
{
    auto result = std::vector<TaskDTO>{root_storage_};

    for (auto elem : subtask_storage_)
    {
        result.insert(result.end(), elem.second.begin(), elem.second.end());
    }

    return result;
}
void TaskStorage::Clear()
{
    root_storage_.clear();
    subtask_storage_.clear();
}
void TaskStorage::LoadRootTasks(const std::vector<TaskDTO>& tasks)
{
    for (const auto& task : tasks)
        this->root_storage_.emplace_back(task);
}


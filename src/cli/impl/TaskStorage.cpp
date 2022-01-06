//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/TaskStorage.h"
#include "../../util/TaskIdComparers.h"

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


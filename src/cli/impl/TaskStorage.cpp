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

    auto iter = std::find_if(subtask_storage_.begin(),
                             subtask_storage_.end(),
                             [parent_id](const auto& elem)
                             {
                                 return elem.first == parent_id;
                             });

    if (iter != subtask_storage_.end())
        result = iter->second;

    return result;
}
void TaskStorage::LoadRootTasks(const std::vector<TaskDTO>& tasks)
{
    root_storage_.insert(root_storage_.end(), tasks.begin(), tasks.end());
}
void TaskStorage::LoadSubTasks(const TaskId& parent_id, const std::vector<TaskDTO>& tasks)
{
    auto iter = subtask_storage_.find(parent_id);
    if (iter != subtask_storage_.end())
        iter->second.insert(iter->second.end(), tasks.begin(), tasks.end());
    else
        subtask_storage_.insert(
            std::make_pair(parent_id, tasks)
        );
}


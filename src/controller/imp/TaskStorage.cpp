//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/TaskStorage.h"

std::vector<TaskToSerialize> TaskStorage::GetRootTasks()
{
    return this->root_storage_;
}
std::vector<TaskToSerialize> TaskStorage::GetSubTasks(const TaskId &parent_id)
{
    auto result = std::vector<TaskToSerialize>{};

    auto iter = std::find_if(subtask_storage_.begin(),
                             subtask_storage_.end(),
                             [parent_id](const auto &elem)
                             {
                                 return elem.first == parent_id;
                             });

    if (iter != subtask_storage_.end())
        result = iter->second;

    return result;
}
Response TaskStorage::LoadRootTasks(const std::vector<TaskToSerialize> &tasks)
{
    Response result;
    root_storage_.insert(root_storage_.end(), tasks.begin(), tasks.end());

    result = Response::CreateSuccess();
    return result;
}
Response TaskStorage::LoadSubTasks(const TaskId &parent_id, const std::vector<TaskToSerialize> &tasks)
{
    Response response;

    auto iter = subtask_storage_.find(parent_id);
    if (iter != subtask_storage_.end())
        iter->second.insert(iter->second.end(), tasks.begin(), tasks.end());
    else
        subtask_storage_.insert(
            std::make_pair(parent_id, tasks)
        );

    response = Response::CreateSuccess();
    return response;
}


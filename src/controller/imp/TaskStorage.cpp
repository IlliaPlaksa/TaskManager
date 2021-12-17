//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/TaskStorage.h"

std::vector<TaskId> TaskStorage::GetParentIds()
{
    auto result = std::vector<TaskId>{};

    for (const auto &elem: this->storage_)
        result.emplace_back(elem.first);

    return result;
}
std::vector<TaskToSerialize> TaskStorage::GetTasksByParentId(const TaskId &parent_id)
{
    return this->storage_.at(parent_id);
}
void TaskStorage::Add(const TaskId &parent_id, const std::vector<TaskToSerialize> &vect)
{
    this->storage_.insert({parent_id, vect});
}


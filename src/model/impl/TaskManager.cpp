//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../include/TaskManager.h"

#include "../../util/TaskComparers.h"
#include "../../util/TaskCreators.h"

#include "../../util/TaskIdComparers.h"
#include "../../util/TaskIdCreators.h"

#include "../../util/TaskDTOComparers.h"
#include "../../util/TaskDTOCreators.h"

TaskManager::TaskManager(std::unique_ptr<IdGenerator> generator)
    : gen_{std::move(generator)} {}

Model::Response TaskManager::Add(const Task& task)
{
    TaskId new_id = this->gen_->GetNextId();

    assert(this->tasks_.count(new_id) == 0);

    this->tasks_.insert(
        std::make_pair(new_id,
                       FamilyTask::Create(task)));
    return Model::Response::CreateSuccess();
}
Model::Response TaskManager::AddSubTask(const Task& task, const TaskId& parent_id)
{
    TaskId new_id = this->gen_->GetNextId();

    assert(this->tasks_.count(new_id) == 0);

    if (tasks_.find(parent_id) != tasks_.end())
        this->tasks_.insert(
            std::make_pair(new_id,
                           FamilyTask::Create(task, parent_id)));
    else
        return Model::Response::CreateError(Response::ErrorType::NON_EXISTING_PARENT_ID);

    return Model::Response::CreateSuccess();
}

Model::Response TaskManager::Edit(const TaskId& id, const Task& task)
{
    if (this->tasks_.find(id) != this->tasks_.end())
    {
        this->tasks_.at(id) = FamilyTask::Create(task);
        return Model::Response::CreateSuccess();
    } else
    {
        return Model::Response::CreateError(Response::ErrorType::INVALID_ID);
    }
}
Model::Response TaskManager::EditSubTask(const TaskId& id, const Task& task, const TaskId& parent_id)
{
    if (this->tasks_.find(id) != this->tasks_.end())
    {
        this->tasks_.at(id) = FamilyTask::Create(task, parent_id);
        return Model::Response::CreateSuccess();
    } else
    {
        return Model::Response::CreateError(Response::ErrorType::INVALID_ID);
    }
}

Model::Response TaskManager::Delete(const TaskId& id)
{
    auto elem_iter = tasks_.find(id);

    if (elem_iter != tasks_.end())
    {
        auto& task = elem_iter->second;
        // Find subtasks
        auto iter = std::find_if(tasks_.begin(), tasks_.end(),
                                 [task](const auto& elem)
                                 {
                                     auto parent = elem.second.GetParentId();
                                     if (parent)
                                         return task.GetParentId() == parent;
                                     else
                                         return false;
                                 });

        if (iter == tasks_.end())
        {
            tasks_.erase(iter, tasks_.end());
            tasks_.erase(id);
        }
    }
    else
        return Response::CreateError(Response::ErrorType::INVALID_ID);

    return Model::Response::CreateSuccess();
}
Model::Response TaskManager::Complete(const TaskId& id)
{
    if (this->tasks_.find(id) != this->tasks_.end())
    {
        auto& task = this->tasks_.at(id);

        // Find uncompleted subtasks
        auto count = std::count_if(tasks_.begin(), tasks_.end(),
                                   [task](const auto& elem)
                                   {
                                       auto parent = elem.second.GetParentId();
                                       if (parent)
                                           return task.GetParentId() == parent and
                                               task.GetTask().status() != Task_Status_kCompleted;
                                       else
                                           return false;
                                   });

        if (count) // Has uncompleted subtasks
            return Model::Response::CreateError(Response::ErrorType::SUBTASKS_IS_NOT_COMPLETED);

        auto new_task = task.GetTask();
        auto parent_id = task.GetParentId();

        new_task.set_status(Task_Status_kCompleted);

        if (parent_id.has_value())
            task = FamilyTask::Create(new_task, parent_id.value());
        else
            task = FamilyTask::Create(new_task);

        return Response::CreateSuccess();
    } else
        return Model::Response::CreateError(Response::ErrorType::INVALID_ID);
}

std::vector<TaskDTO> TaskManager::Show()
{
    auto result = std::vector<TaskDTO>{};
    for (const auto& elem : this->tasks_)
    {
        auto tmp = ConstructTaskDTO(elem.first, elem.second);
        if (tmp)
            result.emplace_back(tmp.value());
    }
    return result;
}
std::vector<TaskDTO> TaskManager::ShowParents()
{
    auto result = std::vector<TaskDTO>{};
    for (const auto& elem : this->tasks_)
    {
        if (!elem.second.GetParentId())
        {
            auto tmp = ConstructTaskDTO(elem.first, elem.second);
            if (tmp)
                result.emplace_back(tmp.value());
        }

    }
    return result;
}
std::vector<TaskDTO> TaskManager::ShowChild(const TaskId& parent_id)
{
    auto result = std::vector<TaskDTO>{};
    for (const auto& elem : this->tasks_)
    {
        if (elem.second.GetParentId() == parent_id)
        {
            auto tmp = ConstructTaskDTO(elem.first, elem.second);
            if (tmp)
                result.emplace_back(tmp.value());
        }
    }
    return result;
}

std::optional<TaskDTO> TaskManager::ConstructTaskDTO(const TaskId& id, const FamilyTask& task)
{
    std::optional<TaskDTO> tmp;
    if (task.GetParentId())
        tmp = CreateSubTaskDTO(id,
                               task.GetTask(),
                               *task.GetParentId());
    else
        tmp = CreateTaskDTO(id, task.GetTask());
    return tmp;
}
Model::Response TaskManager::Load(const std::vector<TaskDTO>& tasks)
{
    auto tmp_storage = std::map<TaskId, FamilyTask>{};
    for (const auto& elem : tasks)
    {
        auto tmp_task = elem.has_parent_id()
                        ? FamilyTask::Create(elem.task(), elem.parent_id())
                        : FamilyTask::Create(elem.task());
        tmp_storage.insert({elem.id(), tmp_task});
    }

    for (const auto& elem : tmp_storage)
    {
        auto parent_id = elem.second.GetParentId();

        if (parent_id.has_value())
        {
            if (tmp_storage.find(*parent_id) == tmp_storage.end())
                return Model::Response::CreateError(
                    Model::Response::ErrorType::FAIL
                );
            else if (*parent_id == elem.first)
                return Model::Response::CreateError(
                    Model::Response::ErrorType::FAIL
                );
        }
    }

    auto last_id = *CreateTaskId(tmp_storage.size());

    this->gen_->SetLastId(last_id);

    this->tasks_ = tmp_storage;
    return Model::Response::CreateSuccess();
}


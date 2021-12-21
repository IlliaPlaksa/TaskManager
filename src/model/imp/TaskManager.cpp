//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../include/TaskManager.h"

TaskManager::TaskManager(std::unique_ptr<IdGenerator> generator)
    : gen_{std::move(generator)} {}

Model::Response TaskManager::Add(const Task &task)
{
    TaskId new_id = this->gen_->GetNextId();

    assert(this->tasks_.count(new_id) == 0);

    this->tasks_.insert(
        std::make_pair(new_id,
                       FamilyTask::Create(task)));
    return Model::Response::CreateSuccess();
}

Model::Response TaskManager::AddSubTask(const Task &task, const TaskId &parent_id)
{
    TaskId new_id = this->gen_->GetNextId();

    assert(this->tasks_.count(new_id) == 0);

    this->tasks_.insert(
        std::make_pair(new_id,
                       FamilyTask::Create(task, parent_id)));
    return Model::Response::CreateSuccess();
}

Model::Response TaskManager::Edit(const TaskId &id, const Task &task)
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

Model::Response TaskManager::EditSubTask(const TaskId &id, const Task &task, const TaskId &parent_id)
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

Model::Response TaskManager::Delete(const TaskId &id)
{
    auto &task = tasks_.at(id);

    // Find subtasks
    auto iter = std::find_if(tasks_.begin(), tasks_.end(),
                             [task](const auto &elem)
                             {
                                 auto parent = elem.second.GetParentId();
                                 if (parent)
                                     return task.GetParentId() == parent;
                                 else
                                     return false;
                             });

    tasks_.erase(iter, tasks_.end());
    tasks_.erase(id);

    return Model::Response::CreateSuccess();
}

Model::Response TaskManager::Complete(const TaskId &id)
{
    if (this->tasks_.find(id) != this->tasks_.end())
    {
        auto &task = this->tasks_.at(id);

        // Find uncompleted subtasks
        auto count = std::count_if(tasks_.begin(), tasks_.end(),
                                   [task](const auto &elem)
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

        task.GetTask().set_status(Task_Status_kCompleted);
        return Response::CreateSuccess();
    } else
        return Model::Response::CreateError(Response::ErrorType::INVALID_ID);
}

std::vector<TaskToSerialize> TaskManager::Show()
{
    auto result = std::vector<TaskToSerialize>{};
    for (const auto &elem: this->tasks_)
    {
        auto tmp = ConstructTaskToSerialize(elem.first, elem.second);
        if (tmp)
            result.emplace_back(tmp.value());

    }
    return result;
}
std::vector<TaskToSerialize> TaskManager::ShowParents()
{
    auto result = std::vector<TaskToSerialize>{};
    for (const auto &elem: this->tasks_)
    {
        if (!elem.second.GetParentId())
        {
            auto tmp = ConstructTaskToSerialize(elem.first, elem.second);
            if (tmp)
                result.emplace_back(tmp.value());
        }

    }
    return result;
}
std::vector<TaskToSerialize> TaskManager::ShowChild(const TaskId &parent_id)
{
    auto result = std::vector<TaskToSerialize>{};
    for (const auto &elem: this->tasks_)
    {
        if (elem.second.GetParentId() == parent_id)
        {
            auto tmp = ConstructTaskToSerialize(elem.first, elem.second);
            if (tmp)
                result.emplace_back(tmp.value());
        }
    }
    return result;
}
std::optional<TaskToSerialize> TaskManager::ConstructTaskToSerialize(const TaskId &id, const FamilyTask &task)
{
    std::optional<TaskToSerialize> tmp;
    if (task.GetParentId())
        tmp = CreateSubTaskToSerialize(id,
                                       task.GetTask(),
                                       *task.GetParentId());
    else
        tmp = CreateTaskToSerialize(id, task.GetTask());
    return tmp;
}
bool TaskManager::Load(const std::vector<TaskToSerialize> &tasks)
{
    return false;
}


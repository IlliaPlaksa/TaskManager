//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../include/TaskManager.h"

TaskManager::TaskManager(std::unique_ptr<IdGenerator> generator)
    : gen_{std::move(generator)} {}

TaskManager::Response TaskManager::Add(const Task &task)
{
    auto result = Response{};

    TaskId new_id = this->gen_->GetNextId();
    if (this->tasks_.count(new_id))
    {
        result.SetErrorMessage("Generator returns non-identical ID");
        result.SetStatus(Response::Status::kError);
    } else
    {
        this->tasks_.insert(
            std::make_pair(new_id,
                           FamilyTask::Create(task)));
        result.SetStatus(Response::Status::kSuccess);
    }

    return result;
}

TaskManager::Response TaskManager::AddSubTask(const Task &task, const TaskId &parent_id)
{
    auto result = Response{};
    TaskId new_id = this->gen_->GetNextId();
    if (this->tasks_.count(new_id))
    {
        result.SetErrorMessage("Generator returns non-identical ID");
        result.SetStatus(Response::Status::kError);
    } else
    {
        this->tasks_.insert(
            std::make_pair(new_id,
                           FamilyTask::Create(task, parent_id)));
        result.SetStatus(Response::Status::kSuccess);
    }
    return result;
}

TaskManager::Response TaskManager::Edit(const TaskId &id,
                                        const Task &task,
                                        const TaskId &parent_id)
{
    auto result = Response{};

    if (this->tasks_.find(id) != this->tasks_.end())
    {
        this->tasks_.at(id) = FamilyTask::Create(task, parent_id);
        result.SetStatus(Response::Status::kSuccess);
    } else
    {
        result.SetErrorMessage("Invalid id passed");
        result.SetStatus(Response::Status::kError);
    }

    return result;
}

TaskManager::Response TaskManager::Delete(const TaskId &id)
{
    auto result = Response{};

    this->tasks_.erase(id);

    result.SetStatus(Response::Status::kSuccess);
    return result;
}

TaskManager::Response TaskManager::Complete(const TaskId &id)
{
    if (this->tasks_.find(id) != this->tasks_.end())
    {
        auto &task = this->tasks_.at(id);
        Task new_task = task.GetTask();
        new_task.set_status(Task_Status_kCompleted);

        task = FamilyTask::Create(new_task, *task.GetParentId());
    } else
        throw std::runtime_error("Invalid id passed");
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


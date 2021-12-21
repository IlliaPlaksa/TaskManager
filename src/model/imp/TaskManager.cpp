//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../include/TaskManager.h"

TaskManager::TaskManager(std::unique_ptr<IdGenerator> generator)
    : gen_{std::move(generator)} {}

Response TaskManager::Add(const Task &task)
{
    Response result;

    TaskId new_id = this->gen_->GetNextId();
    if (this->tasks_.count(new_id))
    {
        result = Response::CreateError("Generator returns non-identical ID");
    } else
    {
        this->tasks_.insert(
            std::make_pair(new_id,
                           FamilyTask::Create(task)));
        result = Response::CreateSuccess();
    }

    return result;
}

Response TaskManager::AddSubTask(const Task &task, const TaskId &parent_id)
{
    Response result;

    TaskId new_id = this->gen_->GetNextId();
    if (this->tasks_.count(new_id))
    {
        result = Response::CreateError("Generator returns non-identical ID");
    } else
    {
        this->tasks_.insert(
            std::make_pair(new_id,
                           FamilyTask::Create(task, parent_id)));
        result = Response::CreateSuccess();
    }
    return result;
}

Response TaskManager::Edit(const TaskId &id, const Task &task)
{
    auto result = Response{};

    if (this->tasks_.find(id) != this->tasks_.end())
    {
        this->tasks_.at(id) = FamilyTask::Create(task);
        result = Response::CreateSuccess();
    } else
    {
        result = Response::CreateError("Invalid id passed");
    }

    return result;
}

Response TaskManager::EditSubTask(const TaskId &id, const Task &task, const TaskId &parent_id)
{
    auto result = Response{};

    if (this->tasks_.find(id) != this->tasks_.end())
    {
        this->tasks_.at(id) = FamilyTask::Create(task, parent_id);
        result = Response::CreateSuccess();
    } else
    {
        result = Response::CreateError("Invalid id passed");
    }

    return result;
}

Response TaskManager::Delete(const TaskId &id)
{
    auto result = Response{};

    this->tasks_.erase(id);

    result = Response::CreateSuccess();
    return result;
}

Response TaskManager::Complete(const TaskId &id)
{
    Response result;

    if (this->tasks_.find(id) != this->tasks_.end())
    {
        auto &task = this->tasks_.at(id);

        auto iter = std::find_if(tasks_.begin(), tasks_.end(),
                                 [task](const auto &elem)
                                 {
                                     auto parent = elem.second.GetParentId();
                                     if (parent)
                                         return task.GetParentId() == parent;
                                     else
                                         return false;
                                 });
        while (iter != tasks_.end())
        {
            if (iter->second.GetTask().status() != Task_Status_kCompleted)
                result = Response::CreateError(
                    "Subtasks of Task with ID: "
                    + std::to_string(id.value())
                    + " isn't Completed"
                    );
        }
        task.GetTask().set_status(Task_Status_kCompleted);

    } else
        result = Response::CreateError("Invalid ID passed");

    return result;
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


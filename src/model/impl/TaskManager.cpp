//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../include/TaskManager.h"

#include "util/Task/TaskComparators.h"
#include "util/Task/TaskCreators.h"

#include "util/TaskId/TaskIdComparators.h"
#include "util/TaskId/TaskIdCreators.h"

#include "util/TaskDTO/TaskDTOComparators.h"
#include "util/TaskDTO/TaskDTOCreators.h"

TaskManager::TaskManager(std::unique_ptr<IdGenerator> generator)
    : gen_{std::move(generator)} {}

ModelResponse TaskManager::Add(const Task& task)
{
    TaskId new_id = gen_->GetNextId();

    tasks_.insert(
        std::make_pair(new_id, TaskNode::Create(task))
    );
    return ModelResponse::Success();
}
ModelResponse TaskManager::AddSubTask(const Task& task, const TaskId& parent_id)
{
    TaskId new_id = gen_->GetNextId();

    if (tasks_.find(parent_id) != tasks_.end())
    {
        tasks_.insert(
            std::make_pair(new_id, TaskNode::Create(task, parent_id))
        );
    }
    else
        return ModelResponse::Error(ModelResponse::ErrorType::NON_EXISTING_PARENT_ID);

    return ModelResponse::Success();
}

ModelResponse TaskManager::Edit(const TaskId& id, const Task& task)
{
    if (tasks_.find(id) != tasks_.end())
    {
        tasks_.at(id) = TaskNode::Create(task);
        return ModelResponse::Success();
    }
    else
    {
        return ModelResponse::Error(ModelResponse::ErrorType::INVALID_ID);
    }
}
ModelResponse TaskManager::EditSubTask(const TaskId& id, const Task& task, const TaskId& parent_id)
{
    auto tmp = tasks_.find(id);

    if (tmp != tasks_.end())
    {
        if (tasks_.find(parent_id) != tasks_.end())
        {
            tmp->second = TaskNode::Create(task, parent_id);
            return ModelResponse::Success();
        }
        else
            return ModelResponse::Error(ModelResponse::ErrorType::NON_EXISTING_PARENT_ID);
    }
    else
        return ModelResponse::Error(ModelResponse::ErrorType::INVALID_ID);
}

ModelResponse TaskManager::Delete(const TaskId& id)
{
    auto elem_iter = tasks_.find(id);

    if (elem_iter != tasks_.end())
    {
        auto& task = elem_iter->second;
        auto subtasks = FindSubTasks(id);

        if (!subtasks.empty())
        {
            for (auto iter: subtasks)
                tasks_.erase(iter);
        }
        tasks_.erase(id);
    }
    else
        return ModelResponse::Error(ModelResponse::ErrorType::INVALID_ID);

    return ModelResponse::Success();
}
ModelResponse TaskManager::Complete(const TaskId& id)
{
    auto task_iter = tasks_.find(id);

    if (task_iter != tasks_.end())
    {
        auto& task = task_iter->second;
        auto subtasks = FindSubTasks(id);

        auto is_uncompleted = [](const std::map<TaskId, TaskNode>::iterator& elem)
        {
            auto task_status = elem->second.GetTask().status();
            return task_status != Task_Status_kCompleted;
        };

        // Find uncompleted subtask
        auto has_uncompleted = std::find_if(subtasks.begin(), subtasks.end(), is_uncompleted);

        if (has_uncompleted != subtasks.end()) // Has uncompleted subtasks
            return ModelResponse::Error(ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS);

        auto new_task = task.GetTask();
        auto parent_id = task.GetParentId();

        new_task.set_status(Task_Status_kCompleted);

        if (parent_id.has_value())
            task = TaskNode::Create(new_task, parent_id.value());
        else
            task = TaskNode::Create(new_task);

        return ModelResponse::Success();
    }
    else
        return ModelResponse::Error(ModelResponse::ErrorType::INVALID_ID);
}

std::vector<TaskDTO> TaskManager::Show()
{
    auto result = std::vector<TaskDTO>{};
    for (const auto& elem: tasks_)
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
    for (const auto& elem: tasks_)
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
    for (const auto& elem: tasks_)
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
std::vector<TaskDTO> TaskManager::ShowTasksWithLabel(const std::string& label)
{
    auto result = std::vector<TaskDTO>{};

    for (const auto& elem: tasks_)
    {
        auto task = elem.second.GetTask();
        auto has_label = std::any_of(task.labels().cbegin(), task.labels().cend(),
                                     [&label](const auto& tmp_label)
                                     {
                                         return tmp_label == label;
                                     });
        if (has_label)
        {
            auto tmp = ConstructTaskDTO(elem.first, elem.second);
            if (tmp)
                result.emplace_back(tmp.value());
        }
    }

    return result;
}

std::optional<TaskDTO> TaskManager::ConstructTaskDTO(const TaskId& id, const TaskNode& task)
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
ModelResponse TaskManager::Load(const std::vector<TaskDTO>& tasks)
{
    auto tmp_storage = std::map<TaskId, TaskNode>{};
    for (const auto& elem: tasks)
    {
        auto tmp_task = elem.has_parent_id()
                        ? TaskNode::Create(elem.task(), elem.parent_id())
                        : TaskNode::Create(elem.task());
        tmp_storage.insert({elem.id(), tmp_task});
    }

    for (const auto& elem: tmp_storage)
    {
        auto parent_id = elem.second.GetParentId();

        if (parent_id.has_value())
        {
            if (tmp_storage.find(*parent_id) == tmp_storage.end()) // No task with such id found
                return ModelResponse::Error(
                    ModelResponse::ErrorType::FAIL
                );
            else if (*parent_id == elem.first) // parent id equals to task id
                return ModelResponse::Error(
                    ModelResponse::ErrorType::FAIL
                );
        }
    }

    auto last_id = *CreateTaskId(tmp_storage.size());
    gen_->SetLastId(last_id);
    tasks_ = tmp_storage;
    return ModelResponse::Success();
}
std::vector<std::map<TaskId, TaskNode>::iterator> TaskManager::FindSubTasks(const TaskId& parent_id)
{
    auto result = std::vector<std::map<TaskId, TaskNode>::iterator>{};

    for (auto iter = tasks_.begin() ; iter != tasks_.end() ; ++iter)
    {
        if (iter->second.GetParentId() == parent_id)
            result.emplace_back(iter);
    }
    return result;
}



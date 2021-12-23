//
// Created by Illia Plaksa on 17.12.2021.
//
#include "TaskToSerializeCreators.h"

std::optional<TaskToSerialize> CreateTaskToSerialize(const TaskId& id,
                                                     const Task& task)
{
    auto result = TaskToSerialize{};
    if (id.IsInitialized() and task.IsInitialized())
    {
        // Allocation of struct fields
        auto tmp_id = std::make_unique<TaskId>(id);
        auto tmp_task = std::make_unique<Task>(task);

        result.set_allocated_id(tmp_id.release());
        result.set_allocated_task(tmp_task.release());

    } else
        return std::nullopt;

    return result;
}

std::optional<TaskToSerialize> CreateSubTaskToSerialize(const TaskId& id,
                                                        const Task& task,
                                                        const TaskId& parent_id)
{
    auto result = CreateTaskToSerialize(id, task);
    if (result)
    {
        auto tmp_parent_id = std::make_unique<TaskId>(parent_id);
        result->set_allocated_parent_id(tmp_parent_id.release());
    } else
        return std::nullopt;

    return result;
}


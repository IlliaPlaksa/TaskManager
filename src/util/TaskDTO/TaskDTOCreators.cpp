//
// Created by Illia Plaksa on 17.12.2021.
//
#include "TaskDTOCreators.h"

std::optional<TaskDTO> CreateTaskDTO(const TaskId& id,
                                     const Task& task)
{
    auto result = TaskDTO{};

    // Allocation of struct fields
    auto tmp_id = std::make_unique<TaskId>(id);
    auto tmp_task = std::make_unique<Task>(task);

    result.set_allocated_id(tmp_id.release());
    result.set_allocated_task(tmp_task.release());

    return result;
}

std::optional<TaskDTO> CreateSubTaskDTO(const TaskId& id,
                                        const Task& task,
                                        const TaskId& parent_id)
{
    auto result = CreateTaskDTO(id, task);

    auto tmp_parent_id = std::make_unique<TaskId>(parent_id);
    result->set_allocated_parent_id(tmp_parent_id.release());

    return result;
}


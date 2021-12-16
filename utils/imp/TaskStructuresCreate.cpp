//
// Created by Illia Plaksa on 16.12.2021.
//

#include "../include/TaskStructuresCreate.h"

std::optional<TaskToSerialize> CreateTaskToSerialize(const TaskId &id,
                                                     const Task &task)
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

std::optional<TaskToSerialize> CreateSubTaskToSerialize(const TaskId &id,
                                                        const Task &task,
                                                        const TaskId &parent_id)
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

std::optional<Task> CreateTask(const std::string &title,
                               const std::time_t &due_to_date,
                               const Task_Priority &priority,
                               const std::string &label,
                               const Task_Status &status)
{
    auto result = Task{};
    if (!title.empty() and due_to_date >= 0)
    {
        result.set_title(title);
        result.set_status(status);
        result.set_label(label);

        auto tmp_date = std::make_unique<google::protobuf::Timestamp>();
        tmp_date->set_seconds(due_to_date);
        result.set_allocated_due_date(tmp_date.release());
    } else
        return std::nullopt;

    return result;
}

std::optional<TaskId> CreateTaskId(const google::protobuf::uint64 &value)
{
    auto result = TaskId{};
    result.set_value(value);

    return result;
}
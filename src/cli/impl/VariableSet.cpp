//
// Created by Illia Plaksa on 23.12.2021.
//

#include "../include/VariableSet.h"
#include "../../util/TaskDTOCreators.h"
#include "../../util/TaskCreators.h"

std::optional<TaskDTO> VariableSet::MakeTaskDTO() const
{
    auto task = MakeTask();
    if (task)
        return parent_id.has_value() ? CreateSubTaskDTO(id, *task, *parent_id)
                                     : CreateTaskDTO(id, *task);
    else
        return std::nullopt;
}
std::optional<Task> VariableSet::MakeTask() const
{
    return CreateTask(title, date, priority, label, status);
}
void VariableSet::Clear()
{
    *this = VariableSet{};
}

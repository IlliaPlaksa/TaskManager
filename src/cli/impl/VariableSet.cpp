//
// Created by Illia Plaksa on 23.12.2021.
//

#include "cli/include/VariableSet.h"
#include "util/TaskDTO/TaskDTOCreators.h"
#include "util/Task/TaskCreators.h"
#include "util/TaskId/TaskIdComparators.h"

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
    return CreateTask(title, date, priority, labels, status);
}
void VariableSet::Clear()
{
    *this = VariableSet{};
}
bool VariableSet::operator==(const VariableSet& other) const
{
    return this->title == other.title
        and this->id == other.id
        and this->status == other.status
        and this->date == other.date
        and this->file_name == other.file_name
        and this->priority == other.priority
        and this->labels == other.labels;
}

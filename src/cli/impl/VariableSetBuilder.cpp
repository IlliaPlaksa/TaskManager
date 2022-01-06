//
// Created by Illia Plaksa on 20.12.2021.
//

#include "../include/VariableSetBuilder.h"
#include <google/protobuf/util/time_util.h>
#include "../../util/TaskDTOCreators.h"

VariableSetBuilder& VariableSetBuilder::SetTitle(const std::string& title)
{
    task_.set_title(title);
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetDate(const time_t& date)
{
    task_.set_allocated_due_date(
        new google::protobuf::Timestamp(
            google::protobuf::util::TimeUtil::TimeTToTimestamp(date)
        )
    );
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetPriority(const Task::Priority& priority)
{
    task_.set_priority(priority);
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetLabel(const std::string& label)
{
    task_.set_label(label);
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetStatus(const Task::Status& status)
{
    task_.set_status(status);
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetParent(const TaskId& parent_id)
{
    parent_id_ = parent_id;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetId(const TaskId& id)
{
    id_ = id;
    return *this;
}
void VariableSetBuilder::Reset()
{
    task_.Clear();
    id_.Clear();
    parent_id_ = std::nullopt;
}
bool VariableSetBuilder::IsReady()
{
    return task_.IsInitialized() and
        !task_.title().empty() and
        task_.has_due_date() and
        id_.IsInitialized();
}
std::optional<TaskId> VariableSetBuilder::id()
{
    return id_.IsInitialized() ? std::optional(id_) : std::nullopt;
}
std::optional<Task> VariableSetBuilder::task()
{
    return task_.IsInitialized() ? std::optional(task_) : std::nullopt;
}
std::optional<TaskId> VariableSetBuilder::parent_id()
{
    return parent_id_ and parent_id_->IsInitialized()
           ? std::optional(id_) : std::nullopt;
}
std::optional<TaskDTO> VariableSetBuilder::MakeTaskToSerialize()
{
    if (this->IsReady())
        return parent_id_.has_value()
               ? *CreateSubTaskDTO(id_, task_, *parent_id_)
               : *CreateTaskDTO(id_, task_);
    else
        return std::nullopt;
}







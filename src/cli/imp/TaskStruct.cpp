//
// Created by Illia Plaksa on 20.12.2021.
//

#include "../include/TaskStruct.h"

TaskStruct &TaskStruct::SetTitle(const std::string &title)
{
    task_.set_title(title);
    return *this;
}
TaskStruct &TaskStruct::SetDate(const time_t &date)
{
    task_.set_allocated_due_date(
        new google::protobuf::Timestamp(
            google::protobuf::util::TimeUtil::TimeTToTimestamp(date)
        )
    );
    return *this;
}
TaskStruct &TaskStruct::SetPriority(const Task::Priority &priority)
{
    task_.set_priority(priority);
    return *this;
}
TaskStruct &TaskStruct::SetLabel(const std::string &label)
{
    task_.set_label(label);
    return *this;
}
TaskStruct &TaskStruct::SetStatus(const Task::Status &status)
{
    task_.set_status(status);
    return *this;
}
TaskStruct &TaskStruct::SetParent(const TaskId &parent_id)
{
    parent_id_ = parent_id;
    return *this;
}
TaskStruct &TaskStruct::SetId(const TaskId &id)
{
    id_ = id;
    return *this;
}
void TaskStruct::Reset()
{
    task_.Clear();
    id_.Clear();
    parent_id_ = std::nullopt;
}
bool TaskStruct::IsReady()
{
    return task_.IsInitialized() and
        task_.title().empty() and
        task_.has_due_date() and
        id_.IsInitialized();
}
std::optional<TaskId> TaskStruct::id()
{
    return id_.IsInitialized() ? std::optional(id_) : std::nullopt;
}
std::optional<Task> TaskStruct::task()
{
    return task_.IsInitialized() ? std::optional(task_) : std::nullopt;
}
std::optional<TaskId> TaskStruct::parent_id()
{
    return parent_id_ and parent_id_->IsInitialized()
           ? std::optional(id_) : std::nullopt;
}
std::optional<TaskToSerialize> TaskStruct::MakeTaskToSerialize()
{
    if (this->IsReady())
        return parent_id_.has_value()
               ? *CreateSubTaskToSerialize(id_, task_, *parent_id_)
               : *CreateTaskToSerialize(id_, task_);
    else
        return std::nullopt;
}







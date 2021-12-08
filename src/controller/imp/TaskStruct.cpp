//
// Created by Illia Plaksa on 26.11.2021.
//

#include "../include/TaskStruct.h"

Task TaskStruct::ConstructTask() const
{
    return Task::Create(title_,
                        due_to_date_,
                        priority_,
                        label_,
                        status_);
}
void TaskStruct::Reset()
{
    title_.clear();
    due_to_date_ = 0;
    priority_ = Task::Priority::kNone;
    label_.clear();
    status_ = Task::Status::kNone;
    parent_id_ = TaskId::CreateDefault();
    id_ = TaskId::CreateDefault();
}
bool TaskStruct::IsReadyToConstruct() const
{
    return !title_.empty()
        and due_to_date_ >= 0
        and priority_ != Task::Priority::kNone;
}
TaskStruct &TaskStruct::SetTitle(const std::string &title)
{
    this->title_ = title;
    return *this;
}
TaskStruct &TaskStruct::SetPriority(const Task::Priority &priority)
{
    this->priority_ = priority;
    return *this;
}
TaskStruct &TaskStruct::SetDate(const time_t &date)
{
    this->due_to_date_ = date;
    return *this;
}
TaskStruct &TaskStruct::SetLabel(const std::string &label)
{
    this->label_ = label;
    return *this;
}
TaskStruct &TaskStruct::SetStatus(const Task::Status &status)
{
    this->status_ = status;
    return *this;
}
TaskStruct &TaskStruct::SetParent(const TaskId &parent_id)
{
    this->parent_id_ = parent_id;
    return *this;
}
TaskStruct &TaskStruct::SetId(const TaskId &id)
{
    this->id_ = id;
    return *this;
}
TaskStruct &TaskStruct::SetFromTask(const Task &task)
{
    this->title_ = task.GetTitle();
    this->due_to_date_ = task.GetDate();
    this->priority_ = task.GetPriority();
    this->label_ = task.GetLabel();
    this->status_ = task.GetStatus();

    return *this;
}
TaskStruct::TaskStruct()
    :
    title_(std::string{}),
    due_to_date_(0),
    priority_(Task::Priority::kNone),
    status_(Task::Status::kNone),
    label_(std::string{}),
    id_(TaskId::CreateDefault()),
    parent_id_(TaskId::CreateDefault())
{
}
TaskId TaskStruct::GetParent() const
{
    return this->parent_id_;
}
TaskId TaskStruct::GetId() const
{
    return this->id_;
}


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
}
bool TaskStruct::IsReadyToConstruct() const
{
    return !title_.empty()
        and due_to_date_ >= 0
        and priority_ != Task::Priority::kNone;
}
void TaskStruct::SetTitle(const std::string &title)
{
    this->title_ = title;
}
void TaskStruct::SetPriority(const Task::Priority &priority)
{
    this->priority_ = priority;
}
void TaskStruct::SetDate(const time_t &date)
{
    this->due_to_date_ = date;
}
void TaskStruct::SetLabel(const std::string &label)
{
    this->label_ = label;
}
void TaskStruct::SetStatus(const Task::Status &status)
{
    this->status_ = status;
}
void TaskStruct::SetFromTask(const Task &task)
{
    this->title_ = task.GetTitle();
    this->due_to_date_ = task.GetDate();
    this->priority_ = task.GetPriority();
    this->label_ = task.GetLabel();
    this->status_ = task.GetStatus();
}

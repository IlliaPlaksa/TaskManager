//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../headers/Task.h"

Task::Task(
    const std::string &title,
    const std::time_t &due_to_date,
    const Priority &priority,
    const std::string &label,
    const Status &status)
    :
    title_(title),
    due_to_date_(due_to_date),
    priority_(priority),
    label_(label),
    status_(status) {}

Task Task::Create(const std::string &title,
                  const std::time_t &due_to_date,
                  const Priority &priority,
                  const std::string &label,
                  const Status &status)
{
    if (!title.empty())
        return Task{title, due_to_date, priority, label, status};
    else
        throw std::runtime_error("Passed empty title");
}

std::string Task::GetTitle() const
{
    return this->title_;
}
std::time_t Task::GetDate() const
{
    return this->due_to_date_;
}
Task::Priority Task::GetPriority() const
{
    return this->priority_;
}
std::string Task::GetLabel() const
{
    return this->label_;
}
Task::Status Task::GetStatus() const
{
    return this->status_;
}
void Task::Complete(Task &task)
{
    task.status_ = Status::kComplete;
}


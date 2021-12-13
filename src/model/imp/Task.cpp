//
// Created by Illia Plaksa on 08.11.2021.
//

#include "../include/Task.h"

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
Task Task::Complete(const Task &task)
{
    return Task::Create(task.GetTitle(),
                        task.GetDate(),
                        task.GetPriority(),
                        task.GetLabel(),
                        Task::Status::kCompleted);
}
std::string Task::ToString() const
{
    std::time_t date = this->GetDate();

    std::stringstream output;
    output
        << "Title: " << this->GetTitle() << '\t'
        << "Due date: " << std::put_time(std::localtime(&date), "%d.%m.%Y") << '\t'
        << "Priority: " << PriorityToString(this->GetPriority()) << '\t'
        << "Label: " << this->GetLabel() << '\t'
        << "Status: " << StatusToString(this->GetStatus()) << '\t';
    return output.str();
}
std::string Task::PriorityToString(const Task::Priority &priority)
{
    switch(priority)
    {
        case Task::Priority::kHigh: return "High";
        case Task::Priority::kMedium: return "Medium";
        case Task::Priority::kLow: return "Low";
        default: return std::string{};
    }
}
std::string Task::StatusToString(const Task::Status &status)
{
    switch(status)
    {
        case Task::Status::kInProgress: return "In progress";
        case Task::Status::kCompleted: return "Completed";
        default: return std::string{};
    }
}


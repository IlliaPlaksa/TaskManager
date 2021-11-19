//
// Created by Illia Plaksa on 08.11.2021.
//

#include "Task.h"

Task::Task(
    std::string title,
    const std::time_t &due_to_date,
    const Priority &priority,
    std::string label)
    :
    title_(std::move(title)),
    due_to_date_(due_to_date),
    priority_(priority),
    label_(std::move(label)) {}

Task Task::Create(const std::string &title,
                  const std::time_t &due_to_date,
                  const Priority &priority,
                  const std::string &label)
{
    if (!title.empty())
        return Task{title,
                    due_to_date,
                    priority,
                    label};
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

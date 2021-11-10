//
// Created by Illia Plaksa on 08.11.2021.
//

#include "Task.h"

Task::Task(
    std::string title,
    const std::time_t &due_to_date,
    const Priority &priority)
    :
    title_(std::move(title)),
    due_to_date_(due_to_date),
    priority_(priority) {}

Task Task::Create(std::string title,
                  const std::time_t &due_to_date,
                  const Priority &priority)
{
  if (!title.empty())
    return Task{std::move(title), due_to_date, priority};
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

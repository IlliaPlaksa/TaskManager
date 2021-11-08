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
  return Task{std::move(title), due_to_date, priority};
}

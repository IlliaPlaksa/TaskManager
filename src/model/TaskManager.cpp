//
// Created by Illia Plaksa on 08.11.2021.
//

#include "TaskManager.h"

TaskId TaskManager::Add(const Task &task)
{
  TaskId new_id = this->gen_.GetNextId();
  this->tasks_.insert(
      std::make_pair(new_id, task)
  );

  return new_id;
}

void TaskManager::Edit(TaskId id, const Task &task)
{
  if (this->tasks_.find(id) != this->tasks_.end())
    this->tasks_.at(id) = task;
  else
    throw std::runtime_error("Invalid id passed");
}

void TaskManager::Delete(TaskId id)
{
  this->tasks_.erase(id);
}

void TaskManager::Complete(TaskId id)
{
  if (this->tasks_.find(id) != this->tasks_.end())
    this->tasks_.erase(id);
  else
    throw std::runtime_error("Invalid id passed");
}

std::vector<std::pair<TaskId, Task>> TaskManager::Show()
{
  auto result = std::vector<std::pair<TaskId, Task>>{};
  for (auto elem: this->tasks_)
    result.emplace_back(elem);

  return result;
}

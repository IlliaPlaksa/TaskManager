//
// Created by Illia Plaksa on 08.11.2021.
//

#include "TaskManager.h"

size_t TaskManager::id_counter_ = 0;

void TaskManager::Create(const Task &task)
{
  this->tasks_.insert(
      std::make_pair(++id_counter_, task)
  );
}

void TaskManager::Edit(size_t id, const Task &task)
{
  if (this->tasks_.find(id) != this->tasks_.end())
    this->tasks_[id] = task;
  else
    throw std::runtime_error("Invalid id passed");
}

void TaskManager::Delete(size_t id)
{
  this->tasks_.erase(id);
}

void TaskManager::Complete(size_t id)
{
  if (this->tasks_.find(id) != this->tasks_.end())
    this->tasks_.erase(id);
  else
    throw std::runtime_error("Invalid id passed");
}

std::vector<std::pair<size_t, Task>> TaskManager::Show()
{
  auto result = std::vector<std::pair<size_t, Task>>{};
  for (auto elem: this->tasks_)
    result.emplace_back(elem);

  return result;
}

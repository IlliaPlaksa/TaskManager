//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKMANAGER_H_
#define TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

#include <map>
#include <vector>
#include "Task.h"
#include <set>

class TaskManager
{
  // TODO change size_t id to custom TaskId
 public:
  void Create(const Task &task);
  void Edit(size_t id, const Task &task);
  void Delete(size_t id);
  void Complete(size_t id);
  std::vector<std::pair<size_t, Task>> Show();

 private:
  std::map<size_t, Task> tasks_;

 private:
  static size_t id_counter_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

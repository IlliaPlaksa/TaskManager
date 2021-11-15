//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKMANAGER_H_
#define TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

#include <map>
#include <vector>
#include "Task.h"
#include "TaskId.h"
#include "IdGenerator.h"

class TaskManager
{
 public:
  TaskId Add(const Task &task);
  void Edit(TaskId id, const Task &task);
  void Delete(TaskId id);
  void Complete(TaskId id);
  std::vector<std::pair<TaskId, Task>> Show();

 private:
  std::map<TaskId, Task> tasks_;
  IdGenerator gen_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASK_H_
#define TASKMANAGER_SRC_MODEL_TASK_H_

#include "Task.pb.h"

std::optional<Task> CreateTask(const std::string &title,
                               const std::time_t &due_to_date,
                               const Task_Priority &priority,
                               const std::string &label = "",
                               const Task_Status &status = Task_Status_kInProgress);

bool operator==(const Task &first, const Task &second);

#endif //TASKMANAGER_SRC_MODEL_TASK_H_

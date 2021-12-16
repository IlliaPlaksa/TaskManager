//
// Created by Illia Plaksa on 16.12.2021.
//

#ifndef TASKMANAGER_UTILS_TASKCOMPARERS_H_
#define TASKMANAGER_UTILS_TASKCOMPARERS_H_

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskToSerialize.pb.h"

// -----Compare operator for Task structures-----

bool operator==(const TaskToSerialize &first, const TaskToSerialize &second);

bool operator==(const Task &first, const Task &second);

bool operator==(const TaskId &first, const TaskId &second);
bool operator<(const TaskId &first, const TaskId &second);

// ----------------------------------------------

#endif //TASKMANAGER_UTILS_TASKCOMPARERS_H_

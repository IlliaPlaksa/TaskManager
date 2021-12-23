//
// Created by Illia Plaksa on 22.12.2021.
//

#ifndef TASKMANAGER_PROTOBUF_UTIL_TASKIDCOMPARERS_H_
#define TASKMANAGER_PROTOBUF_UTIL_TASKIDCOMPARERS_H_

#include "TaskId.pb.h"

bool operator==(const TaskId& first, const TaskId& second);
bool operator<(const TaskId& first, const TaskId& second);

#endif //TASKMANAGER_PROTOBUF_UTIL_TASKIDCOMPARERS_H_

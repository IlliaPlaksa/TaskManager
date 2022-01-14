//
// Created by Illia Plaksa on 22.12.2021.
//

#ifndef TASKMANAGER_PROTOBUF_UTIL_TASKCOMPARERS_H_
#define TASKMANAGER_PROTOBUF_UTIL_TASKCOMPARERS_H_

#include "Task.pb.h"

bool operator==(const Task& first, const Task& second);

#endif //TASKMANAGER_PROTOBUF_UTIL_TASKCOMPARERS_H_

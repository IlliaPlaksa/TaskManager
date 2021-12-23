//
// Created by Illia Plaksa on 23.12.2021.
//

#ifndef TASKMANAGER_PROTOBUF_UTIL_TASKTOSERIALIZECOMPARERS_H_
#define TASKMANAGER_PROTOBUF_UTIL_TASKTOSERIALIZECOMPARERS_H_

#include "TaskToSerialize.pb.h"

bool operator==(const TaskToSerialize &first, const TaskToSerialize &second);

#endif //TASKMANAGER_PROTOBUF_UTIL_TASKTOSERIALIZECOMPARERS_H_

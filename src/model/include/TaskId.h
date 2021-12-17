//
// Created by Illia Plaksa on 10.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKID_H_
#define TASKMANAGER_SRC_MODEL_TASKID_H_

#include "TaskId.pb.h"

std::optional<TaskId> CreateTaskId(const google::protobuf::uint64 &value);

bool operator==(const TaskId &first, const TaskId &second);
bool operator<(const TaskId &first, const TaskId &second);


#endif //TASKMANAGER_SRC_MODEL_TASKID_H_

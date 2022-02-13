//
// Created by Illia Plaksa on 17.12.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_INCLUDE_TASKTOSERIALIZE_H_
#define TASKMANAGER_SRC_MODEL_INCLUDE_TASKTOSERIALIZE_H_

#include "TaskDTO.pb.h"
#include <optional>

std::optional<TaskDTO> CreateTaskDTO(const TaskId& id,
                                     const Task& task);

std::optional<TaskDTO> CreateSubTaskDTO(const TaskId& id,
                                        const Task& task,
                                        const TaskId& parent_id);

#endif //TASKMANAGER_SRC_MODEL_INCLUDE_TASKTOSERIALIZE_H_

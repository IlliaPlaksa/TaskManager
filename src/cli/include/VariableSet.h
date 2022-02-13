//
// Created by Illia Plaksa on 23.12.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_VARIABELSET_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_VARIABELSET_H_

#include <optional>

#include "TaskId.pb.h"
#include "Task.pb.h"
#include "TaskDTO.pb.h"

struct VariableSet
{
public:
    TaskId id;
    std::optional<TaskId> parent_id;

    std::string title;
    std::time_t date;
    std::vector<std::string> labels;
    Task::Status status;
    Task::Priority priority;

    std::string file_name;

public:
    std::optional<TaskDTO> MakeTaskDTO() const;
    std::optional<Task> MakeTask()const;

    bool operator==(const VariableSet& other) const;

public:
    void Clear();
};

#endif //TASKMANAGER_SRC_CLI_INCLUDE_VARIABELSET_H_

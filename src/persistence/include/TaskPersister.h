//
// Created by Illia Plaksa on 15.12.2021.
//

#ifndef TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_
#define TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_

#include <vector>
#include <fstream>
#include <optional>
#include "TaskDTO.pb.h"

class TaskPersister
{
public:
    virtual bool SerializeTasksToFile(const std::string& file_name, const std::vector<TaskDTO>& tasks);
    virtual std::optional<std::vector<TaskDTO>> DeserializeTasksFromFile(const std::string& file_name);
};

#endif //TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_

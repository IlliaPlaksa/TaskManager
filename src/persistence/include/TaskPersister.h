//
// Created by Illia Plaksa on 15.12.2021.
//

#ifndef TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_
#define TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_

#include <vector>
#include <fstream>
#include <optional>
#include "TaskToSerialize.pb.h"

class TaskPersister
{
public:
    virtual void SerializeToFile(const std::string &file_name,
                         const std::vector<TaskToSerialize> &tasks);
    virtual std::optional<std::vector<TaskToSerialize>> DeserializeFromFile(const std::string &file_name);
};

#endif //TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_

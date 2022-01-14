//
// Created by Illia Plaksa on 15.12.2021.
//

#ifndef TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_
#define TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_

#include <vector>
#include <fstream>
#include <optional>
#include "TaskDTO.pb.h"
#include "../../controller/include/Persister.h"

class FilePersister final : public TaskPersister
{
public:
    explicit FilePersister(const std::string& file_name);
public:
    bool Save(const std::vector<TaskDTO>& tasks) override;
    std::optional<std::vector<TaskDTO>> Load() override;

public:
    ~FilePersister() = default;

private:
    std::string file_name_;
};

#endif //TASKMANAGER_SRC_PERSISTENCE_TASKPERSISTER_H_

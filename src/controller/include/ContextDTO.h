//
// Created by Illia Plaksa on 23.12.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXTDTO_H_
#define TASKMANAGER_SRC_CLI_CONTEXTDTO_H_

#include "TaskDTO.pb.h"
#include "../../cli/include/VariableSet.h"

/*
 * Class used to transfer data between Controller and View
*/
class ContextDTO
{
public:
    static ContextDTO Create(const VariableSet& variable_set,
                             const std::vector<TaskDTO>& tasks = std::vector<TaskDTO>{});

public:
    ContextDTO() = default;

public:
    VariableSet variable_set() const;
    std::vector<TaskDTO> tasks() const;

private:
    VariableSet variable_set_;
    std::vector<TaskDTO> task_storage_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXTDTO_H_

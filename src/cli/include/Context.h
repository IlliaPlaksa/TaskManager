//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXT_H_
#define TASKMANAGER_SRC_CLI_CONTEXT_H_

#include <memory>
#include "Step.h"
#include "StepFactory.h"
#include "TaskStruct.h"
#include "VariableSet.h"
#include "../../controller/include/ContextDTO.h"

class Context
{
public:
    bool SetFromContextDTO(const ContextDTO& context_dto);

    ContextDTO GetContextDTO();
public:
    std::shared_ptr<VariableSet> GetVariableSet() const;
    std::shared_ptr<TaskStorage> GetStorage() const;

public:
    Context();

private:
    std::shared_ptr<VariableSet> variable_set_;
    std::shared_ptr<TaskStorage> task_storage_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXT_H_

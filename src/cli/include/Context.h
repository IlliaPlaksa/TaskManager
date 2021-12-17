//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXT_H_
#define TASKMANAGER_SRC_CLI_CONTEXT_H_

#include <memory>
#include "Step.h"
#include "StepFactory.h"
#include "../../model/include/TaskToSerialize.h"

class Context
{
public:
    std::shared_ptr<TaskToSerialize> GetStruct() const;
    std::shared_ptr<TaskStorage> GetTaskStorage() const;

public:
    Context();

private:
    std::shared_ptr<TaskToSerialize> task_struct_;
    std::shared_ptr<TaskStorage> task_storage_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXT_H_

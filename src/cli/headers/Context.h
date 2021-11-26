//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXT_H_
#define TASKMANAGER_SRC_CLI_CONTEXT_H_

#include <memory>
#include "Step.h"
#include "StepFactory.h"
#include "TaskStruct.h"

class Context
{
public:
    void SetStep(const std::shared_ptr<Step> &p_state);
    Step::Status Execute();

public:
    std::shared_ptr<StepFactory> GetFactory();
    std::shared_ptr<TaskStruct> GetStruct();

public:
    Context();
private:
    std::shared_ptr<Step> step_;
    std::shared_ptr<StepFactory> factory_;

    std::shared_ptr<TaskStruct> task_struct_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXT_H_

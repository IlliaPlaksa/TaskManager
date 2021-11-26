//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXT_H_
#define TASKMANAGER_SRC_CLI_CONTEXT_H_

#include <memory>
#include "Step.h"
#include "StepFactory.h"

class Context
{
public:
    void SetStep(const std::shared_ptr<Step> &p_state);
    Step::Status Execute();

public:
    std::shared_ptr<StepFactory> GetFactory();

public:
    Context();
private:
    std::shared_ptr<Step> step_;
    std::shared_ptr<StepFactory> factory_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXT_H_

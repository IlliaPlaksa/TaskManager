//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEPMACHINE_H_
#define TASKMANAGER_SRC_CLI_STEPMACHINE_H_

#include "Context.h"
#include "Step.h"
#include "MachineSteps.h"

class StepMachine
{
public:
    void Run();
public:
    void SetNextStep(const std::shared_ptr<Step> &step);
private:
    Context context_;
    StepFactory factory_;

    std::shared_ptr<Step> current_step_;
};

#endif //TASKMANAGER_SRC_CLI_STEPMACHINE_H_

//
// Created by Illia Plaksa on 24.11.2021.
//

#include "cli/include/MachineSteps.h"

StepResult ExitStep::Execute(Context& context)
{
    StepResult result;
    result.next_step = this->dependency()->step_factory()->CreateStep(StepId::kNone);
    result.command = std::shared_ptr<Command>(nullptr);
    return result;
}


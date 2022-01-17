//
// Created by Illia Plaksa on 13.12.2021.
//

#include "cli/include/MachineSteps.h"

StepResult UpdateStep::Execute(Context &context)
{
    // TODO add filter requests
    StepResult result;
    result.next_step = this->dependency()->step_factory()->CreateStep(StepId::kShow);
    result.command = std::shared_ptr<Command>(new ShowCommand());
    return result;
}
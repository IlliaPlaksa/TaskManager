//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult ExitStep::Execute(Context &context)
{
    StepResult result;
    result.next_step = this->dependency()->step_factory()->CreateStep(StepId::kNone);
    result.command_type = CommandType::kNone;
    return result;
}


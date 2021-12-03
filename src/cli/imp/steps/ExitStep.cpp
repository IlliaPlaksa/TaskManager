//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult ExitStep::Execute(Context &context, StepFactory& factory)
{
    StepResult result;
    result.next_step = factory.CreateStep(StepId::kNone);
    result.operation = OperationType::kNone;
    return result;
}


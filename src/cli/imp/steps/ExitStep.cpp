//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult ExitStep::Execute(Context &context)
{
    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kNone);
    result.operation = OperationType::kNone;
    return result;
}


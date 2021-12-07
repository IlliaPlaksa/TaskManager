//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult ShowStep::Execute(Context &context)
{
    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.operation = OperationType::kNone;
    return result;
}

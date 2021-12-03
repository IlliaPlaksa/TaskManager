//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult CompleteStep::Execute(Context &context, StepFactory& factory)
{
    StepResult result;
    result.next_step = factory.CreateStep(StepId::kRoot);
    result.operation = OperationType::kNone;
    return result;
}

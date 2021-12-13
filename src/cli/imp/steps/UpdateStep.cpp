//
// Created by Illia Plaksa on 13.12.2021.
//

#include "../../include/MachineSteps.h"

StepResult UpdateStep::Execute(Context &context)
{
    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kShow);
    result.command_type = CommandType::kShow;
    return result;
}
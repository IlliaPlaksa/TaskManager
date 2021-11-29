//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../headers/MachineSteps.h"

Step::Status ExitStep::Execute(Context &context)
{
    context.SetStep(context.GetFactory()->CreateStep(StepId::kRoot));
    return Status::kExit;
}


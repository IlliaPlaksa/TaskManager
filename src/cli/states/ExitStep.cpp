//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../MachineSteps.h"

Step::Status ExitStep::Execute(Context &context)
{
    context.SetStep(StepFactory::CreateStep(StepId::kRoot));
    return Status::kExit;
}


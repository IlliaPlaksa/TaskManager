//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../MachineSteps.h"

Step::Status CompleteStep::Execute(Context &context)
{
    context.SetStep(StepFactory::CreateStep(StepId::kRoot));
    return Status::kOk;
}

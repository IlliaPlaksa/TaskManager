//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

Step::Status CompleteStep::Execute(Context &context)
{
    context.SetStep(context.GetFactory()->CreateStep(StepId::kRoot));
    return Status::kOk;
}

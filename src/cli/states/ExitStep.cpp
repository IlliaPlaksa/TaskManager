//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../MachineSteps.h"

Step::Status ExitStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{nullptr});
    return Status::kExit;
}


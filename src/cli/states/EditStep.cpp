//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../MachineSteps.h"

Step::Status EditStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{new RootStep});
    return Status::kOk;
}

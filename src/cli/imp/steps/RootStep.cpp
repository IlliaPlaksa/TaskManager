//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

Step::Status RootStep::Execute(Context &context)
{
    auto console = this->GetConsoleManipulator();
    auto step_id = Read::Command(console);

    auto next_state = context.GetFactory()->CreateStep(step_id.value());

    context.SetStep(next_state);
    if (next_state)
        return Status::kOk;
    else
        return Status::kError;
}

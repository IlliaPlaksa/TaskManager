//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

Step::Status RootStep::Execute(Context &context)
{
    auto console = this->GetConsoleManipulator();

    std::shared_ptr<Step> new_state;

    auto step_id = Read::Command(console);

    if (step_id)
        new_state = context.GetFactory()->CreateStep(step_id.value());
    else
    {
        console.WriteLine("No such command\nUse [help] to determine command you needed");
        new_state = context.GetFactory()->CreateStep(StepId::kRoot);
    }

    context.SetStep(new_state);
    if (new_state)
        return Status::kOk;
    else
        return Status::kError;
}

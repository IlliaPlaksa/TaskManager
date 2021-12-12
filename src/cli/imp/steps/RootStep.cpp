//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult RootStep::Execute(Context &context)
{
    auto console = this->GetConsoleManipulator();
    auto step_id = Read::Command(console);

    StepResult result;
    result.next_step = GetFactory()->CreateStep(step_id);
    result.command_type = CommandType::kNone;
    return result;
}

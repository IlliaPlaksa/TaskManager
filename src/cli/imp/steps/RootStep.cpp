//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult RootStep::Execute(Context &context, StepFactory& factory)
{
    auto console = this->GetConsoleManipulator();
    auto step_id = Read::Command(console);

    StepResult result;
    result.next_step = factory.CreateStep(step_id.value());
    result.operation = OperationType::kNone;
    return result;
}

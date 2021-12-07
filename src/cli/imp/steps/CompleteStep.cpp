//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult CompleteStep::Execute(Context &context)
{
    auto task_id = context.GetTaskId();
    auto console = this->GetConsoleManipulator();

    console->ResetPrompt("complete Task");
    *task_id = Read::Id(console);

    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.operation = OperationType::kComplete;
    return result;
}

//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult DeleteStep::Execute(Context &context, StepFactory& factory)
{
    auto task_id = context.GetTaskId();
    auto console = this->GetConsoleManipulator();

    console.ResetPrompt("delete Task");
    *task_id = Read::Id(console);

    StepResult result;
    result.next_step = factory.CreateStep(StepId::kRoot);
    result.operation = OperationType::kDelete;
    return result;
}

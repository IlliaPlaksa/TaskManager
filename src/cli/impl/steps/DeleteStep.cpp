//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult DeleteStep::Execute(Context &context)
{
    auto task_struct = context.GetStruct();
    auto console = this->GetConsoleManipulator();

    console->ResetPrompt("delete Task");
    task_struct->SetId(Read::Id(console));
    console->ResetPrompt();

    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kDelete;
    return result;
}

//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult EditStep::Execute(Context &context)
{
    auto console = this->GetConsoleManipulator();
    auto &task_struct = *context.GetStruct();

    console->ResetPrompt("edit Task");

    console->ResetPrompt("Task");
    task_struct.SetId(Read::Id(console));
    // TODO add check for non-exist Task

    // Filling structure
    task_struct
        .SetId(Read::Id(console))
        .SetTitle(Read::Title(console))
        .SetDate(Read::Date(console))
        .SetPriority(Read::Priority(console))
        .SetLabel(Read::Label(console))
        .SetStatus(Task::Status::kInProgress);

    console->ResetPrompt("Parent");
    task_struct.SetId(Read::Id(console));

    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.operation = OperationType::kNone;
    return result;
}

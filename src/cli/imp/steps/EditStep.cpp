//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult EditStep::Execute(Context &context)
{
    auto console = this->GetConsoleManipulator();
    auto &task_struct = *context.GetStruct();
    auto& task_id = *context.GetTaskId();
    auto& parent_id = *context.GetParentTaskId();

    console->ResetPrompt("edit Task");

    console->ResetPrompt("Task");
    task_id = Read::Id(console);
    // TODO add check for non-exist Task

    // Filling structure
    task_struct
        .SetTitle(Read::Title(console))
        .SetDate(Read::Date(console))
        .SetPriority(Read::Priority(console))
        .SetLabel(Read::Label(console))
        .SetStatus(Task::Status::kInProgress);

    console->ResetPrompt("Parent");
    parent_id = Read::Id(console);

    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.operation = OperationType::kNone;
    return result;
}

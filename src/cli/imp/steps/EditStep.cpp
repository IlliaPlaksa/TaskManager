//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult EditStep::Execute(Context &context)
{
    StepResult result;
    auto console = this->GetConsoleManipulator();
    auto &task_struct = *context.GetStruct();

    console->ResetPrompt("edit Task");

    console->ResetPrompt("Task");
    // TODO add check for non-exist Task

    // Filling structure
    task_struct
        .SetId(Read::Id(console))
        .SetTitle(Read::Title(console))
        .SetDate(Read::Date(console))
        .SetPriority(Read::Priority(console))
        .SetLabel(Read::Label(console))
        .SetParent(Read::ParentId(console))
        .SetStatus(Task::Status::kInProgress);

    console->ResetPrompt();
    auto confirm = Read::Confirm(console);

    if (confirm)
    {
        result.operation = OperationType::kAdd;
    } else
    {
        console->WriteLine("Operation was canceled");
        task_struct.Reset();
        result.operation = OperationType::kNone;
    }

    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.operation = OperationType::kNone;
    return result;
}

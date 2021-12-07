//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult AddStep::Execute(Context &context)
{
    StepResult result;

    auto console = this->GetConsoleManipulator();
    auto &task_struct = *context.GetStruct();

    console->ResetPrompt("add Task");

    // Filling structure
    task_struct
        .SetTitle(Read::Title(console))
        .SetDate(Read::Date(console))
        .SetPriority(Read::Priority(console))
        .SetLabel(Read::Label(console))
        .SetStatus(Task::Status::kInProgress)
        .SetParent(Read::Id(console));

    console->ResetPrompt("add Parent");

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
    return result;
}

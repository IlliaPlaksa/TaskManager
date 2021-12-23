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
        .SetStatus(Task_Status_kInProgress);

    auto label = Read::Label(console);
    if (label)
        task_struct.SetLabel(label.value());

    auto parent_id = Read::ParentId(console);
    if (parent_id)
        task_struct.SetParent(parent_id.value());

    console->ResetPrompt();
    auto confirm = Read::Confirm(console);

    if (confirm)
    {
        result.command_type = CommandType::kAdd;
    } else
    {
        console->WriteLine("Operation was canceled");
        task_struct.Reset();
        result.command_type = CommandType::kNone;
    }
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    return result;
}

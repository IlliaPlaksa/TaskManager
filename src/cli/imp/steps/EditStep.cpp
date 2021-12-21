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
    result.command_type = CommandType::kNone;
    return result;
}

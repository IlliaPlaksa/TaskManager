//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult EditStep::Execute(Context &context, StepFactory& factory)
{
    auto console = this->GetConsoleManipulator();
    auto &task_struct = *context.GetStruct();
    auto& task_id = *context.GetTaskId();
    auto& parent_id = *context.GetParentTaskId();

    console.ResetPrompt("edit Task");

    // Filling structure
    task_struct
        .SetTitle(Read::Title(console))
        .SetDate(Read::Date(console))
        .SetPriority(Read::Priority(console))
        .SetLabel(Read::Label(console))
        .SetStatus(Task::Status::kInProgress);

    console.ResetPrompt("Task");
    task_id = Read::Id(console);

    console.ResetPrompt("Parent");
    parent_id = Read::Id(console);

    StepResult result;
    result.next_step = factory.CreateStep(StepId::kRoot);
    result.operation = OperationType::kNone;
    return result;
}

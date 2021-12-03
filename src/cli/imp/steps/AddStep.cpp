//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult AddStep::Execute(Context &context, StepFactory &factory)
{
    StepResult result;

    auto console = this->GetConsoleManipulator();
    auto task_struct = context.GetStruct();
    auto task_id = context.GetTaskId();

    console.ResetPrompt("add Task");

    // Filling structure
    task_struct->SetTitle(Read::Title(console).value());
    task_struct->SetDate(Read::Date(console).value());
    task_struct->SetPriority(Read::Priority(console).value());
    task_struct->SetLabel(Read::Label(console).value());
    task_struct->SetStatus(Task::Status::kInProgress);

    console.ResetPrompt("add Parent");
    *context.GetParentTaskId() = Read::Id(console).value();

    auto confirm = Read::Confirm(console);
    if (confirm)
    {
        if (confirm.value())
        {
            result.operation = OperationType::kAdd;
        } else
        {
            console.WriteLine("Operation was canceled");
            task_struct->Reset();
            result.operation = OperationType::kNone;
        }
    }
    console.ResetPrompt();

    result.next_step = factory.CreateStep(StepId::kRoot);
    return result;
}

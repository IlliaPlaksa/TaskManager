//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

Step::Status AddStep::Execute(Context &context)
{
    auto console = this->GetConsoleManipulator();
    auto task_struct = context.GetStruct();

    console.ResetPrompt("add Task");

    auto title = Read::Title(console);
    auto date = Read::Date(console);
    auto priority = Read::Priority(console);
    auto label = Read::Label(console);
    console.ResetPrompt("add Parent");
    auto id = Read::Id(console);

    auto confirm = Read::Confirm(console);
    if (confirm)
    {
        if (confirm.value())
        {
            // Filling structure
            task_struct->SetTitle(title.value());
            task_struct->SetDate(date.value());
            task_struct->SetPriority(priority.value());
            task_struct->SetLabel(label.value());
            task_struct->SetStatus(Task::Status::kInProgress);

            if (task_struct->IsReadyToConstruct())
                task_struct->ConstructTask(); // TODO implement sending task to MODEL
        } else
            console.WriteLine("Operation canceled");

    }

    console.ResetPrompt();

    context.SetStep(context.GetFactory()->CreateStep(StepId::kRoot));
    return Status::kOk;
}

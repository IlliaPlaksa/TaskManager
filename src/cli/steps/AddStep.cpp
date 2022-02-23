//
// Created by Illia Plaksa on 24.11.2021.
//

#include "cli/MachineSteps.h"

StepResult AddStep::Execute(Context& context)
{
    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    console->ResetPrompt("add Task");

    auto task = Read::Task(console);
    auto parent_id = Read::ParentId(console);

    console->ResetPrompt();
    auto confirm = Read::Confirm(console);

    StepResult result;

    if (confirm)
    {
        result.command = std::shared_ptr<Command>(new AddCommand(task, parent_id));
    }
    else
    {
        console->WriteLine("Operation was canceled");
        result.command = std::shared_ptr<Command>(nullptr);
    }
    result.next_step = step_factory->CreateStep(StepId::kRoot);
    return result;
}

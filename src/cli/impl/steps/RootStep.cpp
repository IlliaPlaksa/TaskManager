//
// Created by Illia Plaksa on 24.11.2021.
//

#include "cli/include/MachineSteps.h"

StepResult RootStep::Execute(Context& context)
{
    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    console->ResetPrompt();
    auto step_id = Read::Command(console);

    StepResult result;

    result.next_step = step_factory->CreateStep(step_id);
    result.command = std::shared_ptr<Command>(nullptr);

    return result;
}

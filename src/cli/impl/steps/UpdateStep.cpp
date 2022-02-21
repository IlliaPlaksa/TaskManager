//
// Created by Illia Plaksa on 13.12.2021.
//

#include "cli/include/MachineSteps.h"

StepResult UpdateStep::Execute(Context& context)
{
    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    console->ResetPrompt("show");

    auto label = Read::Label(console);

    StepResult result;

    result.next_step = step_factory->CreateStep(StepId::kShow);
    result.command = std::make_shared<ShowCommand>(label);

    context.GetStorage()->Clear();
    return result;
}
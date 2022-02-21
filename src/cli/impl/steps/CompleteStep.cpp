//
// Created by Illia Plaksa on 24.11.2021.
//

#include "cli/include/MachineSteps.h"

StepResult CompleteStep::Execute(Context& context)
{
    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    console->ResetPrompt("complete Task");

    auto id = Read::Id(console);

    console->ResetPrompt();

    StepResult result;

    result.command = std::shared_ptr<Command>(new CompleteCommand(id));
    result.next_step = step_factory->CreateStep(StepId::kRoot);

    return result;
}

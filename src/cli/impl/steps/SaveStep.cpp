//
// Created by Illia Plaksa on 10.01.2022.
//

#include "cli/include/MachineSteps.h"

StepResult SaveStep::Execute(Context& context)
{
    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    auto file_name = Read::FileName(console);

    StepResult result;

    result.command = result.command = std::shared_ptr<Command>(new SaveCommand(file_name));
    result.next_step = step_factory->CreateStep(StepId::kRoot);

    return result;
}

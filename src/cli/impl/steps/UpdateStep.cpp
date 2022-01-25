//
// Created by Illia Plaksa on 13.12.2021.
//

#include "cli/include/MachineSteps.h"

StepResult UpdateStep::Execute(Context &context)
{
    StepResult result;

    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();
    auto variable_set_builder = VariableSetBuilder{};

    console->ResetPrompt("show");

    auto label = Read::Label(console);

    result.next_step = this->dependency()->step_factory()->CreateStep(StepId::kShow);
    result.command = std::make_shared<ShowCommand>(label);

    context.GetStorage()->Clear();
    return result;
}
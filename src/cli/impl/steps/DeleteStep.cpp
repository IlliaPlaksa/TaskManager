//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult DeleteStep::Execute(Context &context)
{
    auto variable_set_builder = VariableSetBuilder{};

    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    console->ResetPrompt("delete Task");
    variable_set_builder.SetId(Read::Id(console));
    console->ResetPrompt();

    *context.GetVariableSet() = variable_set_builder.GetResult();

    StepResult result;
    result.next_step = step_factory->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kDelete;
    return result;
}

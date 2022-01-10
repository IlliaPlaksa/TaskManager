//
// Created by Illia Plaksa on 10.01.2022.
//

#include "../../include/MachineSteps.h"

StepResult LoadStep::Execute(Context& context)
{
    StepResult result;

    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();
    auto variable_set_builder = VariableSetBuilder{};

    variable_set_builder.SetFileName(Read::FileName(console));

    *context.GetVariableSet() = variable_set_builder.GetResult();

    result.command_type = CommandType::kLoad;
    result.next_step = step_factory->CreateStep(StepId::kRoot);
    return result;
}

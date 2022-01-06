//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult CompleteStep::Execute(Context &context)
{
    auto variable_set_builder = VariableSetBuilder{};
    auto console = this->GetConsoleManipulator();

    console->ResetPrompt("complete Task");
    variable_set_builder.SetId(Read::Id(console));
    console->ResetPrompt();

    *context.GetVariableSet() = variable_set_builder.GetResult();

    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kComplete;
    return result;
}

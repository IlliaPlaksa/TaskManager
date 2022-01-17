//
// Created by Illia Plaksa on 11.01.2022.
//

#include "cli/include/MachineSteps.h"

StepResult ErrorStep::Execute(Context& context)
{
    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    auto message = context.GetVariableSet()->error_message;

    if (message)
        console->WriteError(*message);
    else
        console->WriteError("Error message has no value");

    StepResult result;
    result.next_step = step_factory->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kNone;
    return result;
}

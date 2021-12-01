//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

std::shared_ptr<Step> RootStep::Execute(Context &context, StepFactory& factory)
{
    auto console = this->GetConsoleManipulator();
    auto step_id = Read::Command(console);

    return factory.CreateStep(step_id.value());
}

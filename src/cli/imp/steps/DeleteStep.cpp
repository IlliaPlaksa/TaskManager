//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

std::shared_ptr<Step> DeleteStep::Execute(Context &context, StepFactory& factory)
{
    return factory.CreateStep(StepId::kRoot);
}

//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

std::shared_ptr<Step> HelpStep::Execute(Context &context, StepFactory& factory)
{
    // TODO implement with reading file
    std::stringstream output;
    output << "Commands:" << std::endl
           << "help" << std::endl
           << "add" << std::endl
           << "edit" << std::endl
           << "complete" << std::endl
           << "delete" << std::endl
           << "show" << std::endl
           << "exit" << std::endl;

    this->GetConsoleManipulator().WriteLine(output.str());
    return factory.CreateStep(StepId::kRoot);
}
//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../headers/MachineSteps.h"

Step::Status HelpStep::Execute(Context &context)
{
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
    context.SetStep(context.GetFactory()->CreateStep(StepId::kRoot));
    return Status::kOk;
}
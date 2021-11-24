//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../MachineSteps.h"

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

    context.WriteLine(output.str());
    auto new_state = std::shared_ptr<Step>{new RootStep};
    context.SetStep(new_state);
    return Status::kOk;
}
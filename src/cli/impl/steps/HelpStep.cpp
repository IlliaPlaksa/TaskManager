//
// Created by Illia Plaksa on 24.11.2021.
//

#include "cli/include/MachineSteps.h"
#include <fstream>

StepResult HelpStep::Execute(Context& context)
{
    std::string output;
    std::ifstream file{"help.txt"};

    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    if (file.is_open())
    {
        while (std::getline(file, output))
            console->WriteLine(output);
    }
    else
        console->WriteLine("File help.txt is not found");

    StepResult result;
    result.next_step = step_factory->CreateStep(StepId::kRoot);
    result.command = std::shared_ptr<Command>(nullptr);
    return result;
}
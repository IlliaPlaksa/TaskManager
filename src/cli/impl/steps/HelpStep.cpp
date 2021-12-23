//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"
#include <fstream>

StepResult HelpStep::Execute(Context &context)
{
    std::string output;
    std::ifstream file{"help.txt"};

    if (file.is_open())
    {
        while(std::getline(file, output))
            this->GetConsoleManipulator()->WriteLine(output);
    } else
        this->GetConsoleManipulator()->WriteLine("File help.txt is not found");

    StepResult result;
    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kNone;
    return result;
}
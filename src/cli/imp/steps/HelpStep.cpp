//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"
#include <fstream>

std::shared_ptr<Step> HelpStep::Execute(Context &context, StepFactory &factory)
{
    // TODO implement with reading file
    std::string output;

    std::ifstream file{"help.txt"};

    if (file.is_open())
    {
        while(std::getline(file, output))
            this->GetConsoleManipulator().WriteLine(output);
    } else
        this->GetConsoleManipulator().WriteLine("File help.txt is not found");

    return factory.CreateStep(StepId::kRoot);
}
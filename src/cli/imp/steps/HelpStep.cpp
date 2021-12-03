//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"
#include <fstream>

StepResult HelpStep::Execute(Context &context, StepFactory &factory)
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

    StepResult result;
    result.next_step = factory.CreateStep(StepId::kRoot);
    result.operation = OperationType::kNone;
    return result;
}
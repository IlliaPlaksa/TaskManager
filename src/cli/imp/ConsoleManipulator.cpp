//
// Created by Illia Plaksa on 25.11.2021.
//

#include "../include/ConsoleManipulator.h"

void ConsoleManipulator::WriteLine(const std::string &message) const
{
    std::cout << message << std::endl;
}
std::string ConsoleManipulator::ReadLine(const std::string &message) const
{
    std::cout << this->prompt_ << message << " > ";
    std::string input;
    std::cin >> input;
    return input;
}

void ConsoleManipulator::ResetPrompt(const std::string &prompt)
{
    this->prompt_ = prompt;
}

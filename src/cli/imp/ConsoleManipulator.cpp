//
// Created by Illia Plaksa on 25.11.2021.
//

#include "../include/ConsoleManipulator.h"

void ConsoleManipulator::WriteLine(const std::string &message)
{
    std::cout << message << std::endl;
}
std::string ConsoleManipulator::ReadLine(const std::string &message)
{
    std::cout << this->prefix_ << message << " > ";
    std::string input;
    std::cin >> input;
    return input;
}

void ConsoleManipulator::SetPrefix(const std::string &prefix)
{
    this->prefix_ = prefix;
}

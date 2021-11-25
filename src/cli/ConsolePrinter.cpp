//
// Created by Illia Plaksa on 25.11.2021.
//

#include "ConsolePrinter.h"

void ConsolePrinter::WriteLine(const std::string &message)
{
    std::cout << message << std::endl;
}
std::string ConsolePrinter::ReadLine(const std::string &message)
{
    std::cout << this->prefix_ << message << " > ";
    std::string input;
    std::cin >> input;
    return input;
}

void ConsolePrinter::SetPrefix(const std::string &prefix)
{
    this->prefix_ = prefix;
}

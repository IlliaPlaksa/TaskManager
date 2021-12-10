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
    std::cout << this->prompt_ << ' ' << message << "> ";
    std::string input;
    std::getline(std::cin, input);
    
    return trim(std::move(input));
}

void ConsoleManipulator::ResetPrompt(const std::string &prompt)
{
    this->prompt_ = prompt;
}
void ConsoleManipulator::WriteError(const std::string &message) const
{
    std::cout << "[Error]" << '\t' <<  message << std::endl;
}

std::string ConsoleManipulator::rtrim(std::string &&s) const
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         [](unsigned char ch)
                         {
                             return !std::isspace(ch);
                         }).base(), s.end());
    return s;
}
std::string ConsoleManipulator::ltrim(std::string &&s) const
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    [](int c)
                                    {
                                        return !std::isspace(c);
                                    }));
    return s;
}
std::string ConsoleManipulator::trim(std::string &&s) const
{
    return ltrim(rtrim(std::move(s)));
}

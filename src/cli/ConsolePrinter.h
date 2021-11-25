//
// Created by Illia Plaksa on 25.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONSOLEPRINTER_H_
#define TASKMANAGER_SRC_CLI_CONSOLEPRINTER_H_

#include <string>
#include <iostream>

class ConsolePrinter
{
public:
    void WriteLine(const std::string &message);
    std::string ReadLine(const std::string &message = "");

    void SetPrefix(const std::string &prefix);
private:
    std::string prefix_;
};

#endif //TASKMANAGER_SRC_CLI_CONSOLEPRINTER_H_

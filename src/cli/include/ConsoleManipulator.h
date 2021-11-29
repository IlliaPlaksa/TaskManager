//
// Created by Illia Plaksa on 25.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONSOLEMANIPULATOR_H_
#define TASKMANAGER_SRC_CLI_CONSOLEMANIPULATOR_H_

#include <string>
#include <iostream>

class ConsoleManipulator
{
public:
    void WriteLine(const std::string &message) const;
    std::string ReadLine(const std::string &message = "") const;

    void ResetPrompt(const std::string &prompt = "");
private:
    std::string prompt_;
};

#endif //TASKMANAGER_SRC_CLI_CONSOLEMANIPULATOR_H_

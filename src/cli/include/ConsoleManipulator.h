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
    virtual void WriteLine(const std::string& message) const;
    virtual void WriteError(const std::string& message) const;
    virtual std::string ReadLine() const;
    virtual std::string ReadLine(const std::string& message) const;

    virtual void ResetPrompt();
    virtual void ResetPrompt(const std::string& prompt);

public:
    virtual ~ConsoleManipulator() = default;
private:
    // trim from start
    std::string ltrim(std::string&& s) const;

    // trim from end
    std::string rtrim(std::string&& s) const;

    // trim from both ends
    std::string trim(std::string&& s) const;

private:
    std::string prompt_;
};

#endif //TASKMANAGER_SRC_CLI_CONSOLEMANIPULATOR_H_

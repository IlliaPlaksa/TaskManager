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
    void WriteError(const std::string &message) const;
    std::string ReadLine(const std::string &message = "") const;

    void ResetPrompt(const std::string &prompt = "");
private:
    // trim from start
    std::string ltrim(std::string s) const
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                        [](int c)
                                        {
                                            return !std::isspace(c);
                                        }));
        return s;
    }

// trim from end
    std::string rtrim(std::string s) const
    {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                             [](unsigned char ch)
                             {
                                 return !std::isspace(ch);
                             }).base(), s.end());
        return s;
    }

// trim from both ends
    std::string trim(std::string s) const
    {
        return ltrim(rtrim(s));
    }

private:
    std::string prompt_;
};

#endif //TASKMANAGER_SRC_CLI_CONSOLEMANIPULATOR_H_

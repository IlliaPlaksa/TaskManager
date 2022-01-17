//
// Created by Illia Plaksa on 17.01.2022.
//

#ifndef TASKMANAGER_TESTS_MOCKS_CONSOLEMANIPULATORMOCK_H_
#define TASKMANAGER_TESTS_MOCKS_CONSOLEMANIPULATORMOCK_H_

#include "gmock/gmock.h"
#include "cli/include/ConsoleManipulator.h"

class ConsoleManipulatorMock : public ConsoleManipulator
{
public:
    MOCK_METHOD(void, WriteLine, (const std::string& message), (const, override));
    MOCK_METHOD(void, WriteError, (const std::string& message), (const, override));
    MOCK_METHOD(std::string, ReadLine, (const std::string& message = ""), (const, override));
    MOCK_METHOD(void, ResetPrompt, (const std::string& prompt = ""), (const, override));
};

#endif //TASKMANAGER_TESTS_MOCKS_CONSOLEMANIPULATORMOCK_H_

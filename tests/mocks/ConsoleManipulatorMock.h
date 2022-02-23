//
// Created by Illia Plaksa on 17.01.2022.
//

#ifndef TASKMANAGER_TESTS_MOCKS_CONSOLEMANIPULATORMOCK_H_
#define TASKMANAGER_TESTS_MOCKS_CONSOLEMANIPULATORMOCK_H_

#include "gmock/gmock.h"
#include "cli/ConsoleManipulator.h"

class ConsoleManipulatorMock : public ConsoleManipulator
{
public:
    using ConsoleManipulator::ConsoleManipulator;

    MOCK_METHOD(void, WriteLine, (const std::string& message), (const, override));
    MOCK_METHOD(void, WriteError, (const std::string& message), (const, override));
    MOCK_METHOD(std::string, ReadLine, (), (const, override));
    MOCK_METHOD(std::string, ReadLine, (const std::string& message), (const, override));
    MOCK_METHOD(void, ResetPrompt, (), (override));
    MOCK_METHOD(void, ResetPrompt, (const std::string& prompt), (override));
};

#endif //TASKMANAGER_TESTS_MOCKS_CONSOLEMANIPULATORMOCK_H_

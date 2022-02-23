//
// Created by Illia Plaksa on 14.12.2021.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDMOCK_H_

#include "gmock/gmock.h"
#include "common/Command.h"

class CommandMock : public Command
{
public:
    MOCK_METHOD(CommandResponse, Execute, (const std::shared_ptr<ModelController>& model), (override));
};

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDMOCK_H_

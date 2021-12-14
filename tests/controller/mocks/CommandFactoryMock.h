//
// Created by Illia Plaksa on 14.12.2021.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDFACTORYMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDFACTORYMOCK_H_

#include "gmock/gmock.h"
#include "../../../src/controller/include/CommandFactory.h"

class CommandFactoryMock : public CommandFactory
{
public:
    MOCK_METHOD(std::shared_ptr<Command>,
        CreateCommand,
    (const CommandType &type, const std::shared_ptr<IModel> &model),
    (override));
};

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDFACTORYMOCK_H_

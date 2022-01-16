//
// Created by Illia Plaksa on 14.12.2021.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDMOCK_H_

#include "gmock/gmock.h"
#include "common/include/Command.h"

class CommandMock : public Command
{
public:
    using Command::Command;
    MOCK_METHOD(Model::Response, Execute, (const std::shared_ptr<Model> &view), (override));
};

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_COMMANDMOCK_H_

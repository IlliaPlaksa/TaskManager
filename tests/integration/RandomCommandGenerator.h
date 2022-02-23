//
// Created by Illia Plaksa on 18.02.2022.
//

#ifndef TASKMANAGER_TESTS_INTEGRATION_RANDOMCOMMANDGENERATOR_H_
#define TASKMANAGER_TESTS_INTEGRATION_RANDOMCOMMANDGENERATOR_H_

#include "cli/ConcreteCommands.h"
#include <time.h>

class RandomCommandGenerator
{
    typedef std::shared_ptr<Command> (RandomCommandGenerator::*GenFunction)();
    class CreateCommandHandler
    {
    public:
        virtual std::shared_ptr<Command> operator()() = 0;

    public:
        virtual Task RandomTask();
        virtual TaskId RandomTaskId();

        virtual ~CreateCommandHandler() = default;
    };

private:
    std::vector<std::shared_ptr<CreateCommandHandler>> functions_;

public:
    RandomCommandGenerator();

public:
    std::shared_ptr<Command> GenerateCommand();

private:
    class CreateAddCommand : public CreateCommandHandler
    {
    public:
        std::shared_ptr<Command> operator()() override;
    };

    class CreateAddSubTaskCommand : public CreateCommandHandler
    {
    public:
        std::shared_ptr<Command> operator()() override;
    };

    class CreateEditCommand : public CreateCommandHandler
    {
    public:
        std::shared_ptr<Command> operator()() override;
    };

    class CreateEditSubTaskCommand : public CreateCommandHandler
    {
    public:
        std::shared_ptr<Command> operator()() override;
    };

    class CreateCompleteCommand : public CreateCommandHandler
    {
    public:
        std::shared_ptr<Command> operator()() override;
    };

    class CreateDeleteCommand : public CreateCommandHandler
    {
    public:
        std::shared_ptr<Command> operator()() override;
    };

    class CreateShowCommand : public CreateCommandHandler
    {
    public:
        std::shared_ptr<Command> operator()() override;
    };
};

#endif //TASKMANAGER_TESTS_INTEGRATION_RANDOMCOMMANDGENERATOR_H_

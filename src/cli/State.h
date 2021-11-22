//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STATE_H_
#define TASKMANAGER_SRC_CLI_STATE_H_

#include <memory>
#include <sstream>

class Context;

class State
{
public:
    virtual const State* Execute(Context &context) = 0;
};

class StartState : public State
{
public:

    const State* Execute(Context &context) override;
};

class HelpState : public State
{
public:
    const State* Execute(Context &context) override;
};

class ExitState : public State
{
public:
    const State* Execute(Context &context) override;
};
#endif //TASKMANAGER_SRC_CLI_STATE_H_

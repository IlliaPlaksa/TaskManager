//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_MACHINESTATES_H_
#define TASKMANAGER_SRC_CLI_MACHINESTATES_H_

#include "State.h"

class StartState : public State
{
public:
    const State *Execute(Context &context) override;
};

class HelpState : public State
{
public:
    const State *Execute(Context &context) override;
};

class ExitState : public State
{
public:
    const State *Execute(Context &context) override;
};

class AddState : public State
{
    const State *Execute(Context &context) override;
};

class EditState : public State
{
    const State *Execute(Context &context) override;
};

class CompleteState : public State
{
    const State *Execute(Context &context) override;
};

class DeleteState : public State
{
    const State *Execute(Context &context) override;
};

class ShowState : public State
{
    const State *Execute(Context &context) override;

};
#endif //TASKMANAGER_SRC_CLI_MACHINESTATES_H_

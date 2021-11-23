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
    enum class Status
    {
        kOk = 0,
        kExit,
        kError
    };
public:
    virtual Status Execute(Context &context) = 0;
};

#endif //TASKMANAGER_SRC_CLI_STATE_H_

//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXT_H_
#define TASKMANAGER_SRC_CLI_CONTEXT_H_

#include <memory>
#include <string>
#include <iostream>
#include "State.h"

class Context
{
public:
    void SetState(const std::shared_ptr<State> &p_state);
    State::Status Execute();

    // TODO separate printing
    void WriteLine(const std::string &message);
    std::string ReadLine(const std::string &message = "");

private:
    std::shared_ptr<State> p_current_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXT_H_

//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXT_H_
#define TASKMANAGER_SRC_CLI_CONTEXT_H_

#include <memory>
#include <string>
#include <iostream>
#include "Step.h"

class Context
{
public:
    void SetStep(const std::shared_ptr<Step> &p_state);
    Step::Status Execute();

    // TODO separate printing
    void WriteLine(const std::string &message);
    std::string ReadLine(const std::string &message = "");

private:
    std::shared_ptr<Step> p_current_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXT_H_

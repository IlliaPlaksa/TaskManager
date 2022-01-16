//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEP_H_
#define TASKMANAGER_SRC_CLI_STEP_H_

#include <memory>
#include <sstream>
#include "controller/include/CommandFactory.h"
#include "Readers.h"

class Context;
class Step;

struct StepResult
{
    CommandType command_type;
    std::shared_ptr<Step> next_step;
};

class Step
{
public:
    virtual StepResult Execute(Context& context) = 0;
public:
    virtual ~Step() = default;
};

#endif //TASKMANAGER_SRC_CLI_STEP_H_

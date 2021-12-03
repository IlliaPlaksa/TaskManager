//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEP_H_
#define TASKMANAGER_SRC_CLI_STEP_H_

#include <memory>
#include <sstream>
#include "../../controller/include/OperationType.h"
#include "ConsoleManipulator.h"
#include "Readers.h"

class Context;
class StepFactory;
class Step;

struct StepResult
{
    OperationType operation;
    std::shared_ptr<Step> next_step;
};

class Step
{
public:
    virtual StepResult Execute(Context &context, StepFactory& factory) = 0;

public:
    explicit Step(const std::shared_ptr<ConsoleManipulator> &console_manipulator);

public:
    ConsoleManipulator &GetConsoleManipulator();

private:
    std::shared_ptr<ConsoleManipulator> console_manipulator_;
};

#endif //TASKMANAGER_SRC_CLI_STEP_H_

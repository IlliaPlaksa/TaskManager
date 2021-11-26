//
// Created by Illia Plaksa on 23.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEPFACTORY_H_
#define TASKMANAGER_SRC_CLI_STEPFACTORY_H_

#include "Step.h"

enum class StepId
{
    kNone,
    kRoot,
    kHelp,
    kExit,
    kAdd,
    kEdit,
    kComplete,
    kDelete,
    kShow,
};

class StepFactory
{
public:
    std::shared_ptr<Step> CreateStep(StepId step_id);

public:
    StepFactory();
private:
    std::shared_ptr<ConsoleManipulator> console_manipulator_;
};

#endif //TASKMANAGER_SRC_CLI_STEPFACTORY_H_

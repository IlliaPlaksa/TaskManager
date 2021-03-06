//
// Created by Illia Plaksa on 10.01.2022.
//

#ifndef TASKMANAGER_SRC_CLI_STEPDEPENDENCY_H_
#define TASKMANAGER_SRC_CLI_STEPDEPENDENCY_H_

#include "Step.h"
#include "StepFactory.h"

class StepDependency
{
public:
    StepDependency(const std::shared_ptr<StepFactory>& factory,
                   const std::shared_ptr<ConsoleManipulator>& console_manipulator);

public:
    virtual std::shared_ptr<ConsoleManipulator> console_manipulator();
    virtual std::shared_ptr<StepFactory> step_factory();

public:
    virtual ~StepDependency() = default;
private:
    std::shared_ptr<ConsoleManipulator> console_manipulator_;
    std::shared_ptr<StepFactory> factory_;
};

#endif //TASKMANAGER_SRC_CLI_STEPDEPENDENCY_H_

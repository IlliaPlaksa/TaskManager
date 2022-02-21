//
// Created by Illia Plaksa on 23.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEPFACTORY_H_
#define TASKMANAGER_SRC_CLI_STEPFACTORY_H_

#include "Step.h"
#include "StepId.h"

class StepFactory : public std::enable_shared_from_this<StepFactory>
{
public:
    virtual std::shared_ptr<Step> CreateStep(StepId step_id);

public:
    virtual std::shared_ptr<StepFactory> shared();
public:
    explicit StepFactory(const std::shared_ptr<ConsoleManipulator>& console_manipulator);

public:
    virtual ~StepFactory() = default;
private:
    std::shared_ptr<ConsoleManipulator> console_manipulator_;
};

#endif //TASKMANAGER_SRC_CLI_STEPFACTORY_H_

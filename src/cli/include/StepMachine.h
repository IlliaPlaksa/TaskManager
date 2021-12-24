//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEPMACHINE_H_
#define TASKMANAGER_SRC_CLI_STEPMACHINE_H_

#include <optional>
#include "../../controller/include/View.h"
#include "../../controller/include/Controller.h"
#include "Context.h"
#include "Step.h"
#include "MachineSteps.h"

class StepMachine : public View
{
public:
    void Run() override;

public:
    explicit StepMachine(const std::shared_ptr<StepFactory>& step_factory,
                         const std::shared_ptr<Controller>& controller,
                         const std::shared_ptr<CommandFactory>& command_factory);
private:
    void SetNextStep(const std::shared_ptr<Step>& step);

private:
    Context context_;
    std::shared_ptr<Step> current_step_;

    std::shared_ptr<StepFactory> step_factory_;
    std::shared_ptr<CommandFactory> command_factory_;
    std::shared_ptr<Controller> controller_;
};

#endif //TASKMANAGER_SRC_CLI_STEPMACHINE_H_

//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEPMACHINE_H_
#define TASKMANAGER_SRC_CLI_STEPMACHINE_H_

#include <optional>
#include "../../controller/include/IView.h"
#include "../../controller/include/Controller.h"
#include "Context.h"
#include "Step.h"
#include "MachineSteps.h"

class StepMachine : public IView
{
public:
    void Run() override;

public:
    std::optional<TaskStruct> GetTaskStruct() const override;

public:
    explicit StepMachine(const std::shared_ptr<StepFactory> &factory,
                         const std::shared_ptr<Controller> &controller);

private:
    void SetNextStep(const std::shared_ptr<Step> &step);

private:
    Context context_;
    std::shared_ptr<StepFactory> factory_;
    std::shared_ptr<Step> current_step_;

    std::shared_ptr<Controller> controller_;
};

#endif //TASKMANAGER_SRC_CLI_STEPMACHINE_H_

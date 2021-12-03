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

class StepMachine : public IView, std::enable_shared_from_this<IView>
{
public:
    void Run() override;

public:
    std::optional<Task> GetTask() override;
    std::optional<TaskId> GetTaskId() override;
    std::optional<TaskId> GetParentTaskId() override;

public:
    explicit StepMachine(const std::shared_ptr<Controller> &controller);

private:
    void SetNextStep(const std::shared_ptr<Step> &step);
    std::shared_ptr<IView> getSharedFromThis();

private:
    Context context_;
    StepFactory factory_;
    std::shared_ptr<Step> current_step_;

    std::shared_ptr<Controller> controller_;
};

#endif //TASKMANAGER_SRC_CLI_STEPMACHINE_H_

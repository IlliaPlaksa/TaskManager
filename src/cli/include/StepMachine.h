//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STEPMACHINE_H_
#define TASKMANAGER_SRC_CLI_STEPMACHINE_H_

#include <optional>
#include "common/include/View.h"
#include "controller/include/ModelController.h"
#include "Context.h"
#include "Step.h"
#include "MachineSteps.h"

class StepMachine : public View
{
public:
    explicit StepMachine(const std::shared_ptr<StepFactory>& step_factory,
                         const std::shared_ptr<ModelController>& controller);
public:
    void Run() override;

public:
    ~StepMachine() override = default;

private:
    void SetNextStep(const std::shared_ptr<Step>& step);
    void SetContextFromCommandResponse(const CommandResponse& response);

private:
    static std::string CreateErrorMessage(const ModelResponse::ErrorType& error_type);

private:
    Context context_;
    std::shared_ptr<Step> current_step_;

    std::shared_ptr<StepFactory> step_factory_;
    std::shared_ptr<ModelController> controller_;
};

#endif //TASKMANAGER_SRC_CLI_STEPMACHINE_H_

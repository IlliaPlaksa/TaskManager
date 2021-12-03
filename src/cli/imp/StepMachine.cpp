//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/StepMachine.h"

StepMachine::StepMachine(const std::shared_ptr<Controller> &controller)
    : controller_(controller) {}

void StepMachine::Run()
{
    this->context_ = Context();
    auto initial_step = factory_.CreateStep(StepId::kRoot);
    this->SetNextStep(initial_step);

    while (current_step_)
    {
        auto result = current_step_->Execute(context_, factory_);

        SetNextStep(result.next_step);
        controller_->Action(getSharedFromThis(),
                            result.operation);
    }
}

std::optional<Task> StepMachine::GetTask()
{
    auto task_struct = this->context_.GetStruct();

    if (task_struct->IsReadyToConstruct())
        return task_struct->ConstructTask();
    else
        return std::nullopt;
}
std::optional<TaskId> StepMachine::GetTaskId()
{
    return *context_.GetTaskId();
}
std::optional<TaskId> StepMachine::GetParentTaskId()
{
    return *context_.GetParentTaskId();
}

void StepMachine::SetNextStep(const std::shared_ptr<Step> &step)
{
    this->current_step_ = step;
}
std::shared_ptr<IView> StepMachine::getSharedFromThis()
{
    return shared_from_this();
}

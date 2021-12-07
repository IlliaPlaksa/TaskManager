//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/StepMachine.h"

StepMachine::StepMachine(const std::shared_ptr<StepFactory> &factory,
                         const std::shared_ptr<Controller> &controller)
    :
    factory_(factory),
    controller_(controller)
{

}

void StepMachine::Run()
{
    this->context_ = Context();
    auto initial_step = factory_->CreateStep(StepId::kRoot);
    this->SetNextStep(initial_step);

    while (current_step_)
    {
        auto result = current_step_->Execute(context_);

        SetNextStep(result.next_step);
        controller_->Action(*this, result.operation);
    }
}

std::optional<Task> StepMachine::GetTask() const
{
    auto task_struct = this->context_.GetStruct();

    if (task_struct->IsReadyToConstruct())
        return task_struct->ConstructTask();
    else
        return std::nullopt;
}
std::optional<TaskId> StepMachine::GetTaskId() const
{
    return *context_.GetTaskId();
}
std::optional<TaskId> StepMachine::GetParentTaskId() const
{
    return *context_.GetParentTaskId();
}

void StepMachine::SetNextStep(const std::shared_ptr<Step> &step)
{
    this->current_step_ = step;
}

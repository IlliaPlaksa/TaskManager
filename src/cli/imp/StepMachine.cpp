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

std::optional<TaskStruct> StepMachine::GetTaskStruct() const
{
    auto task_struct = context_.GetStruct();

    if (task_struct->IsReadyToConstruct())
        return *task_struct;
    else
        return std::nullopt;
}

void StepMachine::SetNextStep(const std::shared_ptr<Step> &step)
{
    this->current_step_ = step;
}
void StepMachine::LoadTasks(const TaskStorage &storage)
{
    *context_.GetTaskStorage() = storage;
}

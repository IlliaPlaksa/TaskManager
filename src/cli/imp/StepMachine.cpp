//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/StepMachine.h"

#include "../../util/TaskIdComparers.h"

StepMachine::StepMachine(const std::shared_ptr<StepFactory>& factory,
                         const std::shared_ptr<Controller>& controller)
    :
    step_factory_(factory),
    controller_(controller)
{

}

void StepMachine::Run()
{
    this->context_ = Context();
    auto initial_step = step_factory_->CreateStep(StepId::kRoot);
    this->SetNextStep(initial_step);

    while (current_step_)
    {
        auto result = current_step_->Execute(context_);

        SetNextStep(result.next_step);

        // TODO remove shared from this and pass Context to
        controller_->Action(shared(), result.command_type);
    }
}

std::optional<TaskToSerialize> StepMachine::GetTaskStruct() const
{
    auto task_struct = context_.GetStruct();

    return task_struct->MakeTaskToSerialize();
}

void StepMachine::SetNextStep(const std::shared_ptr<Step>& step)
{
    this->current_step_ = step;
}
void StepMachine::LoadTasks(const TaskStorage& storage)
{
    *context_.GetTaskStorage() = storage;
}
std::shared_ptr<View> StepMachine::shared()
{
    return shared_from_this();
}


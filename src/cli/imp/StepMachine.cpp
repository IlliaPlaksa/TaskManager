//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/StepMachine.h"

void StepMachine::Run()
{
    this->context_ = Context();
    auto initial_step = factory_.CreateStep(StepId::kRoot);
    this->SetNextStep(initial_step);

    while (current_step_)
        this->SetNextStep(current_step_->Execute(context_, factory_));
}
void StepMachine::SetNextStep(const std::shared_ptr<Step> &step)
{
    this->current_step_ = step;
}

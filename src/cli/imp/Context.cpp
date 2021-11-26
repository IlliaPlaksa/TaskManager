//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../headers/Context.h"

void Context::SetStep(const std::shared_ptr<Step> &p_step)
{
    this->step_ = p_step;
}

Step::Status Context::Execute()
{
    if (this->step_)
        return step_->Execute(*this);
    else
        throw std::runtime_error("Current step is not initialized");
}
Context::Context()
    : factory_(std::make_shared<StepFactory>()) {}

std::shared_ptr<StepFactory> Context::GetFactory() { return this->factory_; }

//
// Created by Illia Plaksa on 22.11.2021.
//

#include "Context.h"

void Context::SetStep(const std::shared_ptr<Step> &p_step)
{
    this->step_ = p_step;
}

Step::Status Context::Execute()
{
    return step_->Execute(*this);
}
std::shared_ptr<ConsolePrinter> Context::GetPrinter()
{
    return this->printer_;
}
Context::Context()
{
    this->printer_ = std::make_shared<ConsolePrinter>();
}

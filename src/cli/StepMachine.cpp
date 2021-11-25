//
// Created by Illia Plaksa on 22.11.2021.
//

#include "StepMachine.h"

void StepMachine::Run()
{
    this->context_ = Context();
    auto initial_step = StepFactory::CreateStep(StepId::kRoot);
    this->context_.SetStep(initial_step);

    while (this->context_.Execute() == Step::Status::kOk);
}

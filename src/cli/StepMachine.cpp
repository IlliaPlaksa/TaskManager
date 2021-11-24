//
// Created by Illia Plaksa on 22.11.2021.
//

#include "StepMachine.h"

void StepMachine::Start()
{
    this->context_ = Context();
    auto initial_step = std::shared_ptr<Step>{new RootStep};
    this->context_.SetStep(initial_step);

    while (this->context_.Execute() == Step::Status::kOk);
}

//
// Created by Illia Plaksa on 22.11.2021.
//

#include "StateMachine.h"

void StateMachine::Start()
{
    this->context_ = Context();
    auto initial_state = std::shared_ptr<State>{new StartState};
    this->context_.SetState(initial_state);

    while (this->context_.Execute() == State::Status::kOk);
}

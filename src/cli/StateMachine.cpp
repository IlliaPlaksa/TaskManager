//
// Created by Illia Plaksa on 22.11.2021.
//

#include "StateMachine.h"
void StateMachine::Start()
{
    this->context_ = Context();
    auto p_current_state = std::shared_ptr<State>{new StartState};
    this->context_.SetState(p_current_state);
    do {} while (this->context_.Execute());
}

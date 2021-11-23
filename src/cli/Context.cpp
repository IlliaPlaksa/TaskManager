//
// Created by Illia Plaksa on 22.11.2021.
//

#include "Context.h"

void Context::SetState(const std::shared_ptr<State> &p_state)
{
    this->p_current_ = p_state;
}

State::Status Context::Execute()
{
    return p_current_->Execute(*this);
}
void Context::WriteLine(const std::string &message)
{
    std::cout << message << std::endl;

}
std::string Context::ReadLine(const std::string &message)
{
    std::cout << message << " > ";
    std::string input;
    std::cin >> input;
    return input;
}

//
// Created by Illia Plaksa on 22.11.2021.
//

#include "Context.h"

void Context::SetState(std::shared_ptr<State> p_state)
{
    this->p_current_ = p_state;
}

const State *Context::Execute()
{
    p_current_->Execute(*this);
    return this->p_current_.get();
}
void Context::WriteLine(std::string message)
{
    std::cout << message << std::endl;

}
std::string Context::ReadLine(std::string message)
{
    std::cout << message << " > ";
    std::string input;
    std::cin >> input;
    return input;
}

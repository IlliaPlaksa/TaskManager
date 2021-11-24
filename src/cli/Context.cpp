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

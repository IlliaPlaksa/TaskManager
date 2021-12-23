//
// Created by Illia Plaksa on 25.11.2021.
//

#include "../include/Step.h"

Step::Step(const std::shared_ptr<StepFactory>& factory,
           const std::shared_ptr<ConsoleManipulator>& console_manipulator)
    :
    factory_(factory),
    console_manipulator_(console_manipulator)
{
}

std::shared_ptr<ConsoleManipulator> Step::GetConsoleManipulator()
{
    return this->console_manipulator_;
}
std::shared_ptr<StepFactory> Step::GetFactory()
{
    return this->factory_;
}

//
// Created by Illia Plaksa on 25.11.2021.
//

#include "../include/Step.h"

Step::Step(const std::shared_ptr<ConsoleManipulator> &console_manipulator)
    :
    console_manipulator_(console_manipulator) {}

ConsoleManipulator &Step::GetConsoleManipulator()
{
    return *this->console_manipulator_;
}

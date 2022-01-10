//
// Created by Illia Plaksa on 10.01.2022.
//

#include "../include/StepDependency.h"

StepDependency::StepDependency(const std::shared_ptr<StepFactory>& factory,
                               const std::shared_ptr<ConsoleManipulator>& console_manipulator)
    :
    console_manipulator_(console_manipulator),
    factory_(factory)
{

}
std::shared_ptr<ConsoleManipulator> StepDependency::console_manipulator()
{
    return console_manipulator_;
}
std::shared_ptr<StepFactory> StepDependency::step_factory()
{
    return factory_;
}

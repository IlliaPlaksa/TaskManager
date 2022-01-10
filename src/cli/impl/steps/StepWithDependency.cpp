//
// Created by Illia Plaksa on 10.01.2022.
//

#include "../../include/MachineSteps.h"

StepWithDependency::StepWithDependency(const std::shared_ptr<StepDependency>& dependency)
    :
    dependency_(dependency)
{

}
std::shared_ptr<StepDependency> StepWithDependency::dependency()
{
    return dependency_;
}

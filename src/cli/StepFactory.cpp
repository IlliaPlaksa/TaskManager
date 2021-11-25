//
// Created by Illia Plaksa on 23.11.2021.
//

#include "StepFactory.h"
#include "MachineSteps.h"

std::shared_ptr<Step> StepFactory::CreateStep(StepId step_id)
{
    std::shared_ptr<Step> result;

    switch (step_id)
    {
        case StepId::kRoot:
            result = std::shared_ptr<Step>{new RootStep{this->console_manipulator_}};
            break;
        case StepId::kAdd: result = std::shared_ptr<Step>{new AddStep{this->console_manipulator_}};
            break;
        case StepId::kEdit: result = std::shared_ptr<Step>{new EditStep{this->console_manipulator_}};
            break;
        case StepId::kComplete: result = std::shared_ptr<Step>{new CompleteStep{this->console_manipulator_}};
            break;
        case StepId::kDelete: result = std::shared_ptr<Step>{new DeleteStep{this->console_manipulator_}};
            break;
        case StepId::kShow: result = std::shared_ptr<Step>{new ShowStep{this->console_manipulator_}};
            break;
        case StepId::kExit: result = std::shared_ptr<Step>{new ExitStep{this->console_manipulator_}};
            break;
        case StepId::kHelp: result = std::shared_ptr<Step>{new HelpStep{this->console_manipulator_}};
            break;
        default: result = std::shared_ptr<Step>{nullptr};
            break;
    }
    return result;
}
StepFactory::StepFactory()
    : console_manipulator_(std::make_shared<ConsoleManipulator>()) {}

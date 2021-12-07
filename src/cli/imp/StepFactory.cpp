//
// Created by Illia Plaksa on 23.11.2021.
//

#include "../include/StepFactory.h"
#include "../include/MachineSteps.h"

std::shared_ptr<Step> StepFactory::CreateStep(StepId step_id)
{
    std::shared_ptr<Step> result;

    switch (step_id)
    {
        case StepId::kRoot:
            result = std::shared_ptr<Step>{
                new RootStep{this->shared(),
                             this->console_manipulator_}};
            break;

        case StepId::kAdd:
            result = std::shared_ptr<Step>{
                new AddStep{this->shared(),
                            this->console_manipulator_}};
            break;

        case StepId::kEdit:
            result = std::shared_ptr<Step>{
                new EditStep{this->shared(),
                             this->console_manipulator_}};
            break;
        case StepId::kComplete:
            result = std::shared_ptr<Step>{
                new CompleteStep{this->shared(),
                                 this->console_manipulator_}};
            break;

        case StepId::kDelete:
            result = std::shared_ptr<Step>{
                new DeleteStep{this->shared(),
                               this->console_manipulator_}};
            break;

        case StepId::kShow:
            result = std::shared_ptr<Step>{
                new ShowStep{this->shared(),
                             this->console_manipulator_}};
            break;

        case StepId::kExit:
            result = std::shared_ptr<Step>{
                new ExitStep{this->shared(),
                             this->console_manipulator_}};
            break;

        case StepId::kHelp:
            result = std::shared_ptr<Step>{
                new HelpStep{this->shared(),
                             this->console_manipulator_}};
            break;

        default: result = std::shared_ptr<Step>{nullptr};
            break;
    }
    return result;
}
StepFactory::StepFactory(const std::shared_ptr<ConsoleManipulator>& console_manipulator)
    : console_manipulator_(console_manipulator)
{
}
std::shared_ptr<StepFactory> StepFactory::shared()
{
    return shared_from_this();
}

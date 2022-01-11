//
// Created by Illia Plaksa on 23.11.2021.
//

#include "../include/StepFactory.h"
#include "../include/MachineSteps.h"

std::shared_ptr<Step> StepFactory::CreateStep(StepId step_id)
{
    std::shared_ptr<Step> result;

    auto dependency = std::shared_ptr<StepDependency>{
        new StepDependency(shared(), console_manipulator_)
    };

    switch (step_id)
    {
        case StepId::kRoot:
        {
            result = std::shared_ptr<Step>{
                new RootStep{dependency}};
            break;
        }
        case StepId::kAdd:
        {
            result = std::shared_ptr<Step>{new AddStep{dependency}};
            break;
        }
        case StepId::kEdit:
        {
            result = std::shared_ptr<Step>{new EditStep{dependency}};
            break;
        }
        case StepId::kComplete:
        {
            result = std::shared_ptr<Step>{new CompleteStep{dependency}};
            break;
        }
        case StepId::kDelete:
        {
            result = std::shared_ptr<Step>{new DeleteStep{dependency}};
            break;
        }
        case StepId::kShow:
        {
            result = std::shared_ptr<Step>{new ShowStep{dependency}};
            break;
        }
        case StepId::kUpdate:
        {
            result = std::shared_ptr<Step>{new UpdateStep{dependency}};
            break;
        }
        case StepId::kExit:
        {
            result = std::shared_ptr<Step>{new ExitStep{dependency}};
            break;
        }
        case StepId::kHelp:
        {
            result = std::shared_ptr<Step>{new HelpStep{dependency}};
            break;
        }
        case StepId::kSave:
        {
            result = std::shared_ptr<Step>{new SaveStep{dependency}};
            break;
        }
        case StepId::kLoad:
        {
            result = std::shared_ptr<Step>{new LoadStep{dependency}};
            break;
        }
        case StepId::kError:
        {
            result = std::shared_ptr<Step>{new ErrorStep{dependency}};
            break;
        }
        default:
        {
            result = std::shared_ptr<Step>{nullptr};
            break;
        }
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

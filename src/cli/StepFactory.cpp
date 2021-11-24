//
// Created by Illia Plaksa on 23.11.2021.
//

#include "StepFactory.h"

std::shared_ptr<Step> StepFactory::CreateStep(StepId step_id)
{
    std::shared_ptr<Step> result;
    if (step_id == StepId::kNone)
        result = std::shared_ptr<Step>{nullptr};
    else if (step_id == StepId::kRoot)
        result = std::shared_ptr<Step>{new RootStep};
    else if (step_id == StepId::kExit)
        result = std::shared_ptr<Step>{new ExitStep};
    else if (step_id == StepId::kHelp)
        result = std::shared_ptr<Step>{new HelpStep};
    else if (step_id == StepId::kAdd)
        result = std::shared_ptr<Step>{new AddStep};
    else if (step_id == StepId::kEdit)
        result = std::shared_ptr<Step>{new EditStep};
    else if (step_id == StepId::kComplete)
        result = std::shared_ptr<Step>{new CompleteStep};
    else if (step_id == StepId::kDelete)
        result = std::shared_ptr<Step>{new DeleteStep};
    else if (step_id == StepId::kShow)
        result = std::shared_ptr<Step>{new ShowStep};
    return result;
}

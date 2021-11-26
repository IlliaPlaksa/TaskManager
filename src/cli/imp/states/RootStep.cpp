//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../headers/MachineSteps.h"

Step::Status RootStep::Execute(Context &context)
{
    std::shared_ptr<Step> new_state;

    auto command = this->console_->ReadLine();
    auto step_id = GetIdFromName(command);

    if (step_id != StepId::kNone)
        new_state = context.GetFactory()->CreateStep(step_id);
    else
    {
        this->console_->WriteLine("No such command -> " + command);
        this->console_->WriteLine("Use command [help]");
        new_state = context.GetFactory()->CreateStep(StepId::kRoot);
    }

    context.SetStep(new_state);
    if (new_state)
        return Status::kOk;
    else
        return Status::kError;
}
StepId RootStep::GetIdFromName(const std::string &name)
{
    if (name == "exit")
        return StepId::kExit;
    else if (name == "help")
        return StepId::kHelp;
    else if (name == "add")
        return StepId::kAdd;
    else if (name == "edit")
        return StepId::kEdit;
    else if (name == "complete")
        return StepId::kComplete;
    else if (name == "delete")
        return StepId::kDelete;
    else if (name == "show")
        return StepId::kShow;
    else
        return StepId::kNone;
}

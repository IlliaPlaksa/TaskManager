//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../MachineSteps.h"

Step::Status RootStep::Execute(Context &context)
{
    auto command = context.ReadLine();
    std::shared_ptr<Step> new_state;

    if (command == "exit")
        new_state = std::shared_ptr<Step>{new ExitStep};
    else if (command == "help")
        new_state = std::shared_ptr<Step>{new HelpStep};
    else if (command == "add")
        new_state = std::shared_ptr<Step>{new AddStep};
    else if (command == "edit")
        new_state = std::shared_ptr<Step>{new EditStep};
    else if (command == "complete")
        new_state = std::shared_ptr<Step>{new CompleteStep};
    else if (command == "delete")
        new_state = std::shared_ptr<Step>{new DeleteStep};
    else if (command == "show")
        new_state = std::shared_ptr<Step>{new ShowStep};
    else
    {
        context.WriteLine("No such command -> " + command);
        context.WriteLine("Use command [help]");
        new_state = std::shared_ptr<Step>{new RootStep};
    }
    context.SetStep(new_state);
    if (new_state)
        return Status::kOk;
    else
        return Status::kError;
}
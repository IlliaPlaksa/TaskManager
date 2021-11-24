//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../Step.h"
#include "MachineSteps.h"
#include "../Context.h"

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
Step::Status HelpStep::Execute(Context &context)
{
    std::stringstream output;
    output << "Commands:" << std::endl
           << "help" << std::endl
           << "add" << std::endl
           << "edit" << std::endl
           << "complete" << std::endl
           << "delete" << std::endl
           << "show" << std::endl
           << "exit" << std::endl;

    context.WriteLine(output.str());
    auto new_state = std::shared_ptr<Step>{new RootStep};
    context.SetStep(new_state);
    return Status::kOk;
}
Step::Status ExitStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{nullptr});
    return Status::kExit;
}

// TODO implement all states
Step::Status AddStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{new RootStep});
    return Status::kOk;
}
Step::Status EditStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{new RootStep});
    return Status::kOk;
}
Step::Status CompleteStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{new RootStep});
    return Status::kOk;
}
Step::Status DeleteStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{new RootStep});
    return Status::kOk;
}
Step::Status ShowStep::Execute(Context &context)
{
    context.SetStep(std::shared_ptr<Step>{new RootStep});
    return Status::kOk;
}

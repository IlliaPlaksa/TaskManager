//
// Created by Illia Plaksa on 22.11.2021.
//

#include "State.h"
#include "MachineStates.h"
#include "Context.h"

const State *StartState::Execute(Context &context)
{
    auto command = context.ReadLine();
    std::shared_ptr<State> new_state;

    if (command == "exit")
        new_state = std::shared_ptr<State>{new ExitState};
    else if (command == "help")
        new_state = std::shared_ptr<State>{new HelpState};
    else if (command == "add")
        new_state = std::shared_ptr<State>{new AddState};
    else if (command == "edit")
        new_state = std::shared_ptr<State>{new EditState};
    else if (command == "complete")
        new_state = std::shared_ptr<State>{new CompleteState};
    else if (command == "delete")
        new_state = std::shared_ptr<State>{new DeleteState};
    else if (command == "show")
        new_state = std::shared_ptr<State>{new ShowState};

    else
    {
        context.WriteLine("No such command -> " + command);
        context.WriteLine("Use command [help]");
        new_state = std::shared_ptr<State>{new StartState};
    }
    context.SetState(new_state);
    return new_state.get();
}
const State *HelpState::Execute(Context &context)
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
    auto new_state = std::shared_ptr<State>{new StartState};
    context.SetState(new_state);
    return new_state.get();
}
const State *ExitState::Execute(Context &context)
{
    context.SetState(std::shared_ptr<State>{nullptr});
    return nullptr;
}

// TODO implement all states
const State *AddState::Execute(Context &context)
{
    context.SetState(std::shared_ptr<State>{new StartState});
    return this;
}
const State *EditState::Execute(Context &context)
{
    context.SetState(std::shared_ptr<State>{new StartState});
    return this;
}
const State *CompleteState::Execute(Context &context)
{
    context.SetState(std::shared_ptr<State>{new StartState});
    return this;
}
const State *DeleteState::Execute(Context &context)
{
    context.SetState(std::shared_ptr<State>{new StartState});
    return this;
}
const State *ShowState::Execute(Context &context)
{
    context.SetState(std::shared_ptr<State>{new StartState});
    return this;
}

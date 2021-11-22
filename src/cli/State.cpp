//
// Created by Illia Plaksa on 22.11.2021.
//

#include "State.h"
#include "Context.h"

const State *StartState::Execute(Context &context)
{
    auto command = context.ReadLine();
    std::shared_ptr<State> new_state;

    if (command == "exit")
        new_state = std::shared_ptr<State>{new ExitState};
    else if (command == "help")
        new_state = std::shared_ptr<State>{new HelpState};
    else
    {
        context.WriteLine("No such command -> " + command);
        new_state = std::shared_ptr<State>{new HelpState};
    }
    context.SetState(new_state);
    return new_state.get();
}
const State *HelpState::Execute(Context &context)
{
    std::stringstream output;
    output << "Commands:" << std::endl
           << "help" << std::endl
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

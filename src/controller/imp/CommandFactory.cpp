//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/CommandFactory.h"
CommandFactory::CommandFactory(const std::shared_ptr<IView> &view)
    :
    view_(view)
{
}
std::shared_ptr<Command> CommandFactory::CreateCommand(const CommandType &type)
{
    switch (type)
    {
        case CommandType::kAdd:
        {
            return std::shared_ptr<Command>{new AddCommand{view_}};
        }
        case CommandType::kEdit:
        {
            return std::shared_ptr<Command>{new EditCommand{view_}};
        }
        case CommandType::kComplete:
        {
            return std::shared_ptr<Command>{new CompleteCommand{view_}};
        }
        case CommandType::kDelete:
        {
            return std::shared_ptr<Command>{new DeleteCommand{view_}};
        }
        case CommandType::kShow:
        {
            return std::shared_ptr<Command>{new ShowCommand{view_}};
        }
        default: return std::shared_ptr<Command>{nullptr};
    }
}

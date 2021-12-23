//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/CommandFactory.h"

std::shared_ptr<Command> CommandFactory::CreateCommand(const CommandType& type,
                                                       const std::shared_ptr<Model>& model)
{
    switch (type)
    {
        case CommandType::kAdd:
        {
            return std::shared_ptr<Command>{new AddCommand{model}};
        }
        case CommandType::kEdit:
        {
            return std::shared_ptr<Command>{new EditCommand{model}};
        }
        case CommandType::kComplete:
        {
            return std::shared_ptr<Command>{new CompleteCommand{model}};
        }
        case CommandType::kDelete:
        {
            return std::shared_ptr<Command>{new DeleteCommand{model}};
        }
        case CommandType::kShow:
        {
            return std::shared_ptr<Command>{new ShowCommand{model}};
        }
        default: return std::shared_ptr<Command>{nullptr};
    }
}

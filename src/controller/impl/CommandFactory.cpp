//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/CommandFactory.h"

std::shared_ptr<Command> CommandFactory::CreateCommand(const CommandType& type,
                                                       const ContextDTO& context)
{
    switch (type)
    {
        case CommandType::kAdd:
        {
            return std::shared_ptr<Command>{new AddCommand{context}};
        }
        case CommandType::kEdit:
        {
            return std::shared_ptr<Command>{new EditCommand{context}};
        }
        case CommandType::kComplete:
        {
            return std::shared_ptr<Command>{new CompleteCommand{context}};
        }
        case CommandType::kDelete:
        {
            return std::shared_ptr<Command>{new DeleteCommand{context}};
        }
        case CommandType::kShow:
        {
            return std::shared_ptr<Command>{new ShowCommand{context}};
        }
        default: return std::shared_ptr<Command>{nullptr};
    }
}

//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_COMMANDFACTORY_H_
#define TASKMANAGER_SRC_CONTROLLER_COMMANDFACTORY_H_

#include <memory>
#include "common/include/Command.h"
#include "ConcreteCommands.h"
#include "ContextDTO.h"

enum class CommandType
{
    kNone,
    kAdd,
    kEdit,
    kComplete,
    kDelete,
    kShow,
    kSave,
    kLoad
};

class CommandFactory
{
public:
    explicit CommandFactory() = default;
public:
    virtual std::shared_ptr<Command> CreateCommand(const CommandType& type,
                                                   const std::shared_ptr<ContextDTO>& context);
};

#endif //TASKMANAGER_SRC_CONTROLLER_COMMANDFACTORY_H_

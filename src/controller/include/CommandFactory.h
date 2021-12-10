//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_COMMANDFACTORY_H_
#define TASKMANAGER_SRC_CONTROLLER_COMMANDFACTORY_H_

#include <memory>
#include "Command.h"
#include "IView.h"
#include "ConcreteCommands.h"

enum class CommandType
{
    kNone,
    kAdd,
    kEdit,
    kComplete,
    kDelete,
    kShow,
};

class CommandFactory
{
public:
    explicit CommandFactory(const std::shared_ptr<IView> &view);
public:
    std::shared_ptr<Command> CreateCommand(const CommandType &type);

private:
    std::shared_ptr<IView> view_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_COMMANDFACTORY_H_

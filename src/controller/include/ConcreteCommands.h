//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_CONCRETECOMMANDS_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_CONCRETECOMMANDS_H_

#include "Command.h"

class AddCommand : public Command
{
    using Command::Command;
public:
    Response Execute(const std::shared_ptr<IModel> &model);
};


class EditCommand : public Command
{
    using Command::Command;
public:
    Response Execute(const std::shared_ptr<IModel> &model);
};

class CompleteCommand : public Command
{
    using Command::Command;
public:
    Response Execute(const std::shared_ptr<IModel> &model);
};

class DeleteCommand : public Command
{
    using Command::Command;
public:
    Response Execute(const std::shared_ptr<IModel> &model);
};

class ShowCommand : public Command
{
    // TODO Add constructor with filter params
    using Command::Command;
public:
    Response Execute(const std::shared_ptr<IModel> &model);
};
#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_CONCRETECOMMANDS_H_

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
    Model::Response Execute(const std::shared_ptr<View> &view) override;
};

class EditCommand : public Command
{
    using Command::Command;
public:
    Model::Response Execute(const std::shared_ptr<View> &view) override;
};

class CompleteCommand : public Command
{
    using Command::Command;
public:
    Model::Response Execute(const std::shared_ptr<View> &view) override;

};

class DeleteCommand : public Command
{
    using Command::Command;
public:
    Model::Response Execute(const std::shared_ptr<View> &view) override;

};

class ShowCommand : public Command
{
    // TODO Add constructor with filter params
    using Command::Command;
public:
    Model::Response Execute(const std::shared_ptr<View> &view) override;

};
#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_CONCRETECOMMANDS_H_

//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_

#include "Command.h"
#include "ContextDTO.h"

class CommandWithContext : public Command
{
public:
    explicit CommandWithContext(const ContextDTO& context);
public:
    ContextDTO GetContext();
public:
    virtual Model::Response Execute(const std::shared_ptr<Model>& model) override;

private:
    ContextDTO context_;
};

class AddCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
};

class EditCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
};

class CompleteCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;

};

class DeleteCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;

};

class ShowCommand : public CommandWithContext
{
    // TODO Add constructor with filter params
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;

};
#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_

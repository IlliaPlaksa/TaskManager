//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_

#include "common/include/Command.h"
#include "ContextDTO.h"
#include "Task.pb.h"
#include "TaskDTO.pb.h"
#include "TaskId.pb.h"
#include "persistence/include/FilePersister.h"

// Abstract class of command with context
class CommandWithContext : public Command
{
public:
    explicit CommandWithContext(const std::shared_ptr<ContextDTO>& context);

public:
    void SetContext(const ContextDTO& context);
public:
    std::shared_ptr<ContextDTO> GetContext() const;

public:
    ~CommandWithContext() override = default;
private:
    std::shared_ptr<ContextDTO> context_;
};

class AddCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
public:
    bool IsReady() const override;

};

class EditCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
public:
    bool IsReady() const override;
};

class CompleteCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
public:
    bool IsReady() const override;
};

class DeleteCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
public:
    bool IsReady() const override;
};

class ShowCommand : public CommandWithContext
{
    // TODO Add constructor with filter params
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
public:
    bool IsReady() const override;
};

class SaveCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
public:
    bool IsReady() const override;
};

class LoadCommand : public CommandWithContext
{
    using CommandWithContext::CommandWithContext;
public:
    Model::Response Execute(const std::shared_ptr<Model>& model) override;
public:
    bool IsReady() const override;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_

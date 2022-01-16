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

class AddCommand : public Command
{
    explicit AddCommand(const Task& task, const std::optional<TaskId>& parent_id);
public:
    CommandResponse Execute(const std::shared_ptr<Model>& model) override;

private:
    Task task_;
    std::optional<TaskId> parent_id_;
};

class EditCommand : public Command
{
    explicit EditCommand(const TaskId& id, const Task& task, const std::optional<TaskId>& parent_id);
public:
    CommandResponse Execute(const std::shared_ptr<Model>& model) override;

private:
    TaskId id_;
    Task task_;
    std::optional<TaskId> parent_id_;
};

class CompleteCommand : public Command
{
    explicit CompleteCommand(const TaskId& id);
public:
    CommandResponse Execute(const std::shared_ptr<Model>& model) override;

private:
    TaskId id_;
};

class DeleteCommand : public Command
{
    explicit DeleteCommand(const TaskId& id);
public:
    CommandResponse Execute(const std::shared_ptr<Model>& model) override;

private:
    TaskId id_;
};

class ShowCommand : public Command
{
    // TODO Add constructor with filter params
    explicit ShowCommand() = default;
public:
    CommandResponse Execute(const std::shared_ptr<Model>& model) override;
};

class SaveCommand : public Command
{
    explicit SaveCommand(const std::string& file_name);
public:
    CommandResponse Execute(const std::shared_ptr<Model>& model) override;

private:
    std::string file_name_;
};

class LoadCommand : public Command
{
    explicit LoadCommand(const std::string& file_name);
public:
    CommandResponse Execute(const std::shared_ptr<Model>& model) override;
    
private:
    std::string file_name_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_

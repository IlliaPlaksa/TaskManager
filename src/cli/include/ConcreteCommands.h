//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_

#include "common/include/Command.h"
#include "Task.pb.h"
#include "TaskDTO.pb.h"
#include "TaskId.pb.h"

#include "Logging.h"

class AddCommand : public Command
{
public:
    explicit AddCommand(const Task& task, const std::optional<TaskId>& parent_id);
public:
    CommandResponse Execute(const std::shared_ptr<ModelController>& model) override;

private:
    Task task_;
    std::optional<TaskId> parent_id_;
};

class EditCommand : public Command
{
public:
    explicit EditCommand(const TaskId& id, const Task& task, const std::optional<TaskId>& parent_id);
public:
    CommandResponse Execute(const std::shared_ptr<ModelController>& model) override;

private:
    TaskId id_;
    Task task_;
    std::optional<TaskId> parent_id_;
};

class CompleteCommand : public Command
{
public:
    explicit CompleteCommand(const TaskId& id);
public:
    CommandResponse Execute(const std::shared_ptr<ModelController>& model) override;

private:
    TaskId id_;
};

class DeleteCommand : public Command
{
public:
    explicit DeleteCommand(const TaskId& id);
public:
    CommandResponse Execute(const std::shared_ptr<ModelController>& model) override;

private:
    TaskId id_;
};

class ShowCommand : public Command
{
public:
    explicit ShowCommand(const std::optional<std::string>& label);
public:
    CommandResponse Execute(const std::shared_ptr<ModelController>& model) override;

private:
    std::optional<std::string> label_;
};

class SaveCommand : public Command
{
public:
    explicit SaveCommand(const std::string& file_name);
public:
    CommandResponse Execute(const std::shared_ptr<ModelController>& model) override;

private:
    std::string file_name_;
};

class LoadCommand : public Command
{
public:
    explicit LoadCommand(const std::string& file_name);
public:
    CommandResponse Execute(const std::shared_ptr<ModelController>& model) override;

private:
    std::string file_name_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_CommandWithContextS_H_

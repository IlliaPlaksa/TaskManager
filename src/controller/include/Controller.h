//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_
#define TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "common/include/View.h"
#include "common/include/Model.h"
#include "common/include/Command.h"
#include "CommandFactory.h"

class Controller
{
public:
    class Response;
public:
    explicit Controller(const std::shared_ptr<Model>& model);

public:
    Response Action(const std::shared_ptr<Command>& command);

private:
    static std::string CreateErrorMessage(const Model::Response::ErrorType& error_type);

private:
    std::shared_ptr<Model> model_;
    std::shared_ptr<CommandFactory> command_factory_;
};

class Controller::Response
{
public:
    enum class Status
    {
        kSuccess,
        kError
    };
public:
    static Response CreateSuccess();
    static Response CreateError(const std::string& message);

private:
    Response() = default;

public: // Methods
    bool IsError();

public:
    std::optional<std::string> error();
    Status status();

private: // Fields
    Status status_;
    std::optional<std::string> error_message_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

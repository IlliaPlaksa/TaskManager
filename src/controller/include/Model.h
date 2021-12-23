//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_

#include <vector>
#include <optional>

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskToSerialize.pb.h"

class Model
{
public:
    class Response;
public:
    virtual Response Add(const Task& task) = 0;
    virtual Response AddSubTask(const Task& task, const TaskId& parent_id) = 0;
    virtual Response Edit(const TaskId& task_id, const Task& task) = 0;
    virtual Response EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id) = 0;
    virtual Response Complete(const TaskId& task_id) = 0;
    virtual Response Delete(const TaskId& task_id) = 0;

public:
    virtual std::vector<TaskToSerialize> Show() = 0;
    virtual std::vector<TaskToSerialize> ShowParents() = 0;
    virtual std::vector<TaskToSerialize> ShowChild(const TaskId& parent_id) = 0;

public:
    virtual bool Load(const std::vector<TaskToSerialize>& tasks) = 0;
};

class Model::Response
{
public:
    enum class ErrorType
    {
        INVALID_ID,
        EMPTY_TITLE,
        NON_EXISTING_PARENT_ID,
        SUBTASKS_IS_NOT_COMPLETED,
        // TODO add more error types
    };

    enum class Status
    {
        kSuccess,
        kError
    };
public:
    static Response CreateSuccess();
    static Response CreateError(const ErrorType& error_type);

private:
    Response() = default;

public: // Methods
    bool IsError();

public:
    std::optional<ErrorType> error();
    Status status();

private: // Fields
    Status status_;
    std::optional<ErrorType> error_type_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_

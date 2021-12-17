//
// Created by Illia Plaksa on 12.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_RESPONSE_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_RESPONSE_H_

#include <optional>
#include <string>

class Response
{
public:
    enum class Status
    {
        kNone,
        kSuccess,
        kError
    };
public:
    Response();
public: // Methods
    bool IsError();

public:
    void SetStatus(Status status);
    void SetErrorMessage(const std::string &message);

public:
    std::optional<std::string> error();
    Status status();

private: // Fields
    Status status_;
    std::optional<std::string> error_message_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_RESPONSE_H_

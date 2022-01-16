//
// Created by Illia Plaksa on 16.01.2022.
//

#ifndef TASKMANAGER_SRC_COMMON_INCLUDE_MODELRESPONSE_H_
#define TASKMANAGER_SRC_COMMON_INCLUDE_MODELRESPONSE_H_

#include "common/include/Model.h"

class ModelResponse
{
public:
    enum class ErrorType
    {
        INVALID_ID,
        EMPTY_TITLE,
        NON_EXISTING_PARENT_ID,
        NOT_COMPLETED_SUBTASKS,
        FAIL,
        // TODO add more error types
    };

    enum class Status
    {
        kSuccess,
        kError
    };
public:
    static ModelResponse CreateSuccess();
    static ModelResponse CreateError(const ErrorType& error_type);

private:
    ModelResponse() = default;

public: // Methods
    bool IsError() const;

public:
    std::optional<ErrorType> error() const;
    Status status() const;

private: // Fields
    Status status_;
    std::optional<ErrorType> error_type_;
};

#endif //TASKMANAGER_SRC_COMMON_INCLUDE_MODELRESPONSE_H_

//
// Created by Illia Plaksa on 16.01.2022.
//

#ifndef TASKMANAGER_SRC_COMMON_INCLUDE_MODELRESPONSE_H_
#define TASKMANAGER_SRC_COMMON_INCLUDE_MODELRESPONSE_H_

#include <optional>

/**
 * @brief \b Represents response to a request to the \b Model
 * @details Provides a representation of all responses to requests to the \b Model
 * @author Plaksa Illia
 */
class ModelResponse
{
public:

    /**
    * @brief \b Represents type of \b Errors that can be caused by request to \b Model
    */
    enum class ErrorType
    {
        INVALID_ID,
        EMPTY_TITLE,
        NON_EXISTING_PARENT_ID,
        NOT_COMPLETED_SUBTASKS,
        FAIL,
        // TODO add more error types
    };

    /**
    * @brief \b Represents status of \b Response of \b Model
    */
    enum class Status
    {
        kSuccess,
        kError
    };
public:
    static ModelResponse Success();
    static ModelResponse Error(const ErrorType& error_type);

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

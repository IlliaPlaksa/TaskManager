//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_CONTEXT_H_
#define TASKMANAGER_SRC_CLI_CONTEXT_H_

#include <memory>
#include "Step.h"
#include "StepFactory.h"
#include "TaskStorage.h"

class Context
{
public:
    std::shared_ptr<TaskStorage> GetStorage() const;
    std::optional<std::string> GetError() const;

public:
    void SetError(const std::string& message);

public:
    Context();

private:
    std::shared_ptr<TaskStorage> task_storage_;
    std::optional<std::string> error_message_;
};

#endif //TASKMANAGER_SRC_CLI_CONTEXT_H_

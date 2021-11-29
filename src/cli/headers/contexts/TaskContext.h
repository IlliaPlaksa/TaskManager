//
// Created by Illia Plaksa on 29.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_HEADERS_CONTEXTS_TASKCONTEXT_H_
#define TASKMANAGER_SRC_CLI_HEADERS_CONTEXTS_TASKCONTEXT_H_

#include "../Context.h"
#include "../TaskStruct.h"

class TaskContext : public Context
{
public:
    TaskContext();
public:
    std::shared_ptr<TaskStruct> GetStruct();
private:
    std::shared_ptr<TaskStruct> task_struct_;
};

#endif //TASKMANAGER_SRC_CLI_HEADERS_CONTEXTS_TASKCONTEXT_H_

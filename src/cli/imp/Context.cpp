//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/Context.h"

Context::Context()
    :
    task_struct_(std::make_shared<TaskToSerialize>()),
    task_storage_(std::make_shared<TaskStorage>())
{
}

std::shared_ptr<TaskToSerialize> Context::GetStruct() const
{
    return this->task_struct_;
}
std::shared_ptr<TaskStorage> Context::GetTaskStorage() const
{
    return this->task_storage_;
}

//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/Context.h"

Context::Context()
    : task_struct_(std::make_shared<TaskStruct>()) {}

std::shared_ptr<TaskStruct> Context::GetStruct()
{ return this->task_struct_; }
std::shared_ptr<TaskId> Context::GetTaskId()
{ return this->task_id_; }

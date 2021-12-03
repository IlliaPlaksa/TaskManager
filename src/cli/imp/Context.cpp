//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/Context.h"

Context::Context()
    : task_struct_(std::make_shared<TaskStruct>()),
      task_id_(std::make_shared<TaskId>(TaskId::CreateDefault())),
      parent_id_(std::make_shared<TaskId>(TaskId::CreateDefault())) {}

std::shared_ptr<TaskStruct> Context::GetStruct() const { return this->task_struct_; }
std::shared_ptr<TaskId> Context::GetTaskId() const { return this->task_id_; }
std::shared_ptr<TaskId> Context::GetParentTaskId() const { return this->parent_id_; }

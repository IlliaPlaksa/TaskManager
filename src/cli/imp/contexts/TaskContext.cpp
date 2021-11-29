//
// Created by Illia Plaksa on 29.11.2021.
//

#include "../../headers/contexts/TaskContext.h"

TaskContext::TaskContext()
    :
    task_struct_(std::make_shared<TaskStruct>()) {}
std::shared_ptr<TaskStruct> TaskContext::GetStruct()
{
    return this->task_struct_;
}

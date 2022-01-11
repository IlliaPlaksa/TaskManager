//
// Created by Illia Plaksa on 23.12.2021.
//

#include "../include/ContextDTO.h"
VariableSet ContextDTO::variable_set() const
{
    return this->variable_set_;
}
std::vector<TaskDTO> ContextDTO::tasks() const
{
    return this->task_storage_;
}
ContextDTO ContextDTO::Create(const VariableSet& variable_set, const std::vector<TaskDTO>& storage)
{
    auto result = ContextDTO{};
    result.variable_set_ = variable_set;
    result.task_storage_ = storage;

    return result;
}
void ContextDTO::Clear()
{
    variable_set_.Clear();
    task_storage_.clear();
}

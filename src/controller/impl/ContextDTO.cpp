//
// Created by Illia Plaksa on 23.12.2021.
//

#include "../include/ContextDTO.h"
VariableSet ContextDTO::variable_set() const
{
    return this->variable_set_;
}
std::vector<TaskDTO> ContextDTO::storage() const
{
    return this->storage_;
}
ContextDTO ContextDTO::Create(const VariableSet& variable_set, const std::vector<TaskDTO>& storage)
{
    auto result = ContextDTO{};
    result.variable_set_ = variable_set;
    result.storage_ = storage;

    return result;
}

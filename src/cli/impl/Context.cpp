//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/Context.h"

Context::Context()
    :
    variable_set_(std::shared_ptr<VariableSet>{new VariableSet}),
    storage_(std::make_shared<TaskStorage>())
{
}
std::shared_ptr<VariableSet> Context::GetVariableSet() const
{
    return this->variable_set_;
}

std::shared_ptr<TaskStorage> Context::GetStorage() const
{
    return this->storage_;
}
bool Context::SetFromContextDTO(const ContextDTO& context_dto)
{
    *variable_set_ = context_dto.variable_set();
    this->storage_->LoadTasks(context_dto.storage());
    return false;
}
ContextDTO Context::GetContextDTO()
{
    return ContextDTO::Create(*variable_set_, storage_->GetTasks());
}

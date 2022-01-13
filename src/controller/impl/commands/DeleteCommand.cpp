//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Model::Response DeleteCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto context = this->GetContext();
    auto var_set = context->variable_set();

    return model->Delete(var_set.id);
}
bool DeleteCommand::IsReady() const
{
    auto task_dto = GetContext()->variable_set().MakeTaskDTO();

    return task_dto.has_value()
        and task_dto->id().IsInitialized();
}

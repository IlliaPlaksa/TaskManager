//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"
#include "../../../util/TaskCreators.h"

Model::Response AddCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto context = this->GetContext();
    auto var_set = context.variable_set();

    auto task = CreateTask(var_set.title,
                           var_set.date,
                           var_set.priority,
                           var_set.label,
                           var_set.status);

    if (var_set.parent_id.has_value())
        return model->AddSubTask(*task, *var_set.parent_id);
    else
        return model->Add(*task);
}

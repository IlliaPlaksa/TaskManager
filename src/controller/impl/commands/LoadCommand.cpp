//
// Created by Illia Plaksa on 10.01.2022.
//

#include "../../include/ConcreteCommands.h"


Model::Response LoadCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto context = this->GetContext();
    auto var_set = context->variable_set();

    auto persister = TaskPersister{};

    auto tasks = persister.DeserializeTasksFromFile(var_set.file_name);

    if (tasks.has_value())
        return model->Load(*tasks);
    else
        return Model::Response::CreateError(Model::Response::ErrorType::FAIL);
}
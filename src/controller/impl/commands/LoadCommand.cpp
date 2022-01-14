//
// Created by Illia Plaksa on 10.01.2022.
//

#include "../../include/ConcreteCommands.h"


Model::Response LoadCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto context = this->GetContext();
    auto var_set = context->variable_set();

    auto persister = FilePersister{var_set.file_name};

    auto tasks = persister.Load();

    if (tasks.has_value())
        return model->Load(*tasks);
    else
        return Model::Response::CreateError(Model::Response::ErrorType::FAIL);
}
bool LoadCommand::IsReady() const
{
    auto variable_set = GetContext()->variable_set();
    return !variable_set.file_name.empty();
}

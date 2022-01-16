//
// Created by Illia Plaksa on 10.01.2022.
//

#include "../../include/ConcreteCommands.h"

Model::Response SaveCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto context = this->GetContext();
    auto var_set = context->variable_set();

    auto persister = FilePersister{var_set.file_name};

    if (persister.Save(model->Show()))
        return Model::Response::CreateSuccess();
    else
        return Model::Response::CreateError(Model::Response::ErrorType::FAIL);
}
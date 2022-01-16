//
// Created by Illia Plaksa on 10.01.2022.
//

#include "../../include/ConcreteCommands.h"

CommandResponse LoadCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto result = CommandResponse{};

    auto persister = FilePersister{file_name_};
    auto tasks = persister.Load();

    if (tasks.has_value())
        result.model_response = model->Load(*tasks);
    else
        result.model_response = ModelResponse::CreateError(ModelResponse::ErrorType::FAIL);

    return result;
}
LoadCommand::LoadCommand(const std::string& file_name)
    :
    file_name_(file_name)
{
}


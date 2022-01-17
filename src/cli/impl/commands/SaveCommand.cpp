//
// Created by Illia Plaksa on 10.01.2022.
//

#include "cli/include/ConcreteCommands.h"

CommandResponse SaveCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto result = CommandResponse{};

    auto persister = FilePersister{file_name_};

    if (persister.Save(model->Show()))
        result.model_response = ModelResponse::Success();
    else
        result.model_response = ModelResponse::Error(ModelResponse::ErrorType::FAIL);

    return result;
}
SaveCommand::SaveCommand(const std::string& file_name)
    :
    file_name_(file_name)
{
}

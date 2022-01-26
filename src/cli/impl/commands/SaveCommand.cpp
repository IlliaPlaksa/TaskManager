//
// Created by Illia Plaksa on 10.01.2022.
//

#include "cli/include/ConcreteCommands.h"

CommandResponse SaveCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};

    result.model_response = model->SaveToFile(file_name_);

    return result;
}
SaveCommand::SaveCommand(const std::string& file_name)
    :
    file_name_(file_name)
{
}

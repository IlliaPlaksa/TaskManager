//
// Created by Illia Plaksa on 10.01.2022.
//

#include "cli/ConcreteCommands.h"

CommandResponse LoadCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};

    BOOST_LOG_TRIVIAL(debug) << "Calling LoadFromFile with file name: " << file_name_;

    result.model_response = model->LoadFromFile(file_name_);

    return result;
}
LoadCommand::LoadCommand(const std::string& file_name)
    :
    file_name_(file_name)
{
}


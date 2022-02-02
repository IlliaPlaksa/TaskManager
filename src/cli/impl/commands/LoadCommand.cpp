//
// Created by Illia Plaksa on 10.01.2022.
//

#include "cli/include/ConcreteCommands.h"

CommandResponse LoadCommand::Execute(const std::shared_ptr<ModelController>& model)
{
    auto result = CommandResponse{};

    BOOST_LOG_TRIVIAL(info) << "Calling ModelController's LoadFromFile method in Load command.";
    result.model_response = model->LoadFromFile(file_name_);

    return result;
}
LoadCommand::LoadCommand(const std::string& file_name)
    :
    file_name_(file_name)
{
}


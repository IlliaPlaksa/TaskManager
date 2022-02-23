//
// Created by Illia Plaksa on 16.01.2022.
//

#include "CommandResponse.h"

bool CommandResponse::IsError() const
{
    if (model_response.has_value())
        return model_response->IsError();
    else
        return !tasks.has_value();
}
CommandResponse::CommandResponse()
    :
    model_response(std::nullopt),
    tasks(std::nullopt)
{

}

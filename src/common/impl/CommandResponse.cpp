//
// Created by Illia Plaksa on 16.01.2022.
//

#include "common/include/CommandResponse.h"

bool CommandResponse::IsError() const
{
    if (model_response.has_value())
        return false;
    else
        return model_response->IsError();
}
CommandResponse::CommandResponse()
    :
    model_response(std::nullopt),
    tasks(std::nullopt)
{

}

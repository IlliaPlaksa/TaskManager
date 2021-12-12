//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/Command.h"

Command::Command(const std::shared_ptr<IModel> &model)
    :
    model_(model) {}

std::shared_ptr<IModel> Command::GetModel()
{
    return model_;
}




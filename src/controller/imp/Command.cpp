//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/Command.h"

Command::Command(const std::shared_ptr<Model> &model)
    :
    model_(model) {}

std::shared_ptr<Model> Command::GetModel()
{
    return model_;
}




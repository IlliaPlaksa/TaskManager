//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_COMMAND_H_
#define TASKMANAGER_SRC_CONTROLLER_COMMAND_H_

#include <memory>
#include "Model.h"
#include "View.h"

class Command
{
public:
    virtual Model::Response Execute(const std::shared_ptr<Model>& model) = 0;
public:
    virtual ~Command() = 0;
};
#endif //TASKMANAGER_SRC_CONTROLLER_COMMAND_H_

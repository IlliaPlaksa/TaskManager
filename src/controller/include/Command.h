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
    explicit Command(const std::shared_ptr<Model> &model);
public:
    virtual Model::Response Execute(const std::shared_ptr<View> &view) = 0;

public:
    std::shared_ptr<Model> GetModel();

public:
    virtual ~Command() = default;

private:
    std::shared_ptr<Model> model_;
};
#endif //TASKMANAGER_SRC_CONTROLLER_COMMAND_H_

//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_COMMAND_H_
#define TASKMANAGER_SRC_CONTROLLER_COMMAND_H_

#include <memory>
#include "Model.h"
#include "IView.h"
#include "Response.h"

class Command
{
public:
    explicit Command(const std::shared_ptr<Model> &model);
public:
    virtual Response Execute(const std::shared_ptr<IView> &view) = 0;

public:
    std::shared_ptr<Model> GetModel();

public:
    virtual ~Command() = default;

private:
    std::shared_ptr<Model> model_;
};
#endif //TASKMANAGER_SRC_CONTROLLER_COMMAND_H_

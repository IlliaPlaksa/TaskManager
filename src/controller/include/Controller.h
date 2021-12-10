//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_
#define TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"
#include "IView.h"
#include "IModel.h"
#include "Command.h"
#include "OperationType.h"

class Controller
{
public:
    Command::Response Action(const std::shared_ptr<Command> &command);

public:
    explicit Controller(const std::shared_ptr<IModel> &model);

private:
    std::shared_ptr<IModel> model_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

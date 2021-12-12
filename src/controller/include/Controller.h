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
#include "CommandFactory.h"
#include "Response.h"

class Controller
{
public:
    explicit Controller(const std::shared_ptr<IModel> &model,
                        const std::shared_ptr<CommandFactory> &command_factory);

public:
    Response Action(const std::shared_ptr<IView> &view,
                    const CommandType &command_type);

private:
    std::shared_ptr<IModel> model_;
    std::shared_ptr<CommandFactory> command_factory_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_
#define TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

#include "../../model/include/Task.h"
#include "../../model/include/TaskId.h"
#include "IView.h"
#include "IModel.h"
#include "OperationType.h"

class Controller
{
public:
    void Action(const IView &view,
                const OperationType &operation);

    // TODO add Show methods
public:
    explicit Controller(const std::shared_ptr<IModel> &model);
private:
    std::shared_ptr<IModel> model_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

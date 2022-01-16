//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_
#define TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "common/include/Model.h"

class ModelController : public Model
{
public:
    class Response;
public:
    explicit ModelController(const std::shared_ptr<Model>& model);

private:
    std::shared_ptr<Model> model_;
};
#endif //TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

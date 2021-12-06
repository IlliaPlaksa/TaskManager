//
// Created by Illia Plaksa on 03.12.2021.
//

#include "../include/Controller.h"
Controller::Controller(const std::shared_ptr<IModel> &model)
    :
    model_(model) {}

// TODO change return value
void Controller::Action(const IView &view,
                        const OperationType &operation)
{
    switch (operation)
    {
        case OperationType::kAdd:
        {
            auto task = view.GetTask();
            auto parent_id = view.GetParentTaskId();
            this->model_->Add(task.value(),
                              parent_id.value());
            break;
        }
        case OperationType::kEdit:
        {
            auto task = view.GetTask();
            auto parent_id = view.GetParentTaskId();
            auto id = view.GetTaskId();

            if (task and parent_id and id)
                this->model_->Edit(id.value(),
                               task.value(),
                               parent_id.value());
            break;
        }
        case OperationType::kComplete:
        {
            auto id = view.GetTaskId();

            if (id)
                this->model_->Complete(id.value());
            break;
        }
        case OperationType::kDelete:
        {
            auto id = view.GetTaskId();

            if (id)
                this->model_->Delete(id.value());
            break;
        }
        case OperationType::kNone:
            break;
    }
}

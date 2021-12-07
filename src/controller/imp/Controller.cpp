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
            auto task_struct = view.GetTaskStruct();
            if (task_struct)
            {
                this->model_->Add(task_struct->ConstructTask(),
                                  task_struct->GetParent());
            }
            break;
        }
        case OperationType::kEdit:
        {
            auto task_struct = view.GetTaskStruct();

            if (task_struct)
            {
                auto id = task_struct->GetId();
                auto task = task_struct->ConstructTask();
                auto parent_id = task_struct->GetParent();
                this->model_->Edit(id,
                                   task,
                                   parent_id);
            }
            break;
        }
        case OperationType::kComplete:
        {
            auto task_struct = view.GetTaskStruct();
            if (task_struct)
                this->model_->Complete(task_struct->GetId());
            break;
        }
        case OperationType::kDelete:
        {
            auto task_struct = view.GetTaskStruct();

            if (task_struct)
                this->model_->Delete(task_struct->GetId());
            break;
        }
        case OperationType::kNone:break;
    }
}

//
// Created by Illia Plaksa on 03.12.2021.
//

#include "../include/Controller.h"
Controller::Controller(const std::shared_ptr<IModel> &model)
    :
    model_(model) {}

void Controller::Action(const std::shared_ptr<IView> &view,
                        const OperationType &operation)
{
    switch (operation)
    {
        case OperationType::kAdd:
            this->model_->Add(view->GetTask().value(),
                              view->GetParentTaskId().value());
            break;
        case OperationType::kEdit:
            this->model_->Edit(view->GetTaskId().value(),
                               view->GetTask().value(),
                               view->GetParentTaskId().value());
            break;
        case OperationType::kComplete:
            this->model_->Complete(view->GetTaskId().value());
            break;
        case OperationType::kDelete:
            this->model_->Delete(view->GetTaskId().value());
            break;
        case OperationType::kNone:
            break;
    }
}

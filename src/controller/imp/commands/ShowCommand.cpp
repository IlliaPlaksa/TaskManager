//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response ShowCommand::Execute(const std::shared_ptr<IView> &view)
{
    auto result = Response{};

    auto task_storage = TaskStorage{};

    try
    {
        auto model = GetModel();
        auto parents = model->ShowParents();

        for (const auto& elem : parents)
            task_storage.Add(TaskId::CreateDefault(), parents);

        for (const auto& elem : parents)
            task_storage.Add(elem.first,
                             model->ShowChild(elem.first));

        view->LoadTasks(task_storage);
        result.status = Response::Status::kSuccess;
    }
    catch (const std::exception &e)
    {
        result.status = Response::Status::kError;
        result.error_message = e.what();
    }

    return result;
}
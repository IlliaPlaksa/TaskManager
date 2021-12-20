//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Response ShowCommand::Execute(const std::shared_ptr<IView> &view)
{
    Response result;
    auto task_storage = TaskStorage{};
    auto model = GetModel();
    auto root = model->ShowParents();

    result = task_storage.LoadRootTasks(model->ShowParents());

    for (const auto &task: root)
    {
        const auto &parent_id = task.parent_id();
        task_storage.LoadSubTasks(parent_id, model->ShowChild(parent_id));
    }

    if (!result.IsError())
        view->LoadTasks(task_storage);
    return result;
}
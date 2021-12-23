//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Model::Response ShowCommand::Execute(const std::shared_ptr<View>& view)
{
    auto task_storage = TaskStorage{};
    auto model = GetModel();
    auto root = model->ShowParents();

    task_storage.LoadRootTasks(root);

    for (const auto& task : root)
    {
        const auto& parent_id = task.parent_id();
        task_storage.LoadSubTasks(parent_id, model->ShowChild(parent_id));
    }

    view->LoadTasks(task_storage);

    return Model::Response::CreateSuccess();
}
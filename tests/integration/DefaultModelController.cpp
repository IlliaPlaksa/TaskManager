//
// Created by Illia Plaksa on 18.02.2022.
//

#include "DefaultModelController.h"
DefaultModelController::DefaultModelController(std::unique_ptr<Model> model)
    :
    model_(std::move(model))
{

}
ModelResponse DefaultModelController::Add(const Task& task)
{
    return model_->Add(task);
}
ModelResponse DefaultModelController::AddSubTask(const Task& task, const TaskId& parent_id)
{
    return model_->AddSubTask(task, parent_id);
}
ModelResponse DefaultModelController::Edit(const TaskId& task_id, const Task& task)
{
    return model_->Edit(task_id, task);
}
ModelResponse DefaultModelController::EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id)
{
    return model_->EditSubTask(task_id, task, parent_id);
}
ModelResponse DefaultModelController::Complete(const TaskId& task_id)
{
    return model_->Complete(task_id);
}
ModelResponse DefaultModelController::Delete(const TaskId& task_id)
{
    return model_->Delete(task_id);
}
std::vector<TaskDTO> DefaultModelController::Show()
{
    return model_->Show();
}
std::vector<TaskDTO> DefaultModelController::ShowParents()
{
    return model_->ShowParents();
}
std::vector<TaskDTO> DefaultModelController::ShowChild(const TaskId& parent_id)
{
    return model_->ShowChild(parent_id);
}
std::vector<TaskDTO> DefaultModelController::ShowTasksWithLabel(const std::string& label)
{
    return model_->ShowTasksWithLabel(label);
}
ModelResponse DefaultModelController::Load(const std::vector<TaskDTO>& tasks)
{
    return model_->Load(tasks);
}
ModelResponse DefaultModelController::LoadFromFile(const std::string& file_name)
{
    auto persister = FilePersister{file_name};

    auto tasks = persister.Load();

    if (tasks.has_value())
        return this->Load(*tasks);
    else
        return ModelResponse::Error(ModelResponse::ErrorType::FAIL);
}
ModelResponse DefaultModelController::SaveToFile(const std::string& file_name)
{
    auto persister = FilePersister{file_name};

    auto tasks = this->Show();

    if (persister.Save(tasks))
    {
        return ModelResponse::Success();
    }
    else
        return ModelResponse::Error(ModelResponse::ErrorType::FAIL);
}

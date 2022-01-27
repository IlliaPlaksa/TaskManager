//
// Created by Illia Plaksa on 26.01.2022.
//

#include "RemoteController.h"
#include "util/Response/ResponseConverters.h"
#include "util/TaskDTO/TaskDTOCreators.h"

RemoteController::RemoteController(const std::shared_ptr<grpc::ChannelInterface>& channel)
    :
    stub_(service::RequestHandler::NewStub(channel))
{
}

ModelResponse RemoteController::Add(const Task& task)
{
    grpc::ClientContext context;
    auto response = service::Response();

    stub_->Add(&context, task, &response);

    return ServiceResponseToModelResponse(response);
}
ModelResponse RemoteController::AddSubTask(const Task& task, const TaskId& parent_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    TaskDTO task_dto;
    task_dto.mutable_task()->CopyFrom(task);
    task_dto.mutable_parent_id()->CopyFrom(parent_id);

    stub_->AddSubTask(&context, task_dto, &response);

    return ServiceResponseToModelResponse(response);
}
ModelResponse RemoteController::Edit(const TaskId& task_id, const Task& task)
{
    grpc::ClientContext context;
    auto response = service::Response();

    TaskDTO task_dto;
    task_dto.mutable_id()->CopyFrom(task_id);
    task_dto.mutable_task()->CopyFrom(task);

    stub_->Edit(&context, task_dto, &response);

    return ServiceResponseToModelResponse(response);

}
ModelResponse RemoteController::EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    TaskDTO task_dto;
    task_dto.mutable_id()->CopyFrom(task_id);
    task_dto.mutable_task()->CopyFrom(task);
    task_dto.mutable_parent_id()->CopyFrom(parent_id);

    stub_->EditSubTask(&context, task_dto, &response);

    return ServiceResponseToModelResponse(response);
}
ModelResponse RemoteController::Complete(const TaskId& task_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    stub_->Complete(&context, task_id, &response);

    return ServiceResponseToModelResponse(response);
}
ModelResponse RemoteController::Delete(const TaskId& task_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    stub_->Delete(&context, task_id, &response);

    return ServiceResponseToModelResponse(response);
}
std::vector<TaskDTO> RemoteController::Show()
{
    auto result = std::vector<TaskDTO>{};
    grpc::ClientContext context;

    service::BlankMessage message;

    auto reader = stub_->Show(&context, message);

    TaskDTO tmp_task;

    while (reader->Read(&tmp_task))
    {
        result.emplace_back(tmp_task);
    }

    grpc::Status status = reader->Finish();
    if (status.ok())
        return result;
    else
        return std::vector<TaskDTO>{};
}
std::vector<TaskDTO> RemoteController::ShowParents()
{
    auto result = std::vector<TaskDTO>{};
    grpc::ClientContext context;

    service::BlankMessage message;

    auto reader = stub_->ShowParents(&context, message);

    TaskDTO tmp_task;

    while (reader->Read(&tmp_task))
    {
        result.emplace_back(tmp_task);
    }

    grpc::Status status = reader->Finish();
    if (status.ok())
        return result;
    else
        return std::vector<TaskDTO>{};
}
std::vector<TaskDTO> RemoteController::ShowChild(const TaskId& parent_id)
{
    auto result = std::vector<TaskDTO>{};
    grpc::ClientContext context;

    auto reader = stub_->ShowChild(&context, parent_id);

    TaskDTO tmp_task;

    while (reader->Read(&tmp_task))
    {
        result.emplace_back(tmp_task);
    }

    grpc::Status status = reader->Finish();
    if (status.ok())
        return result;
    else
        return std::vector<TaskDTO>{};
}
ModelResponse RemoteController::Load(const std::vector<TaskDTO>& tasks)
{
    grpc::ClientContext context;
    auto response = service::Response();

    auto writer = stub_->Load(&context, &response);

    for (const auto& task: tasks)
    {
        if (!writer->Write(task))
            return ModelResponse::Error(ModelResponse::ErrorType::FAIL);
    }

    writer->WritesDone();
    grpc::Status status = writer->Finish();

    if (status.ok())
        return ModelResponse::Success();
    else
        return ModelResponse::Error(ModelResponse::ErrorType::FAIL);
}
ModelResponse RemoteController::LoadFromFile(const std::string& file_name)
{
    auto persister = FilePersister{file_name};

    auto tasks = persister.Load();

    if (tasks.has_value())
        return this->Load(*tasks);
    else
        return ModelResponse::Error(ModelResponse::ErrorType::FAIL);
}
ModelResponse RemoteController::SaveToFile(const std::string& file_name)
{
    auto persister = FilePersister{file_name};

    auto tasks = this->Show();

    if (persister.Save(tasks))
    {
        return ModelResponse::Success();
    } else
        return ModelResponse::Error(ModelResponse::ErrorType::FAIL);
}




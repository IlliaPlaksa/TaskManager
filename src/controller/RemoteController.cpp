//
// Created by Illia Plaksa on 26.01.2022.
//

#include "RemoteController.h"
#include "util/Response/ResponseConverters.h"
#include "util/TaskDTO/TaskDTOCreators.h"

RemoteController::RemoteController(std::unique_ptr<service::RequestHandler::StubInterface> stub)
    :
    stub_(std::move(stub))
{
}

ModelResponse RemoteController::Add(const Task& task)
{
    grpc::ClientContext context;
    auto response = service::Response();

    auto status = stub_->Add(&context, task, &response);

    return CreateModelResponse(status, response);
}
ModelResponse RemoteController::AddSubTask(const Task& task, const TaskId& parent_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    TaskDTO task_dto;
    task_dto.mutable_task()->CopyFrom(task);
    task_dto.mutable_parent_id()->CopyFrom(parent_id);

    auto status = stub_->AddSubTask(&context, task_dto, &response);

    return CreateModelResponse(status, response);
}
ModelResponse RemoteController::Edit(const TaskId& task_id, const Task& task)
{
    grpc::ClientContext context;
    auto response = service::Response();

    TaskDTO task_dto;
    task_dto.mutable_id()->CopyFrom(task_id);
    task_dto.mutable_task()->CopyFrom(task);

    auto status = stub_->Edit(&context, task_dto, &response);

    return CreateModelResponse(status, response);
}
ModelResponse RemoteController::EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    TaskDTO task_dto;
    task_dto.mutable_id()->CopyFrom(task_id);
    task_dto.mutable_task()->CopyFrom(task);
    task_dto.mutable_parent_id()->CopyFrom(parent_id);

    auto status = stub_->EditSubTask(&context, task_dto, &response);

    return CreateModelResponse(status, response);
}
ModelResponse RemoteController::Complete(const TaskId& task_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    auto status = stub_->Complete(&context, task_id, &response);

    return CreateModelResponse(status, response);
}
ModelResponse RemoteController::Delete(const TaskId& task_id)
{
    grpc::ClientContext context;
    auto response = service::Response();

    auto status = stub_->Delete(&context, task_id, &response);

    return CreateModelResponse(status, response);
}
std::vector<TaskDTO> RemoteController::Show()
{
    auto result = std::vector<TaskDTO>{};
    grpc::ClientContext context;
    service::BlankMessage message;

    service::TaskDTOEnvelope response;

    auto status = stub_->Show(&context, message, &response);

    auto& tasks = response.tasks();

    result.insert(result.end(), tasks.cbegin(), tasks.cend());

    return result;
}
std::vector<TaskDTO> RemoteController::ShowParents()
{
    auto result = std::vector<TaskDTO>{};
    grpc::ClientContext context;
    service::BlankMessage message;

    service::TaskDTOEnvelope response;

    stub_->ShowParents(&context, message, &response);

    auto& tasks = response.tasks();

    result.insert(result.end(), tasks.cbegin(), tasks.cend());

    return result;
}
std::vector<TaskDTO> RemoteController::ShowChild(const TaskId& parent_id)
{
    auto result = std::vector<TaskDTO>{};
    grpc::ClientContext context;
    service::TaskDTOEnvelope response;

    stub_->ShowChild(&context, parent_id, &response);

    auto& tasks = response.tasks();

    result.insert(result.end(), tasks.cbegin(), tasks.cend());

    return result;
}
ModelResponse RemoteController::Load(const std::vector<TaskDTO>& tasks)
{
    grpc::ClientContext context;
    auto response = service::Response{};
    auto tasks_envelope = service::TaskDTOEnvelope{};

    tasks_envelope.mutable_tasks()->Add(tasks.cbegin(), tasks.cend());

    auto status = stub_->Load(&context, tasks_envelope, &response);

    return CreateModelResponse(status, response);
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

ModelResponse RemoteController::CreateModelResponse(const grpc::Status& status, const service::Response& response)
{
    if (status.ok())
        return ServiceResponseToModelResponse(response);
    else
        return ModelResponse::Error(ModelResponse::ErrorType::FAIL);
}




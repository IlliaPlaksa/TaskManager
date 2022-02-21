//
// Created by Illia Plaksa on 26.01.2022.
//

#include "RequestHandlerImpl.h"

RequestHandlerImpl::RequestHandlerImpl(std::unique_ptr<Model> model)
    : model_(std::move(model))
{
}

grpc::Status RequestHandlerImpl::Add(::grpc::ServerContext* context,
                                     const ::Task* request,
                                     ::service::Response* response)
{
    const auto& task = *request;
    auto result = model_->Add(task);

    *response = ModelResponseToServiceResponse(result);
    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::AddSubTask(::grpc::ServerContext* context,
                                            const ::TaskDTO* request,
                                            ::service::Response* response)
{
    const auto& task = request->task();
    const auto& parent_id = request->parent_id();

    auto result = model_->AddSubTask(task, parent_id);
    *response = ModelResponseToServiceResponse(result);
    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::Edit(::grpc::ServerContext* context,
                                      const ::TaskDTO* request,
                                      ::service::Response* response)
{
    const auto& id = request->id();
    const auto& task = request->task();

    auto result = model_->Edit(id, task);

    *response = ModelResponseToServiceResponse(result);
    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::EditSubTask(::grpc::ServerContext* context,
                                             const ::TaskDTO* request,
                                             ::service::Response* response)
{
    const auto& id = request->id();
    const auto& task = request->task();
    const auto& parent_id = request->parent_id();

    auto result = model_->EditSubTask(id, task, parent_id);

    *response = ModelResponseToServiceResponse(result);
    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::Complete(::grpc::ServerContext* context,
                                          const ::TaskId* request,
                                          ::service::Response* response)
{
    const auto& id = *request;

    auto result = model_->Complete(id);

    *response = ModelResponseToServiceResponse(result);
    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::Delete(::grpc::ServerContext* context,
                                        const ::TaskId* request,
                                        ::service::Response* response)
{
    const auto& id = *request;

    auto result = model_->Delete(id);

    *response = ModelResponseToServiceResponse(result);
    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::Show(::grpc::ServerContext* context,
                                      const google::protobuf::Empty* request,
                                      ::service::TaskDTOEnvelope* response)
{
    auto tasks = model_->Show();

    for (auto& task : tasks)
    {
        response->mutable_tasks()->Add(std::move(task));
    }

    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::ShowParents(::grpc::ServerContext* context,
                                             const google::protobuf::Empty* request,
                                             ::service::TaskDTOEnvelope* response)
{
    auto tasks = model_->ShowParents();

    for (auto& task : tasks)
    {
        response->mutable_tasks()->Add(std::move(task));
    }

    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::ShowChild(::grpc::ServerContext* context,
                                           const ::TaskId* request,
                                           ::service::TaskDTOEnvelope* response)
{
    auto task_id = *request;

    auto tasks = model_->ShowChild(task_id);

    for (auto& task : tasks)
    {
        response->mutable_tasks()->Add(std::move(task));
    }

    return ::grpc::Status::OK;
}

grpc::Status RequestHandlerImpl::ShowTasksWithLabel(::grpc::ServerContext* context,
                                                    const ::service::Label* request,
                                                    ::service::TaskDTOEnvelope* response)
{
    auto& label = request->value();

    auto tasks = model_->ShowTasksWithLabel(label);

    for (auto& task : tasks)
    {
        response->mutable_tasks()->Add(std::move(task));
    }

    return ::grpc::Status::OK;
}

grpc::Status RequestHandlerImpl::Load(::grpc::ServerContext* context,
                                      const ::service::TaskDTOEnvelope* request,
                                      ::service::Response* response)
{
    auto& tasks = request->tasks();
    auto task_vector = std::vector<TaskDTO>{};

    task_vector.insert(task_vector.end(), tasks.cbegin(), tasks.cend());

    auto result = model_->Load(task_vector);
    *response = ModelResponseToServiceResponse(result);

    return ::grpc::Status::OK;
}

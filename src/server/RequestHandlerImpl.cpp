//
// Created by Illia Plaksa on 26.01.2022.
//

#include "RequestHandlerImpl.h"

RequestHandlerImpl::RequestHandlerImpl(std::unique_ptr<Model> model)
    :
    model_(std::move(model))
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
                                      const ::service::BlankMessage* request,
                                      ::grpc::ServerWriter<::TaskDTO>* writer)
{
    auto tasks = model_->Show();

    for (const auto& task: tasks)
    {
        writer->Write(task);
    }

    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::ShowParents(::grpc::ServerContext* context,
                                             const ::service::BlankMessage* request,
                                             ::grpc::ServerWriter<::TaskDTO>* writer)
{
    auto tasks = model_->ShowParents();

    for (const auto& task: tasks)
    {
        writer->Write(task);
    }

    return ::grpc::Status::OK;
}
grpc::Status RequestHandlerImpl::ShowChild(::grpc::ServerContext* context,
                                           const ::TaskId* request,
                                           ::grpc::ServerWriter<::TaskDTO>* writer)
{
    auto parent_id = *request;
    auto tasks = model_->ShowChild(parent_id);

    for (const auto& task: tasks)
    {
        writer->Write(task);
    }

    return ::grpc::Status::OK;
}

grpc::Status RequestHandlerImpl::Load(::grpc::ServerContext* context,
                                      ::grpc::ServerReader<::TaskDTO>* reader,
                                      ::service::Response* response)
{
    auto tasks = std::vector<TaskDTO>{};

    auto tmp_task = TaskDTO();

    while (reader->Read(&tmp_task))
    {
        tasks.emplace_back(tmp_task);
    }

    auto result = model_->Load(tasks);

    *response = ModelResponseToServiceResponse(result);

    return ::grpc::Status::OK;
}


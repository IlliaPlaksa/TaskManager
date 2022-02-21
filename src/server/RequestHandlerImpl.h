//
// Created by Illia Plaksa on 26.01.2022.
//

#ifndef TASKMANAGER_SRC_SERVER_REQUESTHANDLERIMPL_H_
#define TASKMANAGER_SRC_SERVER_REQUESTHANDLERIMPL_H_

#include "Service.grpc.pb.h"
#include "common/include/Model.h"
#include "util/Response/ResponseConverters.h"

class RequestHandlerImpl : public service::RequestHandler::Service
{
public:
    explicit RequestHandlerImpl(std::unique_ptr<Model> model);

public:
    grpc::Status Add(::grpc::ServerContext* context, const ::Task* request, ::service::Response* response) override;
    grpc::Status AddSubTask(::grpc::ServerContext* context,
                            const ::TaskDTO* request,
                            ::service::Response* response) override;
    grpc::Status Edit(::grpc::ServerContext* context, const ::TaskDTO* request, ::service::Response* response) override;
    grpc::Status EditSubTask(::grpc::ServerContext* context,
                             const ::TaskDTO* request,
                             ::service::Response* response) override;
    grpc::Status Complete(::grpc::ServerContext* context,
                          const ::TaskId* request,
                          ::service::Response* response) override;
    grpc::Status Delete(::grpc::ServerContext* context,
                        const ::TaskId* request,
                        ::service::Response* response) override;
    grpc::Status Show(::grpc::ServerContext* context,
                      const google::protobuf::Empty* request,
                      ::service::TaskDTOEnvelope* response) override;
    grpc::Status ShowParents(::grpc::ServerContext* context,
                             const google::protobuf::Empty* request,
                             ::service::TaskDTOEnvelope* response) override;
    grpc::Status ShowChild(::grpc::ServerContext* context,
                           const ::TaskId* request,
                           ::service::TaskDTOEnvelope* response) override;
    grpc::Status ShowTasksWithLabel(::grpc::ServerContext* context,
                                    const ::service::Label* request,
                                    ::service::TaskDTOEnvelope* response) override;
    grpc::Status Load(::grpc::ServerContext* context,
                      const ::service::TaskDTOEnvelope* request,
                      ::service::Response* response) override;

private:
    std::unique_ptr<Model> model_;
};

#endif //TASKMANAGER_SRC_SERVER_REQUESTHANDLERIMPL_H_

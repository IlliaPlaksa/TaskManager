//
// Created by Illia Plaksa on 25.01.2022.
//

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include <boost/log/trivial.hpp>

#include "model/include/TaskManager.h"
#include "server/RequestHandlerImpl.h"

int main(int argc, char** argv)
{

    std::string server_address("0.0.0.0:50051");
    auto model = std::unique_ptr<Model>(new TaskManager{std::make_unique<IdGenerator>()});

    auto service = RequestHandlerImpl{std::move(model)};

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    BOOST_LOG_TRIVIAL(info) << "Server listening on " << server_address;
    server->Wait();
    return 0;
}
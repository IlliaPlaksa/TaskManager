//
// Created by Illia Plaksa on 25.01.2022.
//

#include "controller/RemoteController.h"
#include "cli/include/StepMachine.h"

#include "Logging.h"

int main(int argc, char** argv)
{
    logging::init("client.log",boost::log::trivial::severity_level::info);

    std::string client_address{"localhost:50051"};
    auto channel = grpc::CreateChannel(client_address, grpc::InsecureChannelCredentials());
    auto stub = service::RequestHandler::NewStub(channel);

    auto controller = std::make_shared<RemoteController>(std::move(stub));

    auto console_manipulator = std::make_shared<ConsoleManipulator>(std::cout, std::cin);
    auto step_factory = std::shared_ptr<StepFactory>{new StepFactory{console_manipulator}};

    auto view = std::shared_ptr<View>{new StepMachine{step_factory, controller}};

    BOOST_LOG_TRIVIAL(info) << "Client started at " << client_address;

    view->Run();

    BOOST_LOG_TRIVIAL(info) << "Client shut down";
    return 0;
}
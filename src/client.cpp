//
// Created by Illia Plaksa on 25.01.2022.
//

#include "controller/RemoteController.h"
#include "cli/include/StepMachine.h"

int main(int argc, char** argv)
{
    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    auto controller = std::make_shared<RemoteController>(channel);

    auto console_manipulator = std::make_shared<ConsoleManipulator>(std::cout, std::cin);
    auto step_factory = std::shared_ptr<StepFactory>{new StepFactory{console_manipulator}};

    auto view = std::shared_ptr<View>{new StepMachine{step_factory, controller}};

    view->Run();

    return 0;
}
//
// Created by Illia Plaksa on 03.12.2021.
//

#include "controller/include/Controller.h"
#include "cli/include/StepMachine.h"
#include "model/include/TaskManager.h"

int main()
{
    auto model = std::shared_ptr<Model>{
        new TaskManager{std::make_unique<IdGenerator>()}
    };

    auto command_factory = std::make_shared<CommandFactory>();
    auto controller = std::make_shared<Controller>(Controller{model, command_factory});

    auto console_manipulator = std::make_shared<ConsoleManipulator>();
    auto step_factory = std::shared_ptr<StepFactory>{new StepFactory{console_manipulator}};

    auto view = std::shared_ptr<View>{new StepMachine{step_factory, controller}};

    view->Run();
    return 0;
}

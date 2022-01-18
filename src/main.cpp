//
// Created by Illia Plaksa on 03.12.2021.
//

#include "controller/include/ModelController.h"
#include "cli/include/StepMachine.h"
#include "model/include/TaskManager.h"

int main()
{
    auto model = std::shared_ptr<Model>{
        new TaskManager{std::make_unique<IdGenerator>()}
    };

    // auto controller = std::shared_ptr<Model>(new ModelController{model});

    auto console_manipulator = std::make_shared<ConsoleManipulator>(std::cout, std::cin);
    auto step_factory = std::shared_ptr<StepFactory>{new StepFactory{console_manipulator}};

    auto view = std::shared_ptr<View>{new StepMachine{step_factory, model}};

    view->Run();
    return 0;
}

//
// Created by Illia Plaksa on 03.12.2021.
//

#include "include/Controller.h"
#include "../cli/include/StepMachine.h"
#include "../model/include/TaskManager.h"

int main()
{
    auto model = std::shared_ptr<IModel>{
        new TaskManager{std::make_unique<IdGenerator>()}
    };
    auto controller = std::make_shared<Controller>(Controller{model});

    auto view = std::shared_ptr<IView>{new StepMachine{controller}};

    view->Run();
    return 0;
}

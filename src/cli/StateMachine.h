//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_STATEMACHINE_H_
#define TASKMANAGER_SRC_CLI_STATEMACHINE_H_

#include "Context.h"
#include "State.h"

class StateMachine
{
public:
    void Start();
private:
    Context context_;
};

#endif //TASKMANAGER_SRC_CLI_STATEMACHINE_H_

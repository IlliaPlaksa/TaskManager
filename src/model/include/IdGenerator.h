//
// Created by Illia Plaksa on 10.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_IDGENERATOR_H_
#define TASKMANAGER_SRC_MODEL_IDGENERATOR_H_

#include "TaskId.h"

class IdGenerator
{
public:
    virtual TaskId GetNextId();
    virtual ~IdGenerator() = default;
private:
    unsigned id_counter_ = 1;
};

#endif //TASKMANAGER_SRC_MODEL_IDGENERATOR_H_

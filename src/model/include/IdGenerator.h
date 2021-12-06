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

public:
    IdGenerator();
private:
    int id_counter_;
};

#endif //TASKMANAGER_SRC_MODEL_IDGENERATOR_H_

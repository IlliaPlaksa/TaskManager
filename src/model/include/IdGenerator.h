//
// Created by Illia Plaksa on 10.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_IDGENERATOR_H_
#define TASKMANAGER_SRC_MODEL_IDGENERATOR_H_

#include "TaskId.pb.h"

class IdGenerator
{
public:
    IdGenerator();
public:
    virtual TaskId GetNextId();
    virtual void SetLastId(const TaskId& last_id);
public:
    virtual ~IdGenerator() = default;

private:
    unsigned long long id_counter_;
};

#endif //TASKMANAGER_SRC_MODEL_IDGENERATOR_H_

//
// Created by Illia Plaksa on 10.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_IDGENERATOR_H_
#define TASKMANAGER_SRC_MODEL_IDGENERATOR_H_

#include "TaskId.h"

class IdGenerator
{
 public:
  TaskId GetNextId();

 private:
  unsigned id_counter_ = 0;
};

#endif //TASKMANAGER_SRC_MODEL_IDGENERATOR_H_

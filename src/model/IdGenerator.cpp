//
// Created by Illia Plaksa on 10.11.2021.
//

#include "IdGenerator.h"

TaskId IdGenerator::GetNextId()
{
    return TaskId::Create(this->id_counter_++);
}

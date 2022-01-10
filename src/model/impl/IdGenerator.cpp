//
// Created by Illia Plaksa on 10.11.2021.
//

#include "../include/IdGenerator.h"

#include "../../util/TaskIdCreators.h"

TaskId IdGenerator::GetNextId()
{
    return CreateTaskId(this->id_counter_++).value();
}
IdGenerator::IdGenerator()
    :
    id_counter_(0) {}
void IdGenerator::SetLastId(const TaskId& last_id)
{
    this->id_counter_ = last_id.value();
}


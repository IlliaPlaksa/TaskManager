//
// Created by Illia Plaksa on 10.11.2021.
//

#include "TaskId.h"

TaskId TaskId::Create(unsigned int value)
{
    return TaskId{value};
}

TaskId::TaskId(unsigned int value)
    :
    value_(value)
{
}
bool TaskId::operator<(const TaskId &other) const
{
    return this->value_ < other.value_;
}
bool TaskId::operator==(const TaskId &other) const
{
    return this->value_ == other.value_;
}
bool TaskId::operator!=(const TaskId &other) const
{
    return this->value_ != other.value_;
}



//
// Created by Illia Plaksa on 10.11.2021.
//

#include "../include/TaskId.h"

TaskId TaskId::Create(int value)
{
    if (value < 0)
        throw std::runtime_error{"TaskId value must be non-negative"};
    return TaskId{value};
}

TaskId TaskId::CreateDefault()
{
    return TaskId(-1);
}

TaskId::TaskId(int value)
    :
    value_(value)
{}

int TaskId::value() const
{
    return this->value_;
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



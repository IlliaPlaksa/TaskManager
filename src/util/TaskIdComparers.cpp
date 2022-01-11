//
// Created by Illia Plaksa on 22.12.2021.
//

#include "TaskIdComparers.h"

bool operator==(const TaskId& first, const TaskId& second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}

bool operator!=(const TaskId& first, const TaskId& second)
{
    return !(first == second);
}

bool operator<(const TaskId& first, const TaskId& second)
{
    return first.value() < second.value();
}
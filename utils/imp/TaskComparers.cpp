//
// Created by Illia Plaksa on 16.12.2021.
//

#include "../include/TaskComparers.h"

bool operator==(const TaskToSerialize &first, const TaskToSerialize &second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}

bool operator==(const Task &first, const Task &second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}

bool operator==(const TaskId &first, const TaskId &second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}

bool operator<(const TaskId &first, const TaskId &second)
{
    return first.value() < second.value();
}
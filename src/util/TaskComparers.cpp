//
// Created by Illia Plaksa on 22.12.2021.
//

#include "TaskComparers.h"

bool operator==(const Task& first, const Task& second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}
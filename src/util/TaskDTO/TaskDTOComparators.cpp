//
// Created by Illia Plaksa on 23.12.2021.
//

#include "TaskDTOComparators.h"

bool operator==(const TaskDTO& first, const TaskDTO& second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}

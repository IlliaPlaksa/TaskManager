//
// Created by Illia Plaksa on 23.12.2021.
//

#include "TaskToSerializeComparers.h"

bool operator==(const TaskToSerialize &first, const TaskToSerialize &second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}

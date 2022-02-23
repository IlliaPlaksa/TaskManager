//
// Created by Illia Plaksa on 10.11.2021.
//

#include "TaskIdCreators.h"

std::optional<TaskId> CreateTaskId(const long long& value)
{
    if (value < 0)
        return std::nullopt;

    auto result = TaskId{};
    result.set_value(value);

    return result;
}







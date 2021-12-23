//
// Created by Illia Plaksa on 10.11.2021.
//

#include "TaskIdCreators.h"

std::optional<TaskId> CreateTaskId(const google::protobuf::uint64 &value)
{
    auto result = TaskId{};
    result.set_value(value);

    return result;
}







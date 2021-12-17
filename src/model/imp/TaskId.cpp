//
// Created by Illia Plaksa on 10.11.2021.
//

#include "../include/TaskId.h"

std::optional<TaskId> CreateTaskId(const google::protobuf::uint64 &value)
{
    auto result = TaskId{};
    result.set_value(value);

    return result;
}

bool operator==(const TaskId &first, const TaskId &second)
{
    return first.SerializeAsString() == second.SerializeAsString();
}

bool operator<(const TaskId &first, const TaskId &second)
{
    return first.value() < second.value();
}





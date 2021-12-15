//
// Created by Illia Plaksa on 15.12.2021.
//

#include "../include/TaskPersister.h"

void TaskPersister::SerializeToFile(const std::string &file_name, const std::vector<TaskToSerialize> &tasks)
{
    std::fstream ofs(file_name,
                      std::ios::out | std::ios::trunc | std::ios::binary);

    if(!ofs.is_open())
        return; // Add returning error
    else
        for(const auto& task : tasks)
            task.SerializeToOstream(&ofs);

    google::protobuf::ShutdownProtobufLibrary();
}
std::optional<std::vector<TaskToSerialize>> TaskPersister::DeserializeFromFile(const std::string &file_name)
{
    auto result = std::vector<TaskToSerialize>{};

    std::fstream input(file_name,
                       std::ios::in | std::ios::binary);

    while (input.is_open())
    {
        auto tmp = TaskToSerialize{};
        if(tmp.ParseFromIstream(&input))
            result.emplace_back(tmp);
        else
            return std::nullopt;
    }
    google::protobuf::ShutdownProtobufLibrary();
    return result;
}

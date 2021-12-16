//
// Created by Illia Plaksa on 15.12.2021.
//

#include "../include/TaskPersister.h"

void TaskPersister::SerializeToFile(const std::string &file_name, const std::vector<TaskToSerialize> &tasks)
{
    auto task_package = TaskPackage{};
    std::fstream ofs(file_name,
                     std::ios::out | std::ios::trunc | std::ios::binary);

    if (!ofs.is_open())
        return; // Add returning error
    else
    {
        for (const auto &elem: tasks)
        {
            auto task = task_package.add_tasks();
            *task = elem;
        }
        task_package.SerializeToOstream(&ofs);
    }

    google::protobuf::ShutdownProtobufLibrary();
}
std::optional<std::vector<TaskToSerialize>> TaskPersister::DeserializeFromFile(const std::string &file_name)
{
    auto result = std::vector<TaskToSerialize>{};

    std::fstream input(file_name,
                       std::ios::in | std::ios::binary);

    auto tmp = TaskPackage{};
    if (tmp.ParseFromIstream(&input))
    {
        for (size_t i = 0; i < tmp.tasks_size(); i++)
            result.emplace_back(tmp.tasks(i));
    } else
        return std::nullopt;

    google::protobuf::ShutdownProtobufLibrary();
    return result;
}

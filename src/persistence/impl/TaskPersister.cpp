//
// Created by Illia Plaksa on 15.12.2021.
//

#include "../include/TaskPersister.h"

#include "google/protobuf/util/delimited_message_util.h"

bool TaskPersister::SerializeTasksToFile(const std::string& file_name, const std::vector<TaskToSerialize>& tasks)
{
    std::fstream ofs(file_name,
                     std::ios::out | std::ios::trunc | std::ios::binary);

    if (!ofs.is_open())
        return false;
    else
    {
        for (const auto& elem : tasks)
        {
            google::protobuf::util::SerializeDelimitedToOstream(elem, &ofs);
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return true;
}
std::optional<std::vector<TaskToSerialize>> TaskPersister::DeserializeTasksFromFile(const std::string& file_name)
{
    auto result = std::vector<TaskToSerialize>{};

    std::fstream ifs(file_name,
                     std::ios::in | std::ios::binary);

    auto input = google::protobuf::io::IstreamInputStream(&ifs);

    bool clean_eof = true;
    TaskToSerialize tmp;

    while (clean_eof)
        if (google::protobuf::util::ParseDelimitedFromZeroCopyStream(&tmp, &input, &clean_eof))
        {
            result.emplace_back(tmp);
        } else
            return std::nullopt;

    google::protobuf::ShutdownProtobufLibrary();
    return result;
}


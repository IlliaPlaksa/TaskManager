//
// Created by Illia Plaksa on 15.12.2021.
//

#include "../include/FilePersister.h"

#include "google/protobuf/util/delimited_message_util.h"

FilePersister::FilePersister(const std::string& file_name)
{
    this->file_name_ = file_name;
}

bool FilePersister::Save(const std::vector<TaskDTO>& tasks)
{
    std::fstream ofs(file_name_,
                     std::ios::out | std::ios::trunc | std::ios::binary);

    if (!ofs.is_open())
        return false;
    else
    {
        for (const auto& elem: tasks)
        {
            google::protobuf::util::SerializeDelimitedToOstream(elem, &ofs);
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return true;
}
std::optional<std::vector<TaskDTO>> FilePersister::Load()
{
    auto result = std::vector<TaskDTO>{};

    std::fstream ifs(file_name_,
                     std::ios::in | std::ios::binary);

    auto input = google::protobuf::io::IstreamInputStream(&ifs);

    bool clean_eof = true;
    TaskDTO tmp;

    while (google::protobuf::util::ParseDelimitedFromZeroCopyStream(&tmp, &input, &clean_eof))
        if (!clean_eof)
        {
            result.emplace_back(tmp);
            tmp = TaskDTO{};
        }
        else
            return std::nullopt;

    google::protobuf::ShutdownProtobufLibrary();
    return result;
}


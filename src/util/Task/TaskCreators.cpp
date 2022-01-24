//
// Created by Illia Plaksa on 08.11.2021.
//

#include "TaskCreators.h"

std::optional<Task> CreateTask(const std::string& title,
                               const std::time_t& due_to_date,
                               const Task_Priority& priority,
                               const std::vector<std::string>& labels,
                               const Task_Status& status)
{
    auto result = Task{};
    if (!title.empty() and due_to_date >= 0)
    {
        result.set_title(title);
        result.set_status(status);
        result.set_priority(priority);

        for(const auto& label: labels)
            result.add_labels(label);

        auto tmp_date = std::make_unique<google::protobuf::Timestamp>();
        tmp_date->set_seconds(due_to_date);
        result.set_allocated_due_date(tmp_date.release());
    } else
        return std::nullopt;

    return result;
}



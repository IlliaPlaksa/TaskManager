//
// Created by Illia Plaksa on 29.11.2021.
//

#include <regex>
#include "../include/Validators.h"

#include "../../util/TaskComparers.h"
#include "../../util/TaskCreators.h"

#include "../../util/TaskIdComparers.h"
#include "../../util/TaskIdCreators.h"

std::optional<StepId> Validate::Command(const std::string& command)
{
    if (command == "exit")
        return StepId::kExit;
    else if (command == "help")
        return StepId::kHelp;
    else if (command == "add")
        return StepId::kAdd;
    else if (command == "edit")
        return StepId::kEdit;
    else if (command == "complete")
        return StepId::kComplete;
    else if (command == "delete")
        return StepId::kDelete;
    else if (command == "show")
        return StepId::kUpdate;
    else
        return std::nullopt;
}
std::optional<std::string> Validate::Title(const std::string& title)
{
    if (title.empty())
        return std::nullopt;
    else
        return title;
}
std::optional<TaskId> Validate::Id(const std::string& id)
{
    if (id.empty())
        return std::nullopt;

    int num = std::stoi(id);
    if (num < 0)
        throw std::runtime_error("Id must be non-negative");
    else
        return CreateTaskId(num);
}
std::optional<time_t> Validate::Date(const std::string& date)
{
    const std::string pattern = R"(\d{2}.\d{2}.\d{4})";
    if (!std::regex_match(date, std::regex(pattern))) // Passed string doesn't match date pattern
        return std::nullopt;

    const std::string dateTimeFormat{"%d.%m.%Y"};
    std::istringstream ss{date};

    std::tm dt{};
    ss >> std::get_time(&dt, dateTimeFormat.c_str());
    if (ss.fail())
        return std::nullopt;
    else
    {
        auto time = std::mktime(&dt);
        if (time >= 0)
            return time;
        else
            return std::nullopt;
    }
}
std::optional<Task::Priority> Validate::Priority(const std::string& priority)
{
    if (priority == "high")
        return Task_Priority_kHigh;
    if (priority == "medium")
        return Task_Priority_kMedium;
    if (priority == "low")
        return Task_Priority_kLow;
    else
        return std::nullopt;
}
std::optional<std::string> Validate::Label(const std::string& label)
{
    if (label.empty())
        return std::nullopt;
    else
        return label;
}
std::optional<bool> Validate::Confirm(const std::string& symbol)
{
    if (symbol == "y")
        return true;
    else if (symbol == "n")
        return false;
    else
        return std::nullopt;
}

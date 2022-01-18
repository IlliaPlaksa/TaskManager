//
// Created by Illia Plaksa on 29.11.2021.
//

#include <regex>
#include "cli/include/Validators.h"

#include "util/Task/TaskComparators.h"
#include "util/Task/TaskCreators.h"

#include "util/TaskId/TaskIdComparators.h"
#include "util/TaskId/TaskIdCreators.h"

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
    else if (command == "save")
        return StepId::kSave;
    else if (command == "load")
        return StepId::kLoad;
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
    try
    {
        int num = std::stoi(id);

        return CreateTaskId(num);
    } catch (const std::exception& e)
    {
        return std::nullopt;
    }

}
std::optional<time_t> Validate::Date(const std::string& date)
{
    const std::string pattern = R"(\d{1,2}.\d{1,2}.\d{4})";
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
std::optional<std::string> Validate::FileName(const std::string& file_name)
{
    const std::string pattern = R"(\w{0,}.\w{0,})";
    if (!std::regex_match(file_name, std::regex(pattern)))
        return std::nullopt;
    else
        return file_name;
}


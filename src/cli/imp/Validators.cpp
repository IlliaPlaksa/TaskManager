//
// Created by Illia Plaksa on 29.11.2021.
//

#include "../include/Validators.h"

std::optional<StepId> Validate::Command(const std::string &command)
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
        return StepId::kShow;
    else
        return std::nullopt;
}
std::optional<std::string> Validate::Title(const std::string &title)
{
    if (title.empty())
        return std::nullopt;
    else
        return title;
}
std::optional<TaskId> Validate::Id(const std::string &id)
{
    if (id.empty())
        return TaskId::CreateDefault();

    int num;
    try
    {
        num = std::stoi(id);
        if (num < 0)
            throw std::runtime_error("Id is negative");
    }
    catch (std::exception& e)
    {
        return std::nullopt;
    }
    return TaskId::Create(num);
}
std::optional<time_t> Validate::Date(const std::string &date)
{
    static const std::string dateTimeFormat{"%d.%m.%Y"};
    std::istringstream ss{date};

    std::tm dt;
    ss >> std::get_time(&dt, dateTimeFormat.c_str());
    if (ss.fail())
        return std::nullopt;
    else
    {
        auto time = std::mktime(&dt);
        if(time == -1) // If date is incorrect
            return std::nullopt;
        else
            return time;
    }

}
std::optional<Task::Priority> Validate::Priority(const std::string &priority)
{
    std::string lower_case = priority;

    for (size_t i = 0; i < lower_case.length(); i++)
    {
        lower_case[i] = std::tolower(lower_case[i]);
    }

    if (priority == "high")
        return Task::Priority::kHigh;
    if (priority == "medium")
        return Task::Priority::kHigh;
    if (priority == "low")
        return Task::Priority::kHigh;
    else
        return std::nullopt;
}
std::optional<std::string> Validate::Label(const std::string &label)
{
        return label;
}
std::optional<bool> Validate::Confirm(const std::string &symbol)
{
    if (symbol == "y")
        return true;
    else if (symbol == "n")
        return false;
    else
        return std::nullopt;
}

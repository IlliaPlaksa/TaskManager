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
    return std::nullopt;
}
std::optional<TaskId> Validate::Id(const std::string &id)
{
    return std::nullopt;
}
std::optional<time_t> Validate::Date(const std::string &date)
{
    return std::nullopt;
}
std::optional<Task::Priority> Validate::Priority(const std::string &id)
{
    return std::nullopt;
}
std::optional<std::string> Validate::Label(const std::string &title)
{
    return std::nullopt;
}
std::optional<bool> Validate::Confirm(const std::string &title)
{
    return std::nullopt;
}

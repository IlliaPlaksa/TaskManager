//
// Created by Illia Plaksa on 29.11.2021.
//

#include "../include/Readers.h"

std::optional<StepId> Read::Command(const ConsoleManipulator &console)
{
    auto input = Validate::Command(console.ReadLine());
    return input;
}
std::optional<std::string> Read::Title(const ConsoleManipulator &console)
{
    auto input = Validate::Title(
        console.ReadLine("[Title]")
    );
    return input;
}
std::optional<TaskId> Read::Id(const ConsoleManipulator &console)
{
    auto input = Validate::Id(
        console.ReadLine("[ID]")
    );
    return input;
}
std::optional<time_t> Read::Date(const ConsoleManipulator &console)
{
    auto input = Validate::Date(
        console.ReadLine("[Date]")
    );
    return input;
}
std::optional<Task::Priority> Read::Priority(const ConsoleManipulator &console)
{
    auto input = Validate::Priority(
        console.ReadLine("[Priority]")
    );
    return input;
}
std::optional<std::string> Read::Label(const ConsoleManipulator &console)
{
    auto input = Validate::Label(
        console.ReadLine("[Label]")
    );
    return input;
}
std::optional<bool> Read::Confirm(const ConsoleManipulator &console)
{
    auto input = Validate::Confirm(
        console.ReadLine("[Confirm] \"y/n\"?")
    );
    return input;

}

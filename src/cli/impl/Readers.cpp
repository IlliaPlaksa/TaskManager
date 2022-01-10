//
// Created by Illia Plaksa on 29.11.2021.
//

#include "../include/Readers.h"

StepId Read::Command(const std::shared_ptr<ConsoleManipulator>& console)
{
    auto input = Validate::Command(console->ReadLine());

    while (!input)
    {
        console->WriteError("No such command\nUse [help] to determine command you needed");
        input = Validate::Command(console->ReadLine());
    }
    return input.value();
}
std::string Read::Title(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::optional<std::string> input;
    input = Validate::Title(
        console->ReadLine("[Title]")
    );

    while (!input)
    {
        console->WriteError("Wrong title passed");
        input = Validate::Title(
            console->ReadLine("[Title]")
        );
    }
    return input.value();
}
TaskId Read::Id(const std::shared_ptr<ConsoleManipulator>& console)
{
    const std::string message = "[ID]";
    std::optional<TaskId> input;
    input = Validate::Id(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError("Wrong ID passed");
        input = Validate::Id(
            console->ReadLine(message)
        );
    }
    return input.value();
}
std::optional<TaskId> Read::ParentId(const std::shared_ptr<ConsoleManipulator>& console)
{
    const std::string message = "[Parent ID]";
    std::optional<TaskId> input;
    input = Validate::Id(
        console->ReadLine(message)
    );

    if (!input)
        return std::nullopt;
    else
        return input.value();
}
time_t Read::Date(const std::shared_ptr<ConsoleManipulator>& console)
{
    const std::string message = "[Date] DD.MM.YY";
    auto input = Validate::Date(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError("Wrong Date passed");
        input = Validate::Date(
            console->ReadLine(message)
        );
    }
    return input.value();
}
Task::Priority Read::Priority(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::string message = "[Priority]";
    auto input = Validate::Priority(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError("Wrong Priority passed");
        input = Validate::Priority(
            console->ReadLine(message)
        );
    }
    return input.value();
}
std::optional<std::string> Read::Label(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::string message = "[Label]";
    auto input = Validate::Label(
        console->ReadLine(message)
    );
    return input;
}
bool Read::Confirm(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::string message = "[Confirm] \"y/n\"";
    auto input = Validate::Confirm(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError("Wrong Confirmation passed");
        input = Validate::Confirm(
            console->ReadLine(message)
        );
    }
    return input.value();
}
std::string FileName(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::optional<std::string> input;
    input = Validate::FileName(
        console->ReadLine("[File name]")
    );

    while (!input)
    {
        console->WriteError("Wrong file name passed");
        input = Validate::Title(
            console->ReadLine("[File name]")
        );
    }
    return input.value();
}


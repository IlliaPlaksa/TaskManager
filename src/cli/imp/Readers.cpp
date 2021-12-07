//
// Created by Illia Plaksa on 29.11.2021.
//

#include "../include/Readers.h"

StepId Read::Command(const std::shared_ptr<ConsoleManipulator> &console)
{
    auto input = Validate::Command(console->ReadLine());

    while (!input)
    {
        console->WriteLine("No such command\nUse [help] to determine command you needed");
        input = Validate::Command(console->ReadLine());
    }
    return input.value();
}
std::string Read::Title(const std::shared_ptr<ConsoleManipulator> &console)
{
    std::optional<std::string> input;
    input = Validate::Title(
        console->ReadLine("[Title]")
    );

    while (!input)
    {
        console->WriteLine("Wrong title passed");
        input = Validate::Title(
            console->ReadLine("[Title]")
        );
    }
    return input.value();
}
TaskId Read::Id(const std::shared_ptr<ConsoleManipulator> &console)
{
    const std::string message = "[ID]";
    std::optional<TaskId> input;
    input = Validate::Id(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteLine("Wrong ID passed");
        input = Validate::Id(
            console->ReadLine(message)
        );
    }
    return input.value();
}
time_t Read::Date(const std::shared_ptr<ConsoleManipulator> &console)
{
    const std::string message = "[Date] DD.MM.YY";
    auto input = Validate::Date(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteLine("Wrong Date passed");
        input = Validate::Date(
            console->ReadLine(message)
        );
    }
    return input.value();
}
Task::Priority Read::Priority(const std::shared_ptr<ConsoleManipulator> &console)
{
    std::string message = "[Priority]";
    auto input = Validate::Priority(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteLine("Wrong Priority passed");
        input = Validate::Priority(
            console->ReadLine(message)
        );
    }
    return input.value();
}
std::string Read::Label(const std::shared_ptr<ConsoleManipulator> &console)
{
    std::string message = "[Label]";
    auto input = Validate::Label(
        console->ReadLine(message)
    );
    while (!input)
    {
        console->WriteLine("Wrong Label passed");
        input = Validate::Label(
            console->ReadLine(message)
        );
    }
    return input.value();
}
bool Read::Confirm(const std::shared_ptr<ConsoleManipulator> &console)
{
    std::string message = "[Confirm] \"y/n\"";
    auto input = Validate::Confirm(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteLine("Wrong Confirmation passed");
        input = Validate::Confirm(
            console->ReadLine(message)
        );
    }
    return input.value();
}

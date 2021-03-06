//
// Created by Illia Plaksa on 29.11.2021.
//

#include "cli/Readers.h"

#include "util/Task/TaskCreators.h"

std::vector<std::string> Split(const std::string& str, const std::string& delimiter);

StepId Read::Command(const std::shared_ptr<ConsoleManipulator>& console)
{
    auto input = Validate::Command(console->ReadLine(""));

    while (!input)
    {
        console->WriteError("No such command\nUse [help] to determine command you needed");
        input = Validate::Command(console->ReadLine(""));
    }
    return input.value();
}
std::string Read::Title(const std::shared_ptr<ConsoleManipulator>& console)
{
    const std::string message = "[Title]";
    std::optional<std::string> input;
    input = Validate::Title(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError("Wrong title entered");
        input = Validate::Title(
            console->ReadLine(message)
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
        console->WriteError("Wrong ID entered");
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
    const std::string message = "[Date] DD.MM.YYYY";
    auto input = Validate::Date(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError("Wrong Date entered");
        input = Validate::Date(
            console->ReadLine(message)
        );
    }
    return input.value();
}
Task::Priority Read::Priority(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::string message = R"([Priority] "high", "medium", "low")";
    auto input = Validate::Priority(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError(R"(Wrong Priority entered)");
        input = Validate::Priority(
            console->ReadLine(message)
        );
    }
    return input.value();
}
std::optional<std::string> Read::Label(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::string message = "[Label] press 'Enter' to skip";
    auto input = console->ReadLine(message);

    return Validate::Label(input);
}
std::vector<std::string> Read::Labels(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::vector<std::string> result;

    std::string message = "[Labels]";
    auto input = console->ReadLine(message);

    auto labels = Split(input, " ");

    for (const auto& label : labels)
    {
        if (Validate::Label(label))
            result.emplace_back(label);
    }
    return result;
}
bool Read::Confirm(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::string message = R"([Confirm] "y/n")";
    auto input = Validate::Confirm(
        console->ReadLine(message)
    );

    while (!input)
    {
        console->WriteError("No such confirmation");
        input = Validate::Confirm(
            console->ReadLine(message)
        );
    }
    return input.value();
}
std::string Read::FileName(const std::shared_ptr<ConsoleManipulator>& console)
{
    std::optional<std::string> input;
    input = Validate::FileName(
        console->ReadLine(R"([File name] "example.*")")
    );

    while (!input)
    {
        console->WriteError("Wrong file name entered");
        input = Validate::FileName(
            console->ReadLine("[File name]")
        );
    }
    return input.value();
}
Task Read::Task(const std::shared_ptr<ConsoleManipulator>& console)
{
    ::Task input;

    auto title = Read::Title(console);
    auto date = Read::Date(console);
    auto priority = Read::Priority(console);
    auto labels = Read::Labels(console);

    return *CreateTask(title, date, priority, labels);
}
std::vector<std::string> Split(const std::string& str, const std::string& delimiter)
{
    auto result = std::vector<std::string>{};

    size_t pivot = 0;
    auto tmp = str;

    while (pivot != std::string::npos)
    {
        pivot = tmp.find(delimiter);
        auto sub_str = tmp.substr(0, pivot);

        if (!sub_str.empty())
            result.emplace_back(sub_str);

        tmp.erase(0, pivot + 1);
    }

    return result;
}

//
// Created by Illia Plaksa on 24.11.2021.
//

#include <sstream>
#include "cli/MachineSteps.h"
#include <google/protobuf/util/time_util.h>

StepResult ShowStep::Execute(Context& context)
{
    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    auto task_storage = context.GetStorage();

    if (task_storage)
    {
        auto offset = std::string("\t");
        for (const auto& task : task_storage->GetRootTasks())
        {
            console->WriteLine(ToString(task));
            OutputSubTasks(console, task.id(), *task_storage, offset);
        }
    }

    StepResult result;

    result.next_step = step_factory->CreateStep(StepId::kRoot);
    result.command = std::shared_ptr<Command>(nullptr);

    return result;
}
std::string ShowStep::ToString(const Task::Priority& priority)
{
    switch (priority)
    {
        case Task_Priority_kHigh:return "High";
        case Task_Priority_kMedium:return "Medium";
        case Task_Priority_kLow:return "Low";

        default: return std::string{};
    }
}
std::string ShowStep::ToString(const Task::Status& status)
{
    switch (status)
    {
        case Task_Status_kCompleted: return "Completed";
        case Task_Status_kInProgress: return "In progress";
        default: return std::string{};
    }
}
std::string ShowStep::ToString(const TaskDTO& task_dto)
{
    std::stringstream output;

    const auto& task = task_dto.task();
    const auto& id = task_dto.id();

    output << "ID: " << id.value() << ", "
           << "Title: " << task.title() << ", "
           << "Due date: " << ToString(task.due_date().seconds()) << ", "
           << "Priority: " << ToString(task.priority()) << ", "
           << "Status: " << ToString(task.status()) << ", "
           << "Labels: " << ToString(task.labels());

    return output.str();
}
void ShowStep::OutputSubTasks(const std::shared_ptr<ConsoleManipulator>& console,
                              const TaskId& parent_id,
                              const TaskStorage& storage,
                              const std::string& offset)
{
    for (const auto& task : storage.GetSubTasks(parent_id))
    {
        console->WriteLine(offset + ToString(task));
        OutputSubTasks(console, task.id(), storage, offset + "\t");
    }
}
std::string ShowStep::ToString(const time_t& date)
{
    std::tm tm = *std::localtime(&date);
    std::stringstream stream;
    stream << std::put_time(&tm, "%d.%m.%Y");
    return stream.str();
}
std::string ShowStep::ToString(const google::protobuf::RepeatedPtrField<std::string>& labels)
{
    std::stringstream stream;
    for (const auto& label : labels)
        stream << label << ", ";

    return stream.str();
}



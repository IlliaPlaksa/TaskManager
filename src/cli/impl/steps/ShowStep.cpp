//
// Created by Illia Plaksa on 24.11.2021.
//

#include <sstream>
#include "cli/include/MachineSteps.h"
#include <google/protobuf/util/time_util.h>

StepResult ShowStep::Execute(Context& context)
{
    StepResult result;

    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    auto task_storage = context.GetStorage();

    if (task_storage)
    {
        auto offset = std::string("\t");
        for (const auto& task: task_storage->GetRootTasks())
        {
            std::stringstream output;
            output << ToString(task);

            OutputSubTasks(output, task.id(), *task_storage, offset);

            console->WriteLine(output.str());
        }
    }

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
           << "Label: " << task.label();

    return output.str();
}
void ShowStep::OutputSubTasks(std::ostream& output, const TaskId& parent_id,
                              const TaskStorage& storage, const std::string& offset)
{
    for (const auto& task: storage.GetSubTasks(parent_id))
    {
        output << '\n' << offset << ToString(task);
        OutputSubTasks(output, task.id(), storage, offset + "\t");
    }
}
std::string ShowStep::ToString(const time_t& date)
{
    std::tm tm = *std::localtime(&date);
    std::stringstream stream;
    stream << std::put_time(&tm, "%d.%m.%Y");
    return stream.str();
}



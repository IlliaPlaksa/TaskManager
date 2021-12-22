//
// Created by Illia Plaksa on 24.11.2021.
//

#include <sstream>
#include "../../include/MachineSteps.h"

StepResult ShowStep::Execute(Context &context)
{
    StepResult result;

    auto console = this->GetConsoleManipulator();
    auto task_storage = context.GetTaskStorage();

    if (task_storage)
    {
        for (const auto &task: task_storage->GetRootTasks())
        {
            //
            std::stringstream output;
            output << ToString(task);

            OutputSubTasks(output, task.id(), *task_storage);

            console->WriteLine(output.str());
        }
    }

    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kNone;
    return result;
}
std::string ShowStep::ToString(const Task::Priority &priority)
{
    switch (priority)
    {
        case Task_Priority_kHigh: return "High";
        case Task_Priority_kMedium: return "Medium";
        case Task_Priority_kLow: return "Low";
        default: return std::string{};
    }
}
std::string ShowStep::ToString(const Task::Status &status)
{
    switch (status)
    {
        case Task_Status_kCompleted: return "Completed";
        case Task_Status_kInProgress: return "In progress";
        default: return std::string{};
    }
}
std::string ShowStep::ToString(const TaskToSerialize &task)
{
    std::stringstream output;

    output << "ID: " << task.id().value() << " "
           << "Title: " << task.task().title() << " "
           << "Due date: " << google::protobuf::util::TimeUtil::ToString(task.task().due_date()) << " "
           << "Priority: " << ToString(task.task().priority()) << " "
           << "Status: " << ToString(task.task().status()) << " "
           << "Label: " << task.task().label();

    return output.str();
}
void ShowStep::OutputSubTasks(std::ostream &output, const TaskId &parent_id, const TaskStorage &storage)
{
    output << "\n\t";
    for (const auto& task : storage.GetSubTasks(parent_id))
    {
        output << ToString(task);
        OutputSubTasks(output, task.id(), storage);
    }
}



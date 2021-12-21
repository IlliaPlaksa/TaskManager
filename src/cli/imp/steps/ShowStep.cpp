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
            std::stringstream output;
            output << std::to_string(task.id().value()) << ". " << task.DebugString();

            for (const auto &elem: task_storage->GetSubTasks(task.id()))
            {
                output << '\t' << std::to_string(elem.id().value()) << ". " << elem.DebugString();
            }

            console->WriteLine(output.str());
        }
    }

    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kNone;
    return result;
}

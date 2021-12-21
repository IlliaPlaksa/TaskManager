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
            for (const auto &elem: task_storage->GetSubTasks(task.id()))
            {
                auto id = elem.id();
                std::stringstream output;
                output << std::to_string(id.value()) << ". ";
                elem.SerializeToOstream(&output);

                console->WriteLine(output.str());
            }
    }

    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kNone;
    return result;
}

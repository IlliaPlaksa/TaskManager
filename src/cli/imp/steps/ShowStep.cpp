//
// Created by Illia Plaksa on 24.11.2021.
//

#include "../../include/MachineSteps.h"

StepResult ShowStep::Execute(Context &context)
{
    StepResult result;

    auto console = this->GetConsoleManipulator();
    auto task_storage = context.GetTaskStorage();

    if (task_storage)
    {
        for (const auto &parent_id: task_storage->GetParentIds())
            for (const auto &elem: task_storage->GetTasksByParentId(parent_id))
            {
                auto id = elem.first.value();
                std::string output = "";
                if (id)
                    output = std::to_string(id.value()) + elem.second.ToString();
                else
                    output = elem.second.ToString();
                console->WriteLine(output);
            }
    }

    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kNone;
    return result;
}

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
        for (const auto &parent_id: task_storage->GetParentIds())
            for (const auto &elem: task_storage->GetTasksByParentId(parent_id))
            {
                auto id = elem.first.value();
                std::stringstream output;
                if (id)
                    output << std::to_string(id.value()) << ". " << elem.second.ToString();

                console->WriteLine(output.str());
            }
    }

    result.next_step = GetFactory()->CreateStep(StepId::kRoot);
    result.command_type = CommandType::kNone;
    return result;
}

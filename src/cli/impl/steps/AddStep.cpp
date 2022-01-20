//
// Created by Illia Plaksa on 24.11.2021.
//

#include "cli/include/MachineSteps.h"

StepResult AddStep::Execute(Context& context)
{
    StepResult result;

    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();
    auto variable_set_builder = VariableSetBuilder{};

    console->ResetPrompt("add Task");

    // Filling structure
    variable_set_builder
        .SetTitle(Read::Title(console))
        .SetDate(Read::Date(console))
        .SetPriority(Read::Priority(console))
        .SetLabel(Read::Labels(console))
        .SetStatus(Task_Status_kInProgress);

    auto parent_id = Read::ParentId(console);
    if (parent_id)
        variable_set_builder.SetParent(parent_id.value());

    console->ResetPrompt();
    auto confirm = Read::Confirm(console);

    if (confirm)
    {
        auto var_set = variable_set_builder.GetResult();

        auto task = var_set.MakeTask();
        auto parent_id = var_set.parent_id;

        if (task.has_value())
            result.command = std::shared_ptr<Command>(new AddCommand(*task, parent_id));
    } else
    {
        console->WriteLine("Operation was canceled");
        result.command = std::shared_ptr<Command>(nullptr);
    }
    result.next_step = step_factory->CreateStep(StepId::kRoot);
    return result;
}

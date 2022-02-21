//
// Created by Illia Plaksa on 24.11.2021.
//

#include "cli/include/MachineSteps.h"

StepResult EditStep::Execute(Context& context)
{
    StepResult result;

    auto dependency = this->dependency();

    auto console = dependency->console_manipulator();
    auto step_factory = dependency->step_factory();

    auto variable_set_builder = VariableSetBuilder{};

    console->ResetPrompt("edit Task");

    // Filling structure
    variable_set_builder
        .SetId(Read::Id(console))
        .SetTitle(Read::Title(console))
        .SetDate(Read::Date(console))
        .SetPriority(Read::Priority(console))
        .SetLabels(Read::Labels(console))
        .SetStatus(Task_Status_kInProgress);

    auto parent_id = Read::ParentId(console);
    if (parent_id)
        variable_set_builder.SetParent(parent_id.value());

    console->ResetPrompt();
    auto confirm = Read::Confirm(console);

    if (confirm)
    {
        auto var_set = variable_set_builder.GetResult();
        auto id = var_set.id;
        auto task = var_set.MakeTask();
        auto parent_id = var_set.parent_id;

        if (task.has_value())
            result.command = std::shared_ptr<Command>(new EditCommand(id, *task, parent_id));
    }
    else
    {
        console->WriteLine("Operation was canceled");
        result.command = std::shared_ptr<Command>(nullptr);
    }

    result.next_step = step_factory->CreateStep(StepId::kRoot);
    return result;
}

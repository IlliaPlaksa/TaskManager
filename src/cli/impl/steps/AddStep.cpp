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
        .SetStatus(Task_Status_kInProgress);

    auto label = Read::Label(console);
    if (label)
        variable_set_builder.SetLabel(label.value());

    auto parent_id = Read::ParentId(console);
    if (parent_id)
        variable_set_builder.SetParent(parent_id.value());

    console->ResetPrompt();
    auto confirm = Read::Confirm(console);

    if (confirm)
    {
        *context.GetVariableSet() = variable_set_builder.GetResult();
        result.command_type = CommandType::kAdd;
    } else
    {
        console->WriteLine("Operation was canceled");
        variable_set_builder.Reset();
        result.command_type = CommandType::kNone;
    }
    result.next_step = step_factory->CreateStep(StepId::kRoot);
    return result;
}

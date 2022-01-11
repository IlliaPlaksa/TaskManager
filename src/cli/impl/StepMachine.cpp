//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/StepMachine.h"

#include "../../util/TaskIdComparers.h"

StepMachine::StepMachine(const std::shared_ptr<StepFactory>& step_factory,
                         const std::shared_ptr<Controller>& controller,
                         const std::shared_ptr<CommandFactory>& command_factory)
    :
    step_factory_(step_factory),
    controller_(controller),
    command_factory_(command_factory)
{

}

void StepMachine::Run()
{
    this->context_ = Context();
    auto initial_step = step_factory_->CreateStep(StepId::kRoot);
    this->SetNextStep(initial_step);

    while (current_step_)
    {
        auto result = current_step_->Execute(context_);

        SetNextStep(result.next_step);

        if (result.command_type != CommandType::kNone)
        {
            context_.GetStorage()->Clear();
            auto context_dto = std::shared_ptr<ContextDTO>{new ContextDTO(context_.GetContextDTO())};
            auto command = command_factory_->CreateCommand(result.command_type,
                                                           context_dto);
            auto response = controller_->Action(command);

            if (response.IsError())
            {
                context_.GetVariableSet()->error_message = response.error();
                SetNextStep(step_factory_->CreateStep(StepId::kError));
            } else
            {
                context_.SetFromContextDTO(*context_dto);
            }
        }
    }
}

void StepMachine::SetNextStep(const std::shared_ptr<Step>& step)
{
    this->current_step_ = step;
}



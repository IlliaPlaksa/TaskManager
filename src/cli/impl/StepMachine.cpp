//
// Created by Illia Plaksa on 22.11.2021.
//

#include "../include/StepMachine.h"

#include "util/TaskId/TaskIdComparators.h"

StepMachine::StepMachine(const std::shared_ptr<StepFactory>& step_factory,
                         const std::shared_ptr<ModelController>& controller)
    :
    step_factory_(step_factory),
    controller_(controller)
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
        auto response = result.command->Execute(controller_);

        if (response.IsError())
        {
            context_.SetError(CreateErrorMessage(*response.error()));
            SetNextStep(step_factory_->CreateStep(StepId::kError));
        } else
        {
            context_.SetFromContextDTO();
        }
    }
}

void StepMachine::SetNextStep(const std::shared_ptr<Step>& step)
{
    this->current_step_ = step;
}
std::string StepMachine::CreateErrorMessage(const Model::Response::ErrorType& error_type)
{
    switch (error_type)
    {
        case Model::Response::ErrorType::INVALID_ID: { return "Invalid ID passed"; }
        case Model::Response::ErrorType::EMPTY_TITLE: { return "Empty title of Task passed"; }
        case Model::Response::ErrorType::NON_EXISTING_PARENT_ID: { return "Non-existing parent ID passed"; }
        default: { return "Something went wrong"; }
    }
}


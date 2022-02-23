//
// Created by Illia Plaksa on 22.11.2021.
//

#include "cli/StepMachine.h"
#include "util/TaskId/TaskIdComparators.h"
#include "util/Response/ModelResponseUtils.h"

StepMachine::StepMachine(const std::shared_ptr<StepFactory>& step_factory,
                         const std::shared_ptr<ModelController>& model)
    :
    step_factory_(step_factory),
    model_(model)
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

        if (result.command)
        {
            auto response = result.command->Execute(model_);

            SetContextFromCommandResponse(response);
        }
    }
}

void StepMachine::SetNextStep(const std::shared_ptr<Step>& step)
{
    this->current_step_ = step;
}
std::string StepMachine::CreateErrorMessage(const ModelResponse::ErrorType& error_type)
{
    switch (error_type)
    {
        case ModelResponse::ErrorType::INVALID_ID: { return "Invalid ID entered"; }
        case ModelResponse::ErrorType::EMPTY_TITLE: { return "Empty title of Task entered"; }
        case ModelResponse::ErrorType::NON_EXISTING_PARENT_ID: { return "Non-existing parent ID entered"; }
        default: { return "Something went wrong"; }
    }
}
void StepMachine::SetContextFromCommandResponse(const CommandResponse& response)
{
    BOOST_LOG_TRIVIAL(debug) << "Command returned status: " << to_string(response.model_response->status());

    if (response.IsError())
    {
        BOOST_LOG_TRIVIAL(debug) << "Command returned error: " << to_string(*response.model_response->error()) << ".";

        SetNextStep(step_factory_->CreateStep(StepId::kError));

        auto error_message = CreateErrorMessage(*response.model_response->error());
        context_.SetError(error_message);

        BOOST_LOG_TRIVIAL(debug) << "Command returned error message: " << error_message << ".";
    }
    else
    {
        BOOST_LOG_TRIVIAL(debug) << "Command returned tasks";

        auto tasks = response.tasks;
        auto storage = context_.GetStorage();
        if (tasks.has_value() and storage)
        {
            *storage = tasks.value();
            BOOST_LOG_TRIVIAL(debug) << "Loaded " << tasks->GetTasks().size() << "tasks to Context";
        }
        else
            BOOST_LOG_TRIVIAL(debug) << "Command was successfully executed.";
    }
}

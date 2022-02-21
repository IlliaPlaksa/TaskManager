//
// Created by Illia Plaksa on 18.02.2022.
//

#include "RandomCommandGenerator.h"

#include "util/Task/TaskCreators.h"
#include "util/TaskId/TaskIdCreators.h"

RandomCommandGenerator::RandomCommandGenerator()
    :
    functions_(std::vector<std::shared_ptr<CreateCommandHandler>>{
        std::make_shared<CreateAddCommand>(),
        std::make_shared<CreateAddSubTaskCommand>(),
        std::make_shared<CreateEditCommand>(),
        std::make_shared<CreateEditSubTaskCommand>(),
        std::make_shared<CreateCompleteCommand>(),
        std::make_shared<CreateDeleteCommand>(),
        std::make_shared<CreateShowCommand>(),
    })
{
    srand(time(nullptr));
}
std::shared_ptr<Command> RandomCommandGenerator::GenerateCommand()
{

    auto index = rand() % functions_.size();
    auto result = functions_[index]->operator()();

    return result;
}

Task RandomCommandGenerator::CreateCommandHandler::RandomTask()
{
    auto priorities = std::vector<Task::Priority>{Task_Priority_kHigh, Task_Priority_kMedium, Task_Priority_kLow};

    auto index = rand() % priorities.size();
    auto rand_priority = priorities[index];

    auto rand_time = (time_t) rand();

    return *CreateTask("Title", rand_time, rand_priority, {"label"});
}
TaskId RandomCommandGenerator::CreateCommandHandler::RandomTaskId()
{
    return *CreateTaskId(rand());
}

std::shared_ptr<Command> RandomCommandGenerator::CreateAddCommand::operator()()
{
    auto task = RandomTask();

    return std::make_shared<AddCommand>(task, std::nullopt);
}
std::shared_ptr<Command> RandomCommandGenerator::CreateAddSubTaskCommand::operator()()
{
    auto task = RandomTask();
    auto parent_id = RandomTaskId();

    return std::make_shared<AddCommand>(task, parent_id);
}
std::shared_ptr<Command> RandomCommandGenerator::CreateEditCommand::operator()()
{
    auto task = RandomTask();
    auto task_id = RandomTaskId();

    return std::make_shared<EditCommand>(task_id, task, std::nullopt);
}
std::shared_ptr<Command> RandomCommandGenerator::CreateEditSubTaskCommand::operator()()
{
    auto task = RandomTask();
    auto task_id = RandomTaskId();
    auto parent_id = RandomTaskId();

    return std::make_shared<EditCommand>(task_id, task, parent_id);
}
std::shared_ptr<Command> RandomCommandGenerator::CreateCompleteCommand::operator()()
{
    auto task_id = RandomTaskId();
    return std::make_shared<CompleteCommand>(task_id);
}
std::shared_ptr<Command> RandomCommandGenerator::CreateDeleteCommand::operator()()
{
    auto task_id = RandomTaskId();
    return std::make_shared<DeleteCommand>(task_id);
}
std::shared_ptr<Command> RandomCommandGenerator::CreateShowCommand::operator()()
{
    return std::make_shared<ShowCommand>(std::nullopt);
}
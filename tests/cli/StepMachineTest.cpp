//
// Created by Illia Plaksa on 18.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/StepMachine.h"

#include "mocks/StepFactoryMock.h"
#include "mocks/ModelMock.h"
#include "mocks/ConsoleManipulatorMock.h"
#include "mocks/StepMock.h"
#include "mocks/CommandMock.h"
#include "util/TaskId/TaskIdComparators.h"

class StepMachineTest : ::testing::Test
{
};

TEST(StepMachineTest, shouldRunWithDefaultStep)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};
    auto console = std::make_shared<ConsoleManipulatorMock>(ostream, istream);
    auto factory = std::make_shared<StepFactoryMock>(console);
    auto model = std::make_shared<ModelMock>();

    auto machine = StepMachine(factory, model);

    auto step = std::make_shared<StepMock>();

    auto step_result = StepResult{};
    step_result.next_step = std::shared_ptr<Step>(nullptr);

    auto command = std::make_shared<CommandMock>();
    auto response = CommandResponse{};
    response.model_response = ModelResponse::Success();

    step_result.command = command;

    EXPECT_CALL(*factory, CreateStep(StepId::kRoot))
        .Times(1)
        .WillOnce(::testing::Return(step));

    EXPECT_CALL(*step, Execute(testing::_))
        .Times(1)
        .WillOnce(::testing::Return(step_result));

    EXPECT_CALL(*command, Execute(::testing::_))
    .Times(1)
    .WillOnce(::testing::Return(response));

    machine.Run();
}

TEST(StepMachineTest, shouldProcessErrorResponse)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};
    auto console = std::make_shared<ConsoleManipulatorMock>(ostream, istream);
    auto factory = std::make_shared<StepFactoryMock>(console);
    auto model = std::make_shared<ModelMock>();

    auto machine = StepMachine(factory, model);

    auto step = std::make_shared<StepMock>();

    auto step_result = StepResult{};
    step_result.next_step = std::shared_ptr<Step>(nullptr);

    auto command = std::make_shared<CommandMock>();
    auto response = CommandResponse{};
    response.model_response = ModelResponse::Error(ModelResponse::ErrorType::FAIL);

    step_result.command = command;

    EXPECT_CALL(*factory, CreateStep(StepId::kRoot))
        .Times(1)
        .WillOnce(::testing::Return(step));

    EXPECT_CALL(*factory, CreateStep(StepId::kError))
        .Times(1)
        .WillOnce(::testing::Return(nullptr));

    EXPECT_CALL(*step, Execute(testing::_))
        .Times(1)
        .WillOnce(::testing::Return(step_result));

    EXPECT_CALL(*command, Execute(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(response));

    machine.Run();
}

TEST(StepMachineTest, shouldProcessTasksResponse)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};
    auto console = std::make_shared<ConsoleManipulatorMock>(ostream, istream);
    auto factory = std::make_shared<StepFactoryMock>(console);
    auto model = std::make_shared<ModelMock>();

    auto machine = StepMachine(factory, model);

    auto step = std::make_shared<StepMock>();

    auto step_result = StepResult{};
    step_result.next_step = std::shared_ptr<Step>(nullptr);

    auto command = std::make_shared<CommandMock>();
    auto response = CommandResponse{};
    response.tasks = TaskStorage();

    step_result.command = command;

    EXPECT_CALL(*factory, CreateStep(StepId::kRoot))
        .Times(1)
        .WillOnce(::testing::Return(step));

    EXPECT_CALL(*step, Execute(testing::_))
        .Times(1)
        .WillOnce(::testing::Return(step_result));

    EXPECT_CALL(*command, Execute(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(response));

    machine.Run();
}

//
// Created by Illia Plaksa on 18.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/StepMachine.h"

#include "mocks/StepFactoryMock.h"
#include "mocks/ModelControllerMock.h"
#include "mocks/ConsoleManipulatorMock.h"
#include "mocks/StepMock.h"
#include "mocks/CommandMock.h"
#include "util/TaskId/TaskIdComparators.h"

class StepMachineTest : public ::testing::Test
{
protected:
    std::stringstream ostream;
    std::stringstream istream;
    std::shared_ptr<ConsoleManipulator> console;
    std::shared_ptr<StepFactoryMock> factory;
    std::shared_ptr<ModelControllerMock> model;

    std::shared_ptr<StepMock> step;
    StepResult step_result;

    std::shared_ptr<CommandMock> command;
    CommandResponse response;

    void SetUp() override
    {
        ostream = std::stringstream{};
        istream = std::stringstream{};
        console = std::make_shared<ConsoleManipulatorMock>(ostream, istream);
        model = std::make_shared<ModelControllerMock>();
        factory = std::make_shared<StepFactoryMock>(console);

        step = std::make_shared<StepMock>();
        step_result = StepResult{};
        step_result.next_step = std::shared_ptr<Step>(nullptr);

        command = std::make_shared<CommandMock>();
        response = CommandResponse{};
    }
};

TEST_F(StepMachineTest, shouldRunWithDefaultStep)
{
    StepMachine machine{factory, model};

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

TEST_F(StepMachineTest, shouldProcessErrorResponse)
{
    StepMachine machine{factory, model};

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

TEST_F(StepMachineTest, shouldProcessTasksResponse)
{
    StepMachine machine{factory, model};

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

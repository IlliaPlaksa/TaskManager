//
// Created by Illia Plaksa on 01.02.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/MachineSteps.h"

#include "mocks/ConsoleManipulatorMock.h"
#include "mocks/StepFactoryMock.h"
#include "mocks/StepDependencyMock.h"
#include "mocks/StepMock.h"

#include "util/Task/TaskCreators.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskId/TaskIdComparators.h"
#include "util/TaskDTO/TaskDTOCreators.h"

class ShowStepTest : public ::testing::Test
{
protected:
    std::stringstream ostream_;
    std::stringstream istream_;
    std::shared_ptr<ConsoleManipulatorMock> console_;
    std::shared_ptr<StepFactoryMock> step_factory_;
    std::shared_ptr<StepDependencyMock> dependency_;

    TaskStorage task_storage_;

    void SetUp() override
    {
        console_ = std::make_shared<ConsoleManipulatorMock>(ostream_, istream_);
        step_factory_ = std::make_shared<StepFactoryMock>(console_);
        dependency_ = std::make_shared<StepDependencyMock>(step_factory_, console_);

        task_storage_ = TaskStorage{};

        auto tasks = std::vector<TaskDTO>{
            *CreateTaskDTO(*CreateTaskId(0),
                           *CreateTask("title1", time(nullptr), Task_Priority_kHigh, {"label1", "label2"})),
            *CreateSubTaskDTO(*CreateTaskId(123),
                              *CreateTask("title2", time(nullptr), Task_Priority_kHigh),
                              *CreateTaskId(0))
        };

        task_storage_.LoadTasks(tasks);
    }
};

using ::testing::_;

TEST_F(ShowStepTest, shouldReturnCommand)
{
    auto show_step = ShowStep(dependency_);

    auto context = Context{};
    *context.GetStorage() = task_storage_;

    EXPECT_CALL(*dependency_, console_manipulator())
        .WillRepeatedly(::testing::Return(console_));

    EXPECT_CALL(*dependency_, step_factory())
        .WillRepeatedly(::testing::Return(step_factory_));

    EXPECT_CALL(*console_, WriteLine(_))
        .WillRepeatedly(::testing::Return());

    auto result_step = std::shared_ptr<StepMock>();

    EXPECT_CALL(*step_factory_, CreateStep(StepId::kRoot))
        .WillOnce(::testing::Return(result_step));

    auto result = show_step.Execute(context);

    EXPECT_EQ(result.next_step, result_step);
    EXPECT_EQ(result.command.get(), nullptr);
}

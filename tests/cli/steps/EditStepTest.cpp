//
// Created by Illia Plaksa on 01.02.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/MachineSteps.h"

#include "mocks/ConsoleManipulatorMock.h"
#include "mocks/StepFactoryMock.h"
#include "mocks/StepDependencyMock.h"
#include "mocks/StepMock.h"

class EditStepTest : public ::testing::Test
{
protected:
    std::stringstream ostream_;
    std::stringstream istream_;
    std::shared_ptr<ConsoleManipulatorMock> console_;
    std::shared_ptr<StepFactoryMock> step_factory_;
    std::shared_ptr<StepDependencyMock> dependency_;

    void SetUp() override
    {
        console_ = std::make_shared<ConsoleManipulatorMock>(ostream_, istream_);
        step_factory_ = std::make_shared<StepFactoryMock>(console_);
        dependency_ = std::make_shared<StepDependencyMock>(step_factory_, console_);
    }

};

using ::testing::_;

TEST_F(EditStepTest, shouldReturnCommand)
{
    auto root_step = EditStep(dependency_);

    auto task_id = "9999";
    auto title = "Example title";
    auto date = "14.10.1999";
    auto priority = "medium";
    auto labels = "label1 label2";
    auto parent_id = "1234";
    auto positive_confirm = "y";

    EXPECT_CALL(*dependency_, console_manipulator())
        .WillRepeatedly(::testing::Return(console_));

    EXPECT_CALL(*dependency_, step_factory())
        .WillRepeatedly(::testing::Return(step_factory_));

    EXPECT_CALL(*console_, ReadLine(_))
        .WillOnce(::testing::Return(task_id))
        .WillOnce(::testing::Return(title))
        .WillOnce(::testing::Return(date))
        .WillOnce(::testing::Return(priority))
        .WillOnce(::testing::Return(labels))
        .WillOnce(::testing::Return(parent_id))
        .WillOnce(::testing::Return(positive_confirm));

    auto result_step = std::shared_ptr<StepMock>();

    EXPECT_CALL(*step_factory_, CreateStep(StepId::kRoot))
        .WillOnce(::testing::Return(result_step));

    auto context = Context{};
    auto result = root_step.Execute(context);

    EXPECT_EQ(result.next_step, result_step);
    EXPECT_NE(result.command.get(), nullptr);
}

TEST_F(EditStepTest, shouldNotReturnCommand)
{
    auto root_step = EditStep(dependency_);

    auto task_id = "9999";
    auto title = "Example title";
    auto date = "14.10.1999";
    auto priority = "medium";
    auto labels = "label1 label2";
    auto parent_id = "1234";
    auto negative_confirm = "n";

    EXPECT_CALL(*dependency_, console_manipulator())
        .WillRepeatedly(::testing::Return(console_));

    EXPECT_CALL(*dependency_, step_factory())
        .WillRepeatedly(::testing::Return(step_factory_));

    EXPECT_CALL(*console_, ReadLine(_))
        .WillOnce(::testing::Return(task_id))
        .WillOnce(::testing::Return(title))
        .WillOnce(::testing::Return(date))
        .WillOnce(::testing::Return(priority))
        .WillOnce(::testing::Return(labels))
        .WillOnce(::testing::Return(parent_id))
        .WillOnce(::testing::Return(negative_confirm));

    auto result_step = std::shared_ptr<StepMock>();

    EXPECT_CALL(*step_factory_, CreateStep(StepId::kRoot))
        .WillOnce(::testing::Return(result_step));
    auto context = Context{};
    auto result = root_step.Execute(context);

    EXPECT_EQ(result.next_step, result_step);
    EXPECT_EQ(result.command.get(), nullptr);
}
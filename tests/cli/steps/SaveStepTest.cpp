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

class SaveStepTest : public ::testing::Test
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

TEST_F(SaveStepTest, shouldReturnCommand)
{
    auto save_step = SaveStep(dependency_);

    auto file_name = "file_name.txt";

    EXPECT_CALL(*dependency_, console_manipulator())
        .WillRepeatedly(::testing::Return(console_));

    EXPECT_CALL(*dependency_, step_factory())
        .WillRepeatedly(::testing::Return(step_factory_));

    EXPECT_CALL(*console_, ReadLine(_))
        .WillOnce(::testing::Return(file_name));

    auto result_step = std::shared_ptr<StepMock>();

    EXPECT_CALL(*step_factory_, CreateStep(StepId::kRoot))
        .WillOnce(::testing::Return(result_step));

    auto context = Context{};
    auto result = save_step.Execute(context);

    EXPECT_EQ(result.next_step, result_step);
    EXPECT_NE(result.command.get(), nullptr);
}

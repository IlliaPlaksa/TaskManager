//
// Created by Illia Plaksa on 17.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/StepDependency.h"

#include "mocks/ConsoleManipulatorMock.h"
#include "mocks/StepFactoryMock.h"

class StepDependencyTest : ::testing::Test
{
};

TEST(StepDependencyTest, shouldCreate)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};
    auto console = std::make_shared<ConsoleManipulatorMock>(ostream, istream);
    auto factory = std::make_shared<StepFactoryMock>(console);
    auto obj = StepDependency{factory, console};

    EXPECT_EQ(obj.step_factory(), factory);
    EXPECT_EQ(obj.console_manipulator(), console);
}



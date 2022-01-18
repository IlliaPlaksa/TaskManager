//
// Created by Illia Plaksa on 18.01.2022.
//


#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/StepFactory.h"
#include "cli/include/MachineSteps.h"

#include "mocks/ConsoleManipulatorMock.h"
#include "mocks/StepFactoryMock.h"
#include "mocks/StepDependencyMock.h"

class StepFactoryTest : ::testing::Test
{
};

TEST(StepFactoryTest, shouldReturnSelfShared)
{
    auto console = std::make_shared<ConsoleManipulatorMock>();

    auto obj = std::make_shared<StepFactory>(console);

    EXPECT_EQ(obj.get(), obj->shared().get());
}

TEST(StepFactory, shouldCreateSteps)
{
    auto console = std::make_shared<ConsoleManipulatorMock>();
    auto factory = std::make_shared<StepFactory>(console);

    auto test_ids = std::vector<StepId>
        {
            StepId::kError,
            StepId::kRoot,
            StepId::kHelp,
            StepId::kExit,
            StepId::kAdd,
            StepId::kEdit,
            StepId::kComplete,
            StepId::kDelete,
            StepId::kShow,
            StepId::kUpdate,
            StepId::kSave,
            StepId::kLoad,
        };


    for(auto elem : test_ids)
    {
        EXPECT_TRUE(factory->CreateStep(elem));
    }

    EXPECT_FALSE(factory->CreateStep(StepId::kNone));
}

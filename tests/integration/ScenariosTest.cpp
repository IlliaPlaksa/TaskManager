//
// Created by Illia Plaksa on 23.02.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <sstream>

#include "cli/StepMachine.h"
#include "DefaultModelController.h"
#include "model/TaskManager.h"
#include "mocks/ConsoleManipulatorMock.h"

class ScenariosTest : public ::testing::Test
{
protected:
    std::shared_ptr<ConsoleManipulatorMock> console_;
    std::shared_ptr<View> view_;

    void SetUp() override
    {
    }

    void LaunchTest(const std::vector<std::string>& inputs, const std::vector<std::string>& expect_show)
    {
        std::stringstream output{};
        std::stringstream input{};

        console_ = std::make_shared<ConsoleManipulatorMock>(output, input);

        {
            testing::InSequence s;
            for (const auto& elem : inputs)
            {
                EXPECT_CALL(*console_, ReadLine(::testing::_)).WillOnce(testing::Return(elem));
            }

            EXPECT_CALL(*console_, ReadLine(::testing::_))
                .WillOnce(testing::Return("show"))
                .WillOnce(testing::Return(""))
                .WillOnce(testing::Return("exit"));
        }

        EXPECT_CALL(*console_, WriteError(testing::_)).Times(testing::AnyNumber());
        EXPECT_CALL(*console_, WriteLine(testing::_)).Times(testing::AnyNumber());

        {
            testing::InSequence s;
            for (const std::string& show : expect_show) {
                EXPECT_CALL(*console_, WriteLine(show)).Times(1);
            }
        }

        auto step_factory = std::make_shared<StepFactory>(console_);

        auto generator = std::make_unique<IdGenerator>();
        auto model = std::make_unique<TaskManager>(std::move(generator));
        auto controller = std::make_shared<DefaultModelController>(std::move(model));

        view_ = std::make_shared<StepMachine>(step_factory, controller);

        view_->Run();
    }
};

TEST_F(ScenariosTest, scenario1)
{
    auto scenario = std::vector<std::string>{
        "add",
        "Title",
        "1.1.2022",
        "low",
        "",
        "",
        "y",
        "complete",
        "0",
    };

    auto expected_output = std::vector<std::string>{
        "ID: 0, Title: Title, Due date: 01.01.2022, Priority: Low, Status: Completed, Labels: "
    };

    LaunchTest(scenario, expected_output);
}

TEST_F(ScenariosTest, scenario2)
{
    auto scenario = std::vector<std::string>{
        "add",
        "Parent",
        "1.1.2022",
        "low",
        "",
        "",
        "y",
        "add",
        "Child task",
        "31.12.2022",
        "high",
        "child",
        "0",
        "y",
        "add",
        "Third child",
        "19.07.2022",
        "medium",
        "child",
        "0",
        "y",
        "complete",
        "1",
    };

    auto expected_output = std::vector<std::string>{
        "ID: 0, Title: Parent, Due date: 01.01.2022, Priority: Low, Status: In progress, Labels: ",
        "\tID: 1, Title: Child task, Due date: 31.12.2022, Priority: High, Status: Completed, Labels: child, ",
        "\tID: 2, Title: Third child, Due date: 19.07.2022, Priority: Medium, Status: In progress, Labels: child, ",
    };

    LaunchTest(scenario, expected_output);
}

TEST_F(ScenariosTest, scenario3)
{
    auto scenario = std::vector<std::string>{
        "add",
        "Parent task",
        "4.11.2090",
        "high",
        "label",
        "",
        "y",
        "add",
        "First child",
        "1.12.2200",
        "low",
        "child",
        "0",
        "y",
        "add",
        "Second child",
        "12.3.2021",
        "medium",
        "child",
        "0",
        "y",
        "save",
        "file.txt",
        "delete",
        "1",
        "load",
        "file.txt",
    };

    auto expected_output = std::vector<std::string>{
        "ID: 0, Title: Parent task, Due date: 04.11.2090, Priority: High, Status: In progress, Labels: label, ",
        "\tID: 1, Title: First child, Due date: 01.12.2200, Priority: Low, Status: In progress, Labels: child, ",
        "\tID: 2, Title: Second child, Due date: 12.03.2021, Priority: Medium, Status: In progress, Labels: child, ",
    };

    LaunchTest(scenario, expected_output);
}
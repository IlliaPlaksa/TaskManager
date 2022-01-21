//
// Created by Illia Plaksa on 19.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/Readers.h"
#include "mocks/ConsoleManipulatorMock.h"

class ReadersTest : public ::testing::Test
{
protected:
    std::stringstream ostream_;
    std::stringstream istream_;
    std::shared_ptr<ConsoleManipulatorMock> console_;

    void SetUp() override
    {
        ostream_ = std::stringstream{};
        istream_ = std::stringstream{};
        console_ = std::make_shared<ConsoleManipulatorMock>(ostream_, istream_);
    }
};

TEST_F(ReadersTest, shouldRejectEmptyTitle)
{
    auto wrong_title = "";
    auto correct_title = "Right title";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .Times(2)
        .WillOnce(::testing::Return(wrong_title))
        .WillOnce(::testing::Return(correct_title));

    auto result = Read::Title(console_);

    EXPECT_FALSE(result.empty());
}

TEST_F(ReadersTest, shouldReadId)
{
    auto input = "12345";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(input));

    auto result = Read::Id(console_);

    EXPECT_TRUE(result.value() >= 0);
}

TEST_F(ReadersTest, shouldRejectWrongIdValue)
{
    auto input = std::vector<std::string>{
        "-12345",
        "     ",
        ""};

    auto correct_id = "12345";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(input[0]))
        .WillOnce(::testing::Return(input[1]))
        .WillOnce(::testing::Return(input[2]))
        .WillOnce(::testing::Return(correct_id));

    auto result = Read::Id(console_);

    EXPECT_TRUE(result.value() >= 0);
}

TEST_F(ReadersTest, shouldReadParentId)
{
    auto input = "12345";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(input));

    auto result = Read::ParentId(console_);

    EXPECT_TRUE(result.has_value());
}

TEST_F(ReadersTest, shouldRejectWrongParentIdValue)
{
    auto input = "-12345";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(input));

    auto result = Read::ParentId(console_);

    EXPECT_FALSE(result.has_value());
}

TEST_F(ReadersTest, shouldReadCorrectDate)
{
    auto correct_date_input = std::vector<std::string>{
        "12.12.2020",
        "9.8.1970",
        "30.01.2022"};

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(correct_date_input[0]))
        .WillOnce(::testing::Return(correct_date_input[1]))
        .WillOnce(::testing::Return(correct_date_input[2]));

    auto result = Read::Date(console_);
    EXPECT_TRUE(result >= 0);

    result = Read::Date(console_);
    EXPECT_TRUE(result >= 0);

    result = Read::Date(console_);
    EXPECT_TRUE(result >= 0);
}

TEST_F(ReadersTest, shouldRejectWrongAndBlankDate)
{
    auto wrong_date_input = std::vector<std::string>{
        "2.2.2",
        "0.13.2010",
        "32.13.2022",
    };

    auto correct_date = "01.01.2001";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(wrong_date_input[0]))
        .WillOnce(::testing::Return(wrong_date_input[1]))
        .WillOnce(::testing::Return(wrong_date_input[2]))
        .WillOnce(::testing::Return(correct_date));

    auto result = Read::Date(console_);
    EXPECT_TRUE(result >= 0);
}

TEST_F(ReadersTest, shouldReadCommand)
{
    auto correct_command = std::vector<std::string>{
        "help",
        "exit",
        "add",
        "delete",
        "complete",
        "edit",
        "show"};

    EXPECT_CALL(*console_, ReadLine())
        .WillOnce(::testing::Return(correct_command[0]))
        .WillOnce(::testing::Return(correct_command[1]))
        .WillOnce(::testing::Return(correct_command[2]))
        .WillOnce(::testing::Return(correct_command[3]))
        .WillOnce(::testing::Return(correct_command[4]))
        .WillOnce(::testing::Return(correct_command[5]))
        .WillOnce(::testing::Return(correct_command[6]));

    auto result = StepId::kNone;
    for (size_t i = 0 ; i < correct_command.size() ; ++i)
    {
        result = Read::Command(console_);
        EXPECT_TRUE(result != StepId::kNone);
    }
}

TEST_F(ReadersTest, shouldRejectWrongCommands)
{
    auto wrong_command_input = std::vector<std::string>{
        "   ",
        "some command",
        "asdfhkj",
        "",
    };

    auto correct_command = "help";

    EXPECT_CALL(*console_, ReadLine())
        .WillOnce(::testing::Return(wrong_command_input[0]))
        .WillOnce(::testing::Return(wrong_command_input[1]))
        .WillOnce(::testing::Return(wrong_command_input[2]))
        .WillOnce(::testing::Return(wrong_command_input[3]))
        .WillOnce(::testing::Return(correct_command));

    auto result = Read::Command(console_);
    EXPECT_TRUE(result != StepId::kNone);
}

TEST_F(ReadersTest, shouldReadPriority)
{
    auto correct_priorities = std::vector<std::string>{
        "high",
        "medium",
        "low",
    };

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(correct_priorities[0]))
        .WillOnce(::testing::Return(correct_priorities[1]))
        .WillOnce(::testing::Return(correct_priorities[2]));

    auto possible_priorities = std::vector<Task::Priority>{
        Task_Priority_kHigh,
        Task_Priority_kMedium,
        Task_Priority_kLow,
    };

    for (size_t i = 0 ; i < correct_priorities.size() ; ++i)
    {
        auto result = Read::Priority(console_);
        bool is_any_of_possible = std::any_of(possible_priorities.cbegin(), possible_priorities.cend(),
                                              [&result](const auto& priority)
                                              {
                                                  return result == priority;
                                              });
        EXPECT_TRUE(is_any_of_possible);
    }
}

TEST_F(ReadersTest, shouldRejectWrongPriorityInput)
{
    auto wrong_input = std::vector<std::string>{
        "",
        "    ",
        "abcd",
    };

    auto correct_input = "high";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(wrong_input[0]))
        .WillOnce(::testing::Return(wrong_input[1]))
        .WillOnce(::testing::Return(wrong_input[2]))
        .WillOnce(::testing::Return(correct_input));

    auto result = Read::Priority(console_);

    EXPECT_EQ(result, Task_Priority_kHigh);
}

TEST_F(ReadersTest, shouldReadConfirmation)
{
    auto correct_priorities = std::vector<std::string>{
        "y",
        "n",
    };

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(correct_priorities[0]))
        .WillOnce(::testing::Return(correct_priorities[1]));

    for (size_t i = 0 ; i < correct_priorities.size() ; ++i)
    {
        Read::Confirm(console_);
    }
}

TEST_F(ReadersTest, shouldRejectWrongConfirmationInput)
{
    auto wrong_input = std::vector<std::string>{
        "",
        "    ",
        "abcd",
    };

    auto correct_input = "y";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(wrong_input[0]))
        .WillOnce(::testing::Return(wrong_input[1]))
        .WillOnce(::testing::Return(wrong_input[2]))
        .WillOnce(::testing::Return(correct_input));

    auto result = Read::Confirm(console_);

    EXPECT_EQ(result, true);
}

TEST_F(ReadersTest, shouldReadFileName)
{
    auto correct_priorities = std::vector<std::string>{
        "file.txt",
        "example.bin",
    };

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(correct_priorities[0]))
        .WillOnce(::testing::Return(correct_priorities[1]));

    for (size_t i = 0 ; i < correct_priorities.size() ; ++i)
    {
        auto result = Read::FileName(console_);
        EXPECT_FALSE(result.empty());
    }
}

TEST_F(ReadersTest, shouldRejectWrongFileNameInput)
{
    auto wrong_input = std::vector<std::string>{
        "",
        "    ",
        "asdflk",
    };

    auto correct_input = "file_example.txt";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .WillOnce(::testing::Return(wrong_input[0]))
        .WillOnce(::testing::Return(wrong_input[1]))
        .WillOnce(::testing::Return(wrong_input[2]))
        .WillOnce(::testing::Return(correct_input));

    auto result = Read::FileName(console_);

    EXPECT_FALSE(result.empty());
}

TEST_F(ReadersTest, shouldReadLabels)
{
    auto input_vect = std::vector<std::string>{
        "first",
        "second",
        "third"
    };

    auto input = std::stringstream{};

    for (const auto& label: input_vect)
        input << label << " ";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(input.str()));

    auto result = Read::Labels(console_);

    ASSERT_FALSE(result.empty());

    for (const auto& label: input_vect)
        EXPECT_TRUE(std::find(result.begin(), result.end(), label) != input_vect.end());
}

TEST_F(ReadersTest, ReadLabelsShouldRejectBlankLabels)
{
    auto input = "            ";

    EXPECT_CALL(*console_, ReadLine(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(input));

    auto result = Read::Labels(console_);

    EXPECT_TRUE(result.empty());
}
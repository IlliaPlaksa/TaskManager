//
// Created by Illia Plaksa on 21.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/Readers.h"

class ValidatorsTest : public ::testing::Test
{

};

TEST(ValidatorsTest, shouldApproveCorrectCommand)
{
    auto correct_input = std::vector<std::string>{
        "exit",
        "help",
        "add",
        "edit",
        "complete",
        "delete",
        "show",
        "save",
        "load",
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::Command(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectCommand)
{
    auto wrong_input = std::vector<std::string>{
        "",
        "   ",
        "asdlfkj",
        "12345"
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::Command(input);
        EXPECT_FALSE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldApproveCorrectTitle)
{
    auto correct_input = std::vector<std::string>{
        "Title",
        "abcd",
        "Example title"
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::Title(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectBlankTitle)
{
    auto wrong_input = std::vector<std::string>{
        ""
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::Title(input);
        EXPECT_FALSE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldApproveCorrectId)
{
    auto correct_input = std::vector<std::string>{
        "12345",
        "0",
        "1"
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::Id(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectWrongId)
{
    auto wrong_input = std::vector<std::string>{
        "-12345",
        "   ",
        ""
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::Id(input);
        EXPECT_FALSE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldApproveCorrectDate)
{
    auto correct_input = std::vector<std::string>{
        "12.03.2020",
        "1.1.2002",
        "01.01.1999"
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::Date(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectWrongDate)
{
    auto wrong_input = std::vector<std::string>{
        "32.10.2000",
        "123.123.1233",
        "01.14.1999",
        "1.1.1000",
        "     ",
        ""
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::Date(input);
        EXPECT_FALSE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldApproveCorrectPriority)
{
    auto correct_input = std::vector<std::string>{
        "high",
        "low",
        "medium"
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::Priority(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectWrongPriority)
{
    auto wrong_input = std::vector<std::string>{
        "LOL",
        "HIGH",
        "highh",
        "lox",
        "     ",
        ""
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::Priority(input);
        EXPECT_FALSE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldApproveCorrectLabel)
{
    auto correct_input = std::vector<std::string>{
        "ads;lfj",
        "Example_label",
        "sslsadf"
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::Label(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectWrongLabel)
{
    auto wrong_input = std::vector<std::string>{
        ""
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::Priority(input);
        EXPECT_FALSE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldApproveCorrectConfirmation)
{
    auto correct_input = std::vector<std::string>{
        "y",
        "n",
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::Confirm(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectWrongConfirmation)
{
    auto wrong_input = std::vector<std::string>{
        "",
        "sdflkgj",
        "    "
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::Confirm(input);
        EXPECT_FALSE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldApproveCorrectFileName)
{
    auto correct_input = std::vector<std::string>{
        "file.txt",
        "example.bin",
    };

    for (const auto& input : correct_input)
    {
        auto result = Validate::FileName(input);
        EXPECT_TRUE(result.has_value());
    }
}

TEST(ValidatorsTest, shouldRejectWrongFileName)
{
    auto wrong_input = std::vector<std::string>{
        "",
        "sdflkgj",
        "    "
    };

    for (const auto& input : wrong_input)
    {
        auto result = Validate::FileName(input);
        EXPECT_FALSE(result.has_value());
    }
}
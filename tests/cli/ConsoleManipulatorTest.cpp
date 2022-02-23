//
// Created by Illia Plaksa on 18.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/ConsoleManipulator.h"

class ConsoleManipulatorTest : ::testing::Test
{
};

TEST(ConsoleManipulatorTest, shouldWriteLine)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};

    auto console = ConsoleManipulator{ostream, istream};

    auto message = "Console message";

    console.WriteLine(message);

    auto output = std::string{};

    getline(ostream, output);

    EXPECT_EQ(output, message);
}

TEST(ConsoleManipulatorTest, shouldWriteError)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};
    auto console = ConsoleManipulator{ostream, istream};

    auto message = std::string{"Error message"};

    console.WriteError(message);

    auto input = std::string{};

    getline(ostream, input);

    EXPECT_EQ(input, "[Error]\t" + message);
}

TEST(ConsoleManipulatorTest, shouldReadline)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};

    auto console = ConsoleManipulator{ostream, istream};
    auto input = std::string{"Input string"};
    auto output = std::string();

    istream << input;

    auto actual_input = console.ReadLine();

    getline(ostream, output);

    EXPECT_EQ(output, std::string(" > "));
    EXPECT_EQ(actual_input, input);

    ostream = std::stringstream{};
    istream = std::stringstream{};

    istream << input;

    auto message = std::string("Message");
    actual_input = console.ReadLine(message);

    getline(ostream, output);

    EXPECT_EQ(output, std::string(' ' + message + "> "));
    EXPECT_EQ(actual_input, input);
}

TEST(ConsoleManipulatorTest, shouldResetPromps)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};

    auto console = ConsoleManipulator{ostream, istream};

    auto message = std::string{"Prompt"};

    console.ResetPrompt(message);

    console.ReadLine();

    auto output = std::string{};
    getline(ostream, output);

    EXPECT_EQ(output, message + " > ");

    ostream = std::stringstream{};
    istream = std::stringstream{};

    console.ResetPrompt();
    console.ReadLine();
    getline(ostream, output);

    EXPECT_EQ(output, " > ");
}


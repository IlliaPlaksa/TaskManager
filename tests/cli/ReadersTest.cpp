//
// Created by Illia Plaksa on 19.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/Readers.h"
#include "mocks/ConsoleManipulatorMock.h"

class ReadersTest : ::testing::Test
{
};

TEST(ReadersTest, shouldReadLabels)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};
    auto console = std::make_shared<ConsoleManipulatorMock>(ostream, istream);

    auto input_vect = std::vector<std::string>{
        "first",
        "second",
        "third"
    };

    auto input = std::stringstream{};

    for (const auto& label: input_vect)
        input << label << " ";

    EXPECT_CALL(*console, ReadLine(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(input.str()));

    auto result = Read::Labels(console);

    ASSERT_FALSE(result.empty());

    for (const auto& label: input_vect)
        EXPECT_TRUE(std::find(result.begin(), result.end(), label) != input_vect.end());
}

TEST(ReadersTest, shouldRejectBlankLabels)
{
    auto ostream = std::stringstream{};
    auto istream = std::stringstream{};
    auto console = std::make_shared<ConsoleManipulatorMock>(ostream, istream);

    auto input = "            ";

    EXPECT_CALL(*console, ReadLine(::testing::_))
        .Times(1)
        .WillOnce(::testing::Return(input));

    auto result = Read::Labels(console);

    EXPECT_TRUE(result.empty());
}
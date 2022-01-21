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

}
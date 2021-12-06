//
// Created by Illia Plaksa on 14.11.2021.
//

#include "gtest/gtest.h"
#include "../../src/model/include/TaskId.h"

class TaskIdTest : public ::testing::Test {};

TEST(TaskIdTest, shouldCreate)
{
    auto excpected_value = 1234;
    auto id = TaskId::Create(excpected_value);
    EXPECT_EQ(excpected_value, id.value());
}

TEST(TaskIdTest, shouldThrowNegativeValueException)
{
    auto excpected_value = -1234;
    EXPECT_THROW(TaskId::Create(excpected_value), std::runtime_error);
}


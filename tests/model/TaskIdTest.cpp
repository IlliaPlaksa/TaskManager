//
// Created by Illia Plaksa on 14.11.2021.
//

#include "gtest/gtest.h"
#include "../../src/model/TaskId.h"

class TaskIdTest : public ::testing::Test {};

TEST(TaskIdTest, shouldCreate)
{
    auto excpected_value = -1234;
    auto id = TaskId::Create(excpected_value);
    EXPECT_EQ(excpected_value, id.value());
}


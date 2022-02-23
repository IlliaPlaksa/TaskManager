//
// Created by Illia Plaksa on 23.02.2022.
//

#include "gtest/gtest.h"

#include "util/TaskId/TaskIdComparators.h"
#include "util/TaskId/TaskIdCreators.h"

class TaskUtilsTest : public ::testing::Test
{
};

TEST_F(TaskUtilsTest, shouldCreateTaskId)
{
    auto value = 1234567;
    auto task_id = CreateTaskId(value);
    ASSERT_TRUE(task_id.has_value());
}

TEST_F(TaskUtilsTest, shouldNotCreateTaskIdWithNegativeValue)
{
    auto value = -1234567;
    auto task_id = CreateTaskId(value);
    ASSERT_FALSE(task_id.has_value());
}

TEST_F(TaskUtilsTest, shouldCompareEqualTaskId)
{
    auto value = 1234567;

    auto task_id1 = CreateTaskId(value);
    auto task_id2 = CreateTaskId(value);

    ASSERT_EQ(task_id1, task_id2);
}

TEST_F(TaskUtilsTest, shouldCompareNonEqualTaskId)
{
    auto value1 = 1234567;
    auto value2 = 1234568;

    auto task_id1 = CreateTaskId(value1);
    auto task_id2 = CreateTaskId(value2);

    ASSERT_NE(task_id1, task_id2);
}


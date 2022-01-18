//
// Created by Illia Plaksa on 18.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/VariableSet.h"

#include "util/TaskId/TaskIdCreators.h"
#include "util/Task/TaskCreators.h"
#include "util/TaskDTO/TaskDTOCreators.h"

class VariableSetTest : ::testing::Test
{
};

TEST(VariableSetTest, shouldMakeTask)
{
    auto var_set = VariableSet{};

    EXPECT_EQ(var_set.MakeTask(), std::nullopt);
    EXPECT_EQ(var_set.MakeTaskDTO(), std::nullopt);

    var_set.id = *CreateTaskId(1234);
    var_set.title = "Title";
    var_set.date = time(nullptr);
    var_set.priority = Task_Priority_kHigh;
    var_set.parent_id = *CreateTaskId(0);

    EXPECT_NE(var_set.MakeTask(), std::nullopt);
    EXPECT_NE(var_set.MakeTaskDTO(), std::nullopt);
}

TEST(VariableSetTest, shouldClear)
{
    auto var_set = VariableSet{};

    var_set.id = *CreateTaskId(1234);
    var_set.title = "Title";
    var_set.date = time(nullptr);
    var_set.priority = Task_Priority_kHigh;
    var_set.parent_id = *CreateTaskId(0);

    var_set.Clear();

    EXPECT_EQ(var_set, VariableSet{});

}
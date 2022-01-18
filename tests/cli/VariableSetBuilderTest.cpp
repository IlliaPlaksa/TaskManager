//
// Created by Illia Plaksa on 18.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/VariableSetBuilder.h"
#include "util/TaskId/TaskIdCreators.h"

class VariableSetBuilderTest : ::testing::Test
{
};

TEST(VariableSetBuilderTest, shouldSetAllFields)
{
    auto builder = VariableSetBuilder{};

    auto var_set = VariableSet{};
    var_set.title = "Title";
    var_set.date = time(nullptr);
    var_set.priority = Task_Priority_kHigh;
    var_set.status = Task_Status_kInProgress;
    var_set.id = *CreateTaskId(123);
    var_set.parent_id = *CreateTaskId(0);
    var_set.label = "Label";
    var_set.file_name = "file.txt";


    // Filling structure
    builder
        .SetTitle(var_set.title)
        .SetDate(var_set.date)
        .SetPriority(var_set.priority)
        .SetStatus(var_set.status)
        .SetId(var_set.id)
        .SetParent(*var_set.parent_id)
        .SetLabel(var_set.label)
        .SetFileName(var_set.file_name);


    EXPECT_EQ(builder.GetResult(), var_set);
}

TEST(VariableSetBuilderTest, shouldReset)
{
    auto builder = VariableSetBuilder{};

    auto var_set = VariableSet{};
    var_set.title = "Title";
    var_set.date = time(nullptr);
    var_set.priority = Task_Priority_kHigh;
    var_set.status = Task_Status_kInProgress;
    var_set.id = *CreateTaskId(123);
    var_set.parent_id = *CreateTaskId(0);
    var_set.label = "Label";
    var_set.file_name = "file.txt";


    // Filling structure
    builder
        .SetTitle(var_set.title)
        .SetDate(var_set.date)
        .SetPriority(var_set.priority)
        .SetStatus(var_set.status)
        .SetId(var_set.id)
        .SetParent(*var_set.parent_id)
        .SetLabel(var_set.label)
        .SetFileName(var_set.file_name);

    builder.Reset();

    EXPECT_EQ(builder.GetResult(), VariableSet());
}
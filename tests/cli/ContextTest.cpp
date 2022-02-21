//
// Created by Illia Plaksa on 17.01.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/Context.h"

class ContextTest : ::testing::Test
{
};

TEST(ContextTest, shouldCreate)
{
    auto obj = Context{};

    EXPECT_TRUE(obj.GetStorage());
    EXPECT_FALSE(obj.GetError());
}

TEST(ContextTest, shouldSetError)
{
    auto obj = Context{};
    auto message = "Simple error message";
    obj.SetError(message);

    EXPECT_EQ(obj.GetError(), message);
}

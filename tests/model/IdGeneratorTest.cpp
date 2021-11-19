//
// Created by Illia Plaksa on 14.11.2021.
//
#include "gtest/gtest.h"
#include "../../src/model/IdGenerator.h"

class IdGeneratorTest : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(IdGeneratorTest, mustReturnNewId)
{
    auto gen = IdGenerator{};
    EXPECT_EQ(TaskId::Create(1), gen.GetNextId());
    EXPECT_NE(TaskId::Create(1), gen.GetNextId());
}
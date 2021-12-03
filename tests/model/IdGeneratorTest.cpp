//
// Created by Illia Plaksa on 14.11.2021.
//
#include "gtest/gtest.h"
#include "../../src/model/include/IdGenerator.h"

class IdGeneratorTest : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(IdGeneratorTest, mustReturnNewId)
{
    auto gen = IdGenerator{};

    auto first_id = gen.GetNextId();
    auto second_id = gen.GetNextId();
    EXPECT_NE(first_id, second_id);
}
//
// Created by Illia Plaksa on 14.11.2021.
//
#include "gtest/gtest.h"
#include "../../src/model/include/IdGenerator.h"
#include "util/TaskId/TaskIdComparators.h"

class IdGeneratorTest : public ::testing::Test
{};

TEST(IdGeneratorTest, mustReturnNewId)
{
    auto gen = IdGenerator{};

    auto first_id = gen.GetNextId();
    auto second_id = gen.GetNextId();
    EXPECT_NE(first_id, second_id);
}
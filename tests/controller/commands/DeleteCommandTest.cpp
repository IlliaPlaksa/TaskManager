//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../../src/controller/include/ConcreteCommands.h"
#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"
#include "./../../src/util/TaskIdCreators.h"
#include "./../../src/util/TaskIdComparers.h"

class DeleteCommandTest : ::testing::Test {};

TEST(DeleteCommandTest, shouldExecute)
{
    auto model = std::shared_ptr<ModelMock>{new ModelMock};
    auto context = std::make_shared<ContextDTOMock>();

    auto command = DeleteCommand{context};

    auto id = *CreateTaskId(0);

    EXPECT_CALL(*model, Delete(id))
        .Times(1)
        .WillOnce(testing::Return(Model::Response::CreateSuccess()));

    command.Execute(model);
}
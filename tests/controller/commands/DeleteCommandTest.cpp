//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "controller/include/ConcreteCommands.h"
#include "../mocks/ModelMock.h"
#include "../mocks/ContextDTOMock.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskId/TaskIdComparators.h"

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
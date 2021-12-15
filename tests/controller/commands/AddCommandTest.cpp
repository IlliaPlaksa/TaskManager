//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../../src/controller/include/ConcreteCommands.h"
#include "../mocks/ModelMock.h"
#include "../mocks/ViewMock.h"

class AddCommandTest : ::testing::Test {};

TEST(AddCommandTest, shouldExecuteCommonLogic)
{
    auto model = std::shared_ptr<ModelMock>{new ModelMock};
    auto view = std::shared_ptr<ViewMock>{new ViewMock};

    auto command = AddCommand{model};

    auto task = Task::Create("Title",
                             time(nullptr),
                             Task::Priority::kHigh);
    auto id = TaskId::Create(123);

    auto task_struct = TaskStruct{};
    task_struct
        .SetFromTask(task)
        .SetParent(id);

    EXPECT_CALL(*view, GetTaskStruct())
        .Times(1)
        .WillOnce(testing::Return(task_struct));

    EXPECT_CALL(*model, Add(task, id))
        .Times(1)
        .WillOnce(testing::Return(TaskId::CreateDefault()));

    command.Execute(view);
}
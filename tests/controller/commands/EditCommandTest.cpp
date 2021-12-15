//
// Created by Illia Plaksa on 14.12.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../../src/controller/include/ConcreteCommands.h"
#include "../mocks/ModelMock.h"
#include "../mocks/ViewMock.h"

class EditCommandTest : ::testing::Test {};

TEST(EditCommandTest, shouldExecuteCommonLogic)
{
    auto model = std::shared_ptr<ModelMock>{new ModelMock};
    auto view = std::shared_ptr<ViewMock>{new ViewMock};

    auto command = EditCommand{model};

    auto task = Task::Create("Title",
                             time(nullptr),
                             Task::Priority::kHigh);
    auto id = TaskId::Create(123);
    auto parent_id = TaskId::CreateDefault();

    auto task_struct = TaskStruct{};
    task_struct
        .SetFromTask(task)
        .SetId(id)
        .SetParent(parent_id);


    EXPECT_CALL(*view, GetTaskStruct())
        .Times(1)
        .WillOnce(testing::Return(task_struct));

    EXPECT_CALL(*model, Edit(id, task, parent_id))
    .Times(1);

    command.Execute(view);
}
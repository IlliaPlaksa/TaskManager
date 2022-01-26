//
// Created by Illia Plaksa on 28.01.2022.
//

#include "gtest/gtest.h"
#include "Service_mock.grpc.pb.h"
#include "controller/RemoteController.h"

#include "util/Task/TaskComparators.h"
#include "util/TaskDTO/TaskDTOComparators.h"
#include "util/TaskId/TaskIdComparators.h"

class RemoteControllerTest : public ::testing::Test
{
protected:
    std::unique_ptr<service::MockRequestHandlerStub> stub_;

    void SetUp() override
    {
        stub_ = std::make_unique<service::MockRequestHandlerStub>();
    }
};

using ::testing::_;

TEST_F(RemoteControllerTest, shouldCallAddMethod)
{
    Task task{};

    EXPECT_CALL(*stub_, Add(_, task, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};

    auto result = controller.Add(task);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallAddSubTaskMethod)
{
    Task task{};
    TaskId parent_id{};

    TaskDTO request{};
    request.mutable_task()->CopyFrom(task);
    request.mutable_parent_id()->CopyFrom(parent_id);

    EXPECT_CALL(*stub_, AddSubTask(_, request, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};

    auto result = controller.AddSubTask(task, parent_id);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallEditMethod)
{
    Task task{};
    TaskId task_id{};

    TaskDTO request{};
    request.mutable_task()->CopyFrom(task);
    request.mutable_id()->CopyFrom(task_id);

    EXPECT_CALL(*stub_, Edit(_, request, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};

    auto result = controller.Edit(task_id, task);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallEditSubTaskMethod)
{
    TaskId task_id{};
    Task task{};
    TaskId parent_id{};

    TaskDTO request{};
    request.mutable_id()->CopyFrom(task_id);
    request.mutable_task()->CopyFrom(task);
    request.mutable_parent_id()->CopyFrom(parent_id);

    EXPECT_CALL(*stub_, EditSubTask(_, request, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};

    auto result = controller.EditSubTask(task_id, task, parent_id);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallCompleteMethod)
{
    TaskId task_id{};

    EXPECT_CALL(*stub_, Complete(_, task_id, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};

    auto result = controller.Complete(task_id);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallDeleteMethod)
{
    TaskId task_id{};

    EXPECT_CALL(*stub_, Delete(_, task_id, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.Delete(task_id);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallShowMethod)
{
    EXPECT_CALL(*stub_, Show(_, _, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.Show();

    EXPECT_TRUE(result.empty());
}

TEST_F(RemoteControllerTest, shouldCallShowParentsMethod)
{
    EXPECT_CALL(*stub_, ShowParents(_, _, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.ShowParents();

    EXPECT_TRUE(result.empty());
}

TEST_F(RemoteControllerTest, shouldCallShowChildMethod)
{
    TaskId request{};

    EXPECT_CALL(*stub_, ShowChild(_, request, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.ShowChild(request);

    EXPECT_TRUE(result.empty());
}

TEST_F(RemoteControllerTest, shouldCallLoadMethod)
{
    std::vector<TaskDTO> tasks{};

    EXPECT_CALL(*stub_, Load(_, _, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.Load(tasks);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallLoadFromFileMethod)
{
    std::string file_name = "test_file.txt";

    EXPECT_CALL(*stub_, Load(_, _, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.LoadFromFile(file_name);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallSaveToFileMethod)
{
    std::string file_name = "test_file.txt";

    EXPECT_CALL(*stub_, Show(_, _, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.SaveToFile(file_name);

    EXPECT_FALSE(result.IsError());
}

TEST_F(RemoteControllerTest, shouldCallShowTasksWithLabelMethod)
{
    std::string label = "Example";

    EXPECT_CALL(*stub_, ShowTasksWithLabel(_, _, _))
        .WillOnce(::testing::Return(::grpc::Status::OK));

    RemoteController controller{std::move(stub_)};
    auto result = controller.ShowTasksWithLabel(label);

    EXPECT_TRUE(result.empty());
}
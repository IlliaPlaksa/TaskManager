//
// Created by Illia Plaksa on 27.01.2022.
//

#include "gtest/gtest.h"
#include "server/RequestHandlerImpl.h"
#include "mocks/ModelMock.h"

#include "util/Task/TaskComparators.h"
#include "util/TaskId/TaskIdComparators.h"
#include "util/TaskDTO/TaskDTOComparators.h"

class RequestHandlerImplTest : public ::testing::Test
{
protected:
    std::unique_ptr<ModelMock> model_;

    void SetUp() override
    {
        model_ = std::make_unique<ModelMock>();
    }
};

TEST_F(RequestHandlerImplTest, shouldCallAddMethod)
{
    ::grpc::ServerContext context{};
    Task task{};
    ::service::Response response{};

    EXPECT_CALL(*model_, Add(task))
        .WillOnce(::testing::Return(ModelResponse::Success()));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.Add(&context, &task, &response);

    EXPECT_EQ(response.status(), ::service::Response_Status_kSuccess);
}

TEST_F(RequestHandlerImplTest, shouldCallAddSubTaskMethod)
{
    ::grpc::ServerContext context{};

    Task task{};
    TaskId parent_id{};

    TaskDTO request{};

    request.set_allocated_task(
        std::make_unique<Task>(task).release()
    );
    request.set_allocated_parent_id(
        std::make_unique<TaskId>(parent_id).release()
    );

    ::service::Response response{};

    EXPECT_CALL(*model_, AddSubTask(task, parent_id))
        .WillOnce(::testing::Return(ModelResponse::Success()));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.AddSubTask(&context, &request, &response);

    EXPECT_EQ(response.status(), ::service::Response_Status_kSuccess);
}

TEST_F(RequestHandlerImplTest, shouldCallEditMethod)
{
    Task task{};
    TaskId task_id{};

    TaskDTO request{};
    request.set_allocated_task(
        std::make_unique<Task>(task).release()
    );
    request.set_allocated_id(
        std::make_unique<TaskId>(task_id).release()
    );

    ::grpc::ServerContext context{};
    ::service::Response response{};

    EXPECT_CALL(*model_, Edit(task_id, task))
        .WillOnce(::testing::Return(ModelResponse::Success()));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.Edit(&context, &request, &response);

    EXPECT_EQ(response.status(), ::service::Response_Status_kSuccess);
}

TEST_F(RequestHandlerImplTest, shouldCallEditSubTaskMethod)
{
    ::grpc::ServerContext context{};
    ::service::Response response{};

    TaskId task_id{};
    Task task{};
    TaskId parent_id{};

    TaskDTO request{};

    request.set_allocated_id(
        std::make_unique<TaskId>(task_id).release()
    );
    request.set_allocated_task(
        std::make_unique<Task>(task).release()
    );
    request.set_allocated_parent_id(
        std::make_unique<TaskId>(parent_id).release()
    );

    EXPECT_CALL(*model_, EditSubTask(task_id, task, parent_id))
        .WillOnce(::testing::Return(ModelResponse::Success()));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.EditSubTask(&context, &request, &response);

    EXPECT_EQ(response.status(), ::service::Response_Status_kSuccess);
}

TEST_F(RequestHandlerImplTest, shouldCallCompleteMethod)
{
    ::grpc::ServerContext context{};
    TaskId task_id{};
    ::service::Response response{};

    EXPECT_CALL(*model_, Complete(task_id))
        .WillOnce(::testing::Return(ModelResponse::Success()));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.Complete(&context, &task_id, &response);

    EXPECT_EQ(response.status(), ::service::Response_Status_kSuccess);
}

TEST_F(RequestHandlerImplTest, shouldCallDeleteMethod)
{
    ::grpc::ServerContext context{};
    TaskId task_id{};
    ::service::Response response{};

    EXPECT_CALL(*model_, Delete(task_id))
        .WillOnce(::testing::Return(ModelResponse::Success()));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.Delete(&context, &task_id, &response);

    EXPECT_EQ(response.status(), ::service::Response_Status_kSuccess);
}

TEST_F(RequestHandlerImplTest, shouldCallShowMethod)
{
    ::grpc::ServerContext context{};
    google::protobuf::Empty request{};
    ::service::TaskDTOEnvelope response{};

    auto model_response = std::vector<TaskDTO>{TaskDTO{}};

    EXPECT_CALL(*model_, Show())
        .WillOnce(::testing::Return(model_response));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.Show(&context, &request, &response);

    EXPECT_EQ(response.tasks().size(), model_response.size());
}

TEST_F(RequestHandlerImplTest, shouldCallShowParentsMethod)
{
    ::grpc::ServerContext context{};
    google::protobuf::Empty request{};
    ::service::TaskDTOEnvelope response{};

    auto model_response = std::vector<TaskDTO>{TaskDTO{}};

    EXPECT_CALL(*model_, ShowParents())
        .WillOnce(::testing::Return(model_response));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.ShowParents(&context, &request, &response);

    EXPECT_EQ(response.tasks().size(), model_response.size());
}

TEST_F(RequestHandlerImplTest, shouldCallShowChildMethod)
{
    ::grpc::ServerContext context{};
    TaskId request{};
    ::service::TaskDTOEnvelope response{};

    auto model_response = std::vector<TaskDTO>{TaskDTO{}};

    EXPECT_CALL(*model_, ShowChild(request))
        .WillOnce(::testing::Return(model_response));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.ShowChild(&context, &request, &response);

    EXPECT_EQ(response.tasks().size(), model_response.size());
}

TEST_F(RequestHandlerImplTest, shouldCallLoadMethod)
{
    ::grpc::ServerContext context{};
    ::service::TaskDTOEnvelope request{};
    ::service::Response response{};

    std::vector<TaskDTO> tasks{};

    EXPECT_CALL(*model_, Load(tasks))
        .WillOnce(::testing::Return(ModelResponse::Success()));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.Load(&context, &request, &response);

    EXPECT_EQ(response.status(), ::service::Response_Status_kSuccess);
}

TEST_F(RequestHandlerImplTest, shouldCallShowTasksWithLabelMethod)
{
    ::grpc::ServerContext context{};
    ::service::TaskDTOEnvelope response{};

    std::string label = "Example";
    service::Label request{};
    request.set_allocated_value(new std::string(label));

    auto model_response = std::vector<TaskDTO>{TaskDTO{}};

    EXPECT_CALL(*model_, ShowTasksWithLabel(request.value()))
        .WillOnce(::testing::Return(model_response));

    RequestHandlerImpl request_handler{std::move(model_)};

    request_handler.ShowTasksWithLabel(&context, &request, &response);

    EXPECT_EQ(response.tasks().size(), model_response.size());
}
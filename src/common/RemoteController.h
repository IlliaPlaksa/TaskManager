//
// Created by Illia Plaksa on 26.01.2022.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_REMOTECONTROLLER_H_
#define TASKMANAGER_SRC_CONTROLLER_REMOTECONTROLLER_H_

#include "common/include/ModelController.h"
#include "Service.grpc.pb.h"
#include "persistence/include/FilePersister.h"

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

class RemoteController : public ModelController
{
public:
    RemoteController(const std::shared_ptr<grpc::ChannelInterface>& channel);
public:
    ModelResponse Add(const Task& task) override;
    ModelResponse AddSubTask(const Task& task, const TaskId& parent_id) override;
    ModelResponse Edit(const TaskId& task_id, const Task& task) override;
    ModelResponse EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id) override;
    ModelResponse Complete(const TaskId& task_id) override;
    ModelResponse Delete(const TaskId& task_id) override;

public:
    std::vector<TaskDTO> Show() override;
    std::vector<TaskDTO> ShowParents() override;
    std::vector<TaskDTO> ShowChild(const TaskId& parent_id) override;

public:
    ModelResponse Load(const std::vector<TaskDTO>& tasks) override;
    ModelResponse LoadFromFile(const std::string& file_name) override;
    ModelResponse SaveToFile(const std::string& file_name) override;

private:
    std::unique_ptr<service::RequestHandler::Stub> stub_;
};

#endif //TASKMANAGER_SRC_CONTROLLER_REMOTECONTROLLER_H_

//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKMANAGER_H_
#define TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

#include <map>
#include <vector>
#include "common/include/Model.h"
#include "TaskNode.h"
#include "IdGenerator.h"
#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskDTO.pb.h"

class TaskManager : public Model
{
public:
    Response Add(const Task& task) override;
    Response AddSubTask(const Task& task, const TaskId& parent_id) override;
    Response Edit(const TaskId& id,
                  const Task& task) override;
    Response EditSubTask(const TaskId& id,
                         const Task& task,
                         const TaskId& parent_id) override;
    Response Delete(const TaskId& id) override;
    Response Complete(const TaskId& id) override;

    std::vector<TaskDTO> Show() override;
    std::vector<TaskDTO> ShowParents() override;
    std::vector<TaskDTO> ShowChild(const TaskId& parent_id) override;

    Response Load(const std::vector<TaskDTO>& tasks) override;

public:
    explicit TaskManager(std::unique_ptr<IdGenerator> generator);

private:
    std::optional<TaskDTO> ConstructTaskDTO(const TaskId& id, const TaskNode& task);
    std::vector<std::map<TaskId, TaskNode>::iterator> FindSubTasks(const TaskId& parent_id);


private:
    std::map<TaskId, TaskNode> tasks_;
    std::unique_ptr<IdGenerator> gen_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

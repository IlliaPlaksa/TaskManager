//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKMANAGER_H_
#define TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

#include <map>
#include <vector>
#include "../../controller/include/IModel.h"
#include "FamilyTask.h"
#include "Task.h"
#include "TaskId.h"
#include "TaskToSerialize.h"
#include "IdGenerator.h"

class TaskManager : public IModel
{
public:
    Response Add(const Task &task) override;
    Response AddSubTask(const Task &task, const TaskId &parent_id) override;
    Response Edit(const TaskId &id,
                  const Task &task,
                  const TaskId &parent_id) override;
    Response Delete(const TaskId &id) override;
    Response Complete(const TaskId &id) override;

    std::vector<TaskToSerialize> Show() override;
    std::vector<TaskToSerialize> ShowParents() override;
    std::vector<TaskToSerialize> ShowChild(const TaskId &parent_id) override;

public:
    explicit TaskManager(std::unique_ptr<IdGenerator> generator);

private:
    std::optional<TaskToSerialize> ConstructTaskToSerialize(const TaskId &id, const FamilyTask &task);

private:
    std::map<TaskId, FamilyTask> tasks_;
    std::unique_ptr<IdGenerator> gen_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

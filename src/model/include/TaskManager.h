//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKMANAGER_H_
#define TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

#include <map>
#include <vector>
#include "../../controller/include/IModel.h"
#include "FamilyTask.h"
#include "TaskId.h"
#include "IdGenerator.h"

class TaskManager : public IModel
{
public:
    TaskId Add(const Task &task,
               const TaskId &parent_id) override;
    void Edit(const TaskId &id,
              const Task &task,
              const TaskId &parent_id) override;
    void Delete(const TaskId &id) override;
    void Complete(const TaskId &id) override;

    std::vector<std::pair<TaskId, Task>> Show() override;
    std::vector<std::pair<TaskId, Task>> ShowParents() override;
    std::vector<std::pair<TaskId, Task>> ShowChild(TaskId parent_id) override;

public:
    explicit TaskManager(std::unique_ptr<IdGenerator> generator);

private:
    std::map<TaskId, FamilyTask> tasks_;
    std::unique_ptr<IdGenerator> gen_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

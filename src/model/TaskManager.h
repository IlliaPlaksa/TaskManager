//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKMANAGER_H_
#define TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

#include <map>
#include <vector>
#include "FamilyTask.h"
#include "TaskId.h"
#include "IdGenerator.h"

class TaskManager
{
public:
    TaskId Add(const FamilyTask &task);
    void Edit(TaskId id, const FamilyTask &task);
    void Delete(TaskId id);
    void Complete(TaskId id);

    std::vector<std::pair<TaskId, FamilyTask>> Show();
    // TODO add new Show methods for "Family" relation
    std::vector<std::pair<TaskId, FamilyTask>> ShowParents();
    std::vector<std::pair<TaskId, FamilyTask>> ShowChild(TaskId parent_id);

public:
    explicit TaskManager(std::unique_ptr<IdGenerator> generator);

private:
    std::map<TaskId, FamilyTask> tasks_;
    std::unique_ptr<IdGenerator> gen_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKMANAGER_H_

//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_IMODEL_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_IMODEL_H_

#include <vector>
#include <optional>

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskToSerialize.pb.h"

class IModel
{
public:
    class Response;

public:
    virtual Response Add(const Task &task) = 0;
    virtual Response AddSubTask(const Task &task, const TaskId &parent_id) = 0;
    virtual Response Edit(const TaskId &task_id, const Task &task, const TaskId &parent_id) = 0;
    virtual Response Complete(const TaskId &task_id) = 0;
    virtual Response Delete(const TaskId &task_id) = 0;

public:
    virtual std::vector<TaskToSerialize> Show() = 0;
    virtual std::vector<TaskToSerialize> ShowParents() = 0;
    virtual std::vector<TaskToSerialize> ShowChild(const TaskId &parent_id) = 0;

public:
    void LoadFromFile(const std::string &file_name);
    void SaveToFile(const std::string &file_name);
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_IMODEL_H_

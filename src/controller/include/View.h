//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_

#include <optional>
#include "../../model/include/TaskToSerialize.h"
#include "cli/include/TaskStorage.h"

class View :public std::enable_shared_from_this<View>
{
public:
    virtual void Run() = 0;
public:
    virtual void LoadTasks(const TaskStorage &storage) = 0;
public:
    virtual std::optional<TaskToSerialize> GetTaskStruct() const = 0;
public:
    virtual std::shared_ptr<View> shared() = 0;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_

//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_IVIEW_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_IVIEW_H_

#include <optional>
#include "../../model/include/TaskToSerialize.h"
#include "cli/include/TaskStorage.h"

class IView :public std::enable_shared_from_this<IView>
{
public:
    virtual void Run() = 0;
public:
    virtual void LoadTasks(const TaskStorage &storage) = 0;
public:
    virtual std::optional<TaskToSerialize> GetTaskStruct() const = 0;
public:
    virtual std::shared_ptr<IView> shared() = 0;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_IVIEW_H_

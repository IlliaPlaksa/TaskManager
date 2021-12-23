//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_

#include <optional>
#include "TaskDTO.pb.h"
#include "cli/include/TaskStorage.h"

class View : public std::enable_shared_from_this<View>
{
public:
    virtual void Run() = 0;

public:

public:
    virtual ~View() = 0;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_VIEW_H_

//
// Created by Illia Plaksa on 14.01.2022.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_PERSISTER_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_PERSISTER_H_

#include "TaskDTO.pb.h"

/**
 * @brief \b Interface of task persister
 * @details Provides API of \b Task persister that saves and loads set of \b TaskDTO structures to some source
 * @author Plaksa Illia
 */
class TaskPersister
{
public:
    /**
     * @param tasks \b std::vector of \b TaskDTO that will be saved to source
     * @return \b bool \b true in case of successful saving and \b false otherwise
     */
    virtual bool Save(const std::vector<TaskDTO>& tasks) = 0;

    /**
     * @return \b std::optional from \b std::vector of \b TaskDTO that was loaded from source in case of failed load returns \b std::nullopt
     */
    virtual std::optional<std::vector<TaskDTO>> Load() = 0;
public:
    virtual ~TaskPersister() = default;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_PERSISTER_H_

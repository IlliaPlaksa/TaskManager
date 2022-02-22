//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_
#define TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_

#include <vector>
#include <optional>

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskDTO.pb.h"

#include "ModelResponse.h"

/**
 * @brief \b Core interface of \b TaskManager
 * @details Provides API of \b TaskManager
 * @author Plaksa Illia
 */
class Model
{
public:
    /**
     * @param task Protobuf Task message to add
     * @return \b ModelResponse
     */
    virtual ModelResponse Add(const Task& task) = 0;

    /**
     * @param task Protobuf \b Task message to add
     * @param parent_id Protobuf \b TaskId specifies ID of parent task
     * @return \b ModelResponse
     */
    virtual ModelResponse AddSubTask(const Task& task, const TaskId& parent_id) = 0;

    /**
     * @param task_id Protobuf \b TaskId specifies ID of task to edit
     * @param task Protobuf \b Task specifies new state of chosen task
     * @return /b ModelResponse
     */
    virtual ModelResponse Edit(const TaskId& task_id, const Task& task) = 0;

    /**
     * @param task_id Protobuf \b TaskId specifies ID of task to edit
     * @param task Protobuf \b Task specifies new state of chosen task
     * @param parent_id Protobuf \b TaskId specifies ID of parent task
     * @return /b ModelResponse
     */
    virtual ModelResponse EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id) = 0;

    /**
     * @param task_id Protobuf \b TaskId specifies ID of task to complete
     * @return \b ModelResponse
     */
    virtual ModelResponse Complete(const TaskId& task_id) = 0;

    /**
     * @param task_id Protobuf \b TaskId specifies ID of task to delete
     * @return \b ModelResponse
     */
    virtual ModelResponse Delete(const TaskId& task_id) = 0;

public:
    /**
     * @return \b std::vector of \b TaskDTO that is a copy of stored tasks with hierarchical structure
     */
    virtual std::vector<TaskDTO> Show() = 0;

    /**
     * @return \b std::vector of \b TaskDTO that is a copy of stored parent tasks
     */
    virtual std::vector<TaskDTO> ShowParents() = 0;

    /**
     * @param parent_id \b TaskId specifies ID of task which child is needed to return
     * @return \b std::vector of \b TaskDTO that is copy of child Tasks of specifies task
     */
    virtual std::vector<TaskDTO> ShowChild(const TaskId& parent_id) = 0;

    /**
     * @param label \b std::string specifies label of tasks to show
     * @return \b std::vector of \b TaskDTO that is copy of task with specified label with hierarchical structure
     */
    virtual std::vector<TaskDTO> ShowTasksWithLabel(const std::string& label) = 0;

public:
    /**
     * @param tasks \b std::vector of \b TaskDTO which specifies tasks to reset storage from
     * @return \b ModelResponse
     * @note In case of wrong input returns \b ModelResponse with error message
     * and saves the same state that was before method's call
     */
    virtual ModelResponse Load(const std::vector<TaskDTO>& tasks) = 0;

public:
    virtual ~Model() = default;
};

#endif //TASKMANAGER_SRC_CONTROLLER_INCLUDE_MODEL_H_

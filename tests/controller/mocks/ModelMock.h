//
// Created by Illia Plaksa on 14.12.2021.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_MODELMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_MODELMOCK_H_

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_MODELMOCK_H_

#include "gmock/gmock.h"
#include "../../../src/controller/include/IModel.h"

class ModelMock : public IModel
{
    using TaskVect = std::vector<std::pair<TaskId, Task>>;
public:
    MOCK_METHOD(TaskId, Add,
                (const Task &task, const TaskId &parent_id), (override));
    MOCK_METHOD(void, Edit,
                (const TaskId &task_id, const Task &task, const TaskId &parent_id), (override));
    MOCK_METHOD(void, Complete,
                (const TaskId &task_id), (override));
    MOCK_METHOD(void, Delete,
                (const TaskId &task_id), (override));

    MOCK_METHOD(TaskVect, Show, (), (override));
    MOCK_METHOD(TaskVect, ShowParents, (), (override));
    MOCK_METHOD(TaskVect, ShowChild, (TaskId parent_id), (override));
};

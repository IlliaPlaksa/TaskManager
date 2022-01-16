//
// Created by Illia Plaksa on 14.12.2021.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_MODELMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_MODELMOCK_H_

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_MODELMOCK_H_

#include "gmock/gmock.h"
#include "common/include/Model.h"

class ModelMock : public Model
{
public:
    MOCK_METHOD(Response, Add, (const Task &task), (override));
    MOCK_METHOD(Response, AddSubTask, (const Task &task, const TaskId &parent_id), (override));
    MOCK_METHOD(Response, Edit, (const TaskId &task_id, const Task &task), (override));
    MOCK_METHOD(Response, EditSubTask, (const TaskId &task_id, const Task &task, const TaskId &parent_id), (override));
    MOCK_METHOD(Response, Complete, (const TaskId &task_id), (override));
    MOCK_METHOD(Response, Delete, (const TaskId &task_id), (override));

    MOCK_METHOD(std::vector<TaskDTO>, Show, (), (override));
    MOCK_METHOD(std::vector<TaskDTO>, ShowParents, (), (override));
    MOCK_METHOD(std::vector<TaskDTO>, ShowChild, (const TaskId& task_id), (override));

    MOCK_METHOD(Response, Load, (const std::vector<TaskDTO>& tasks), (override));
};

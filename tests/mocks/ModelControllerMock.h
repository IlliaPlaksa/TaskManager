//
// Created by Illia Plaksa on 27.01.2022.
//

#ifndef TASKMANAGER_TESTS_MOCKS_MODELCONTROLLERMOCK_H_
#define TASKMANAGER_TESTS_MOCKS_MODELCONTROLLERMOCK_H_

#include "gmock/gmock.h"
#include "common/include/ModelController.h"

class ModelControllerMock : public ModelController
{
public:
    MOCK_METHOD(ModelResponse, Add, (const Task &task), (override));
    MOCK_METHOD(ModelResponse, AddSubTask, (const Task &task, const TaskId &parent_id), (override));
    MOCK_METHOD(ModelResponse, Edit, (const TaskId &task_id, const Task &task), (override));
    MOCK_METHOD(ModelResponse,EditSubTask,(const TaskId &task_id, const Task &task, const TaskId &parent_id),(override));
    MOCK_METHOD(ModelResponse, Complete, (const TaskId &task_id), (override));
    MOCK_METHOD(ModelResponse, Delete, (const TaskId &task_id), (override));

    MOCK_METHOD(std::vector<TaskDTO>, Show, (), (override));
    MOCK_METHOD(std::vector<TaskDTO>, ShowParents, (), (override));
    MOCK_METHOD(std::vector<TaskDTO>, ShowChild, (const TaskId& task_id), (override));

    MOCK_METHOD(ModelResponse, Load, (const std::vector<TaskDTO>& tasks), (override));

    MOCK_METHOD(ModelResponse, LoadFromFile, (const std::string& file_name), (override));
    MOCK_METHOD(ModelResponse, SaveToFile, (const std::string& file_name), (override));

};

#endif //TASKMANAGER_TESTS_MOCKS_MODELCONTROLLERMOCK_H_

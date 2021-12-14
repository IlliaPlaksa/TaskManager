//
// Created by Illia Plaksa on 14.12.2021.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_VIEWMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_VIEWMOCK_H_

#include "gmock/gmock.h"
#include "../../../src/controller/include/IView.h"

class ViewMock : public IView
{
public:
    MOCK_METHOD(void, Run, (), (override));
    MOCK_METHOD(void, LoadTasks, (const TaskStorage &storage), (override));
    MOCK_METHOD(std::optional<TaskStruct>, GetTaskStruct, (), (const, override));
    MOCK_METHOD(std::shared_ptr<IView>, shared, (), (override));
};

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_VIEWMOCK_H_



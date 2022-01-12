//
// Created by Illia Plaksa on 14.12.2021.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_VIEWMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_VIEWMOCK_H_

#include "gmock/gmock.h"
#include "../../../src/controller/include/View.h"

class ViewMock : public View
{
public:
    MOCK_METHOD(void, Run, (), (override));
};

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCK_INCLUDE_VIEWMOCK_H_



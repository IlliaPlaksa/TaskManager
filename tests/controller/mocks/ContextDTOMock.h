//
// Created by Illia Plaksa on 12.01.2022.
//

#ifndef TASKMANAGER_TESTS_CONTROLLER_MOCKS_CONTEXTDTOMOCK_H_
#define TASKMANAGER_TESTS_CONTROLLER_MOCKS_CONTEXTDTOMOCK_H_

#include "gmock/gmock.h"
#include "../../../src/controller/include/ContextDTO.h"

class ContextDTOMock : public ContextDTO
{
public:
    MOCK_METHOD(void, Clear, (), (override));
    MOCK_METHOD(VariableSet, variable_set, (), (const, override));
    MOCK_METHOD(std::vector<TaskDTO>, tasks, (), (const, override));
};

#endif //TASKMANAGER_TESTS_CONTROLLER_MOCKS_CONTEXTDTOMOCK_H_
